////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  QCamxHAL3TestPreviewOnly.h
/// @brief Preview only mode
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "QCamxHAL3TestVideoOnly.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "QCamxHAL3Test"

typedef enum {
    PREVIEW_IDX   =  0,
} StreamIdx;

/************************************************************************
* name : QCamxHAL3TestPreviewOnly
* function: construct object.
************************************************************************/
QCamxHAL3TestVideoOnly::QCamxHAL3TestVideoOnly(camera_module_t* module, QCamxHAL3TestConfig* config)
{
    init(module, config);

    mVideoMode = VIDEO_ONLY_MODE_NORMAL;
    mIsStoped = true;
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder = new QCamxTestVideoEncoder(mConfig);
    #endif
}

/************************************************************************
* name : ~QCamxHAL3TestPreviewOnly
* function: destory object.
************************************************************************/
QCamxHAL3TestVideoOnly::~QCamxHAL3TestVideoOnly()
{
    deinit();
}

/************************************************************************
* name : CapturePostProcess
* function: handle capture result.
************************************************************************/
void QCamxHAL3TestVideoOnly::CapturePostProcess(DeviceCallback* cb, camera3_capture_result *result)
{
    const camera3_stream_buffer_t* buffers = NULL;
    QCamxHAL3TestVideoOnly* testpre = (QCamxHAL3TestVideoOnly*)cb;
    QCamxHAL3TestDevice* device = testpre->mDevice;
    buffers = result->output_buffers;

    for (uint32_t i = 0;i < result->num_output_buffers ;i++) {
        int index = device->findStream(buffers[i].stream);
        CameraStream* stream = device->mCameraStreams[index];
        BufferInfo* info = stream->bufferManager->getBufferInfo(buffers[i].buffer);
        if (stream->streamType == CAMERA3_TEMPLATE_VIDEO_RECORD) {
            if (mCbs && mCbs->video_cb) {
                mCbs->video_cb(info, result->frame_number);
            }
            if (testpre->mDumpVideoNum > 0 &&
                (mDumpInterval == 0 ||
                (mDumpInterval > 0 && result->frame_number % mDumpInterval == 0))) {
                QCamxHAL3TestCase::DumpFrame(info, result->frame_number, VIDEO_TYPE);
                if (mDumpInterval == 0) {
                    testpre->mDumpPreviewNum--;
                }
            }
            if (mIsStoped) {
                stream->bufferManager->ReturnBuffer(buffers[i].buffer);
            } else {
                EnqueueFrameBuffer(stream,buffers[i].buffer);
            }
            if (mConfig->mShowFps) {
                showFPS(VIDEO_TYPE);
            }
        }
    }

    return ;
}

/************************************************************************
* name : selectOpMode
* function: choose suitable operate mode.
************************************************************************/
void QCamxHAL3TestVideoOnly::selectOpMode(uint32_t *operation_mode,int width,int height,
    int fps)
{
    uint32_t tags = 0;
    const int32_t *sensorModeTable = NULL;
    int res = 0;

    QCAMX_INFO(" video only: operation mode %d, fps: %d",operation_mode, fps);
    sp<VendorTagDescriptor> vTags =
        android::VendorTagDescriptor::getGlobalVendorTagDescriptor();
    camera_metadata_ro_entry entry;
    CameraMetadata::getTagFromName("org.quic.camera2.sensormode.info.SensorModeTable",
        vTags.get(), &tags);

    res = find_camera_metadata_ro_entry(mDevice->mCharacteristics, tags, &entry);
    if ((res == 0) && (entry.count > 0)) {
        sensorModeTable = entry.data.i32;
    }

    int modeCount = sensorModeTable[0];
    int modeSize = sensorModeTable[1];
    int sensorMode = -1;
    int s_width,s_height,s_fps,matched_fps;

    matched_fps = MAX_SENSOR_FPS;

    for (int i = 0; i < modeCount; i++) {
        s_width  =  sensorModeTable[2 + i*modeSize];
        s_height =  sensorModeTable[3 + i*modeSize];
        s_fps    =  sensorModeTable[4 + i*modeSize];

        if ((s_width >= width) &&
            (s_height >= height) &&
            (s_fps >= fps) &&
            (s_fps <= matched_fps)) {
            matched_fps = s_fps;
            sensorMode = i;
        }
    }

    if (sensorMode > 0) {
        // use StreamConfigModeSensorMode in camx
        *operation_mode = (*operation_mode) | ((sensorMode + 1) << 16) | (0x1 << 24);
        QCAMX_INFO(" operation mode %x, sensorMode: %d",operation_mode, sensorMode);
    }
}

/************************************************************************
* name : initPreviewStream
* function: do prepare for preview stream.
************************************************************************/
int QCamxHAL3TestVideoOnly::initVideoOnlyStream()
{
    int res = 0;
    camera3_stream_t videoStream;
    std::vector<camera3_stream_t*> streams;
    streams.resize(0);

    uint32_t operation_mode = CAMERA3_STREAM_CONFIGURATION_NORMAL_MODE;
    if (mConfig->mFpsRange[1] > 30 && mConfig->mFpsRange[1] <= 60) {
        // for HFR case such as 4K@60 and 1080p@60
        mVideoMode = VIDEO_ONLY_MODE_HFR60;
    } else if (mConfig->mFpsRange[1] > 60 && mConfig->mFpsRange[1] <= 90) {
        // for HFR case such as 1080p@90
        operation_mode = CAMERA3_STREAM_CONFIGURATION_CONSTRAINED_HIGH_SPEED_MODE;
        mVideoMode = VIDEO_ONLY_MODE_HFR90;
    } else if (mConfig->mFpsRange[1] > 90 && mConfig->mFpsRange[1] <= 120) {
        // for HFR case such as 1080p@120
        operation_mode = CAMERA3_STREAM_CONFIGURATION_CONSTRAINED_HIGH_SPEED_MODE;
        mVideoMode = VIDEO_ONLY_MODE_HFR120;
    }else if (mConfig->mFpsRange[1] > 120 && mConfig->mFpsRange[1] <= 240) {
        // for HFR case such as 1080p@240
        operation_mode = CAMERA3_STREAM_CONFIGURATION_CONSTRAINED_HIGH_SPEED_MODE;
        mVideoMode = VIDEO_ONLY_MODE_HFR240;
    }else if (mConfig->mFpsRange[1] > 240 && mConfig->mFpsRange[1] <= 480) {
        // for HFR case such as 720p@480
        operation_mode = CAMERA3_STREAM_CONFIGURATION_CONSTRAINED_HIGH_SPEED_MODE;
        mVideoMode = VIDEO_ONLY_MODE_HFR480;
    }

    //init stream configure
    bool supportsPartialResults;
    uint32_t partialResultCount;

    /*add video stream*/
    std::vector<AvailableStream> outputVideoStreams;
    AvailableStream videoThreshold = {mConfig->mVideoStream.width, mConfig->mVideoStream.height,
        mConfig->mVideoStream.format};
    //AvailableStream videoThreshold = {1920, 1080, HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED};
    if (res == 0) {
        camera_metadata_ro_entry entry;
        res = find_camera_metadata_ro_entry(mDevice->mCharacteristics,
            ANDROID_REQUEST_PARTIAL_RESULT_COUNT, &entry);
        if ((0 == res) && (entry.count > 0)) {
            partialResultCount = entry.data.i32[0];
            supportsPartialResults = (partialResultCount > 1);
        }
        res = mDevice->GetValidOutputStreams(outputVideoStreams, &videoThreshold);
    }
    if (res < 0 || outputVideoStreams.size() == 0) {
        QCAMX_ERR("Failed to find output stream for video: w: %d, h: %d, fmt: %d",
            mConfig->mVideoStream.width, mConfig->mVideoStream.height,
            mConfig->mVideoStream.format);
        return -1;
    }

    videoStream.stream_type = CAMERA3_STREAM_OUTPUT;//OUTPUT
    videoStream.width = outputVideoStreams[0].width;
    videoStream.height = outputVideoStreams[0].height;
    videoStream.format = outputVideoStreams[0].format;
    videoStream.data_space = HAL_DATASPACE_BT709;
    videoStream.usage = GRALLOC_USAGE_PRIVATE_0 | GRALLOC_USAGE_HW_VIDEO_ENCODER;
    videoStream.rotation = 0;
    // Fields to be filled by HAL (max_buffers, priv) are initialized to 0
    videoStream.max_buffers = 0;
    videoStream.priv = 0;
    streams.push_back(&videoStream);

    mDevice->setSyncBufferMode(SYNC_BUFFER_EXTERNAL);
    mDevice->setFpsRange(mConfig->mFpsRange[0], mConfig->mFpsRange[1]);
    if (mVideoMode >= VIDEO_ONLY_MODE_HFR60) {
        // for HFR case
        int stream_size = 0;
        int stream_index = 0;
        for (int i = 0;i < (int)streams.size();i++) {
            if ((streams[i]->width * streams[i]->height) > stream_size) {
                stream_size = streams[i]->width * streams[i]->height;
                stream_index = i;
            }
        }
        selectOpMode(&operation_mode,streams[stream_index]->width,
            streams[stream_index]->height,mConfig->mFpsRange[1]);
    }

    mDevice->configureStreams(streams,operation_mode);
    if (mMetadataExt) {
        mDevice->setCurrentMeta(mMetadataExt);
        mDevice->constructDefaultRequestSettings(0/*video only case*/, CAMERA3_TEMPLATE_VIDEO_RECORD);
    } else {
        mDevice->constructDefaultRequestSettings(0/*video only case*/, CAMERA3_TEMPLATE_VIDEO_RECORD, true);
    }

    android::CameraMetadata* metaUpdate = getCurrentMeta();
    sp<VendorTagDescriptor> vTags =
        android::VendorTagDescriptor::getGlobalVendorTagDescriptor();

    uint8_t antibanding = ANDROID_CONTROL_AE_ANTIBANDING_MODE_AUTO;
    metaUpdate->update(ANDROID_CONTROL_AE_ANTIBANDING_MODE,&(antibanding),sizeof(antibanding));

    uint8_t afmode = ANDROID_CONTROL_AF_MODE_CONTINUOUS_VIDEO;
    metaUpdate->update(ANDROID_CONTROL_AF_MODE, &(afmode), 1);
    uint8_t reqFaceDetectMode =  (uint8_t)ANDROID_STATISTICS_FACE_DETECT_MODE_OFF;
    metaUpdate->update(ANDROID_STATISTICS_FACE_DETECT_MODE,
            &reqFaceDetectMode, 1);

    if (mVideoMode <= VIDEO_ONLY_MODE_HFR60) {
        uint8_t jpegquality = JPEG_QUALITY_DEFAULT;
        metaUpdate->update(ANDROID_JPEG_QUALITY,&(jpegquality),sizeof(jpegquality));
    }

    if (mVideoMode != VIDEO_ONLY_MODE_NORMAL) {
        uint8_t videohdr = 0;
        uint8_t PCREnable = 0;
        uint8_t EISEnable = 0;
        uint32_t tag;
        uint8_t reqVstabMode = ANDROID_CONTROL_VIDEO_STABILIZATION_MODE_OFF;
        metaUpdate->update(ANDROID_CONTROL_VIDEO_STABILIZATION_MODE, &reqVstabMode, 1);

        uint8_t nr = ANDROID_NOISE_REDUCTION_MODE_FAST;
        metaUpdate->update(ANDROID_NOISE_REDUCTION_MODE, &(nr), 1);

        uint8_t antibanding = ANDROID_CONTROL_AE_ANTIBANDING_MODE_50HZ;
        metaUpdate->update(ANDROID_CONTROL_AE_ANTIBANDING_MODE,&antibanding,1);

        CameraMetadata::getTagFromName("org.quic.camera2.streamconfigs.HDRVideoMode",
            vTags.get(), &tag);
        metaUpdate->update(tag, &(videohdr), 1);

        CameraMetadata::getTagFromName("org.quic.camera.EarlyPCRenable.EarlyPCRenable",
            vTags.get(), &tag);
        metaUpdate->update(tag, &(PCREnable), 1);

        CameraMetadata::getTagFromName("org.quic.camera.eis3enable.EISV3Enable",
            vTags.get(), &tag);
        metaUpdate->update(tag, &(EISEnable), 1);
    }

    updataMetaDatas(metaUpdate);
    return res;
}

int QCamxHAL3TestVideoOnly::PreinitStreams()
{
    int res = 0;
    camera3_stream_t videoStream;
    std::vector<camera3_stream_t*> streams;
    int stream_num = 1;

    QCAMX_INFO("single video stream %dx%d %d\n",
        mConfig->mVideoStream.width,
        mConfig->mVideoStream.height,
        mConfig->mVideoStream.format);

    videoStream.stream_type = CAMERA3_STREAM_OUTPUT;
    videoStream.width = mConfig->mVideoStream.width;
    videoStream.height = mConfig->mVideoStream.height;
    videoStream.format = mConfig->mVideoStream.format;
    videoStream.data_space = HAL_DATASPACE_BT709;
    videoStream.usage = GRALLOC_USAGE_PRIVATE_0 | GRALLOC_USAGE_HW_VIDEO_ENCODER;
    videoStream.rotation = 0;
    videoStream.max_buffers = HFR_VIDEO_STREAM_BUFFER_MAX;
    videoStream.priv = 0;

    streams.resize(stream_num);
    streams[0] = &videoStream;

    mDevice->PreAllocateStreams(streams);

    return res;
}

/************************************************************************
* name : run
* function: interface for create snapshot thread.
************************************************************************/
void QCamxHAL3TestVideoOnly::run()
{
    //open camera
    mDevice->setCallBack(this);
    initVideoOnlyStream();

    if (mVideoMode <= VIDEO_ONLY_MODE_HFR60) {
        mDevice->mLivingRequestExtAppend = LIVING_REQUEST_APPEND;
    } else {
        mDevice->mLivingRequestExtAppend = HFR_LIVING_REQUEST_APPEND;
    }
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder->run();
    #endif
    mIsStoped = false;

    CameraThreadData* resultThreadVideo = new CameraThreadData();
    CameraThreadData* requestThreadVideo = new CameraThreadData();
    requestThreadVideo->requestNumber[0] = REQUEST_NUMBER_UMLIMIT;
    mDevice->processCaptureRequestOn(requestThreadVideo,resultThreadVideo);
}

/************************************************************************
* name : EnqueueFrameBuffer
* function: enqueue a frame to video encoder
************************************************************************/
void QCamxHAL3TestVideoOnly::EnqueueFrameBuffer(CameraStream *stream,buffer_handle_t *buf_handle) {
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder->EnqueueFrameBuffer(stream,buf_handle);
    #else
    stream->bufferManager->ReturnBuffer(buf_handle);
    #endif
}

/************************************************************************
* name : stop
* function: interface for stop snapshot thread.
************************************************************************/
void QCamxHAL3TestVideoOnly::stop()
{
    mDevice->stopStreams();
}
