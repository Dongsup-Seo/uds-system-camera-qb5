////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  QCamxHAL3TestConfig.cpp
/// @brief for QCamxHAL3TestConfig handles
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "QCamxHAL3TestConfig.h"
#include <unistd.h>
#include <string.h>
#include <vector>
#include <log/log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "QCamxHAL3Test"
/************************************************************************
* name : QCamxHAL3TestConfig
* function: construct object.
************************************************************************/
QCamxHAL3TestConfig::QCamxHAL3TestConfig()
{
    mDump = new QCamxHAL3TestLog("/data/misc/camera/test1.log");
    memset(&mMetaDump,       0, sizeof(meta_dump_t));
    memset(&mMetaStat,       0, sizeof(meta_stat_t));
    memset(&mPreviewStream,  0, sizeof(stream_info_t));
    memset(&mSnapshotStream, 0, sizeof(stream_info_t));
    memset(&mVideoStream,    0, sizeof(stream_info_t));
    memset(&mVideoRateConfig, 0, sizeof(video_bitrate_config_t));
    mVideoRateConfig.isBitRateConstant = false;
    mTestMode = -1;
    mIsH265 = 0;
    mCameraId = -1;
    // show FPS by default
    mShowFps = 1;
    // In ZSL by default
    mZslEnabled = true;
    mFpsRange[0] = 1;
    mFpsRange[1] = 30;
    mRangeMode   = -1;
    mImageType   = -1;
    mMetaDump.temperature = 1;
}

/************************************************************************
* name : ~QCamxHAL3TestConfig
* function: destory object.
************************************************************************/
QCamxHAL3TestConfig::~QCamxHAL3TestConfig()
{
    delete mDump;
    mDump = NULL;
}

/************************************************************************
* name : parseCommandlineMetaUpdate
* function: get update meta info from cmd.
************************************************************************/
int QCamxHAL3TestConfig::parseCommandlineMetaUpdate(char* order,android::CameraMetadata* metaUpdate)
{
    enum {
        MANUAL_EXPOSURE = 0,
        MANUAL_ISO,
        ANTBANDING,
        MANUAL_SENSITIVIYT,
        MANUAL_AWB_MODE,
        MANUALWB_MODE,
        MANUALWB_CCT,
        MANUALWB_GAINS,
        MANUAL_AF_MODE,
        MANUAL_AE_MODE,
        MANUAL_AE_ANTIBANDING_MODE,
        MANUAL_COLOR_CORRECTION_MODE,
        MANUAL_CONTROL_MODE,
        MANUAL_ZSL_MODE,
        ZOOM,
        TOTAL_NUM_FRAMES,
        EXPOSURE_METERING,
        SELECT_PRIORITY,
        EXP_PRIORITY,
        JPEG_QUALITY,
        CROP_REGION,
    };
    char *const token[] = {
        [MANUAL_EXPOSURE]                   = (char *const)"manual_exp",
        [MANUAL_ISO]                        = (char *const)"manual_iso",
        [ANTBANDING]                        = (char *const)"antimode",
        [MANUAL_SENSITIVIYT]                = (char *const)"manualsens",
        [MANUAL_AWB_MODE]                   = (char *const)"manualawbmode",
        [MANUALWB_MODE]                     = (char *const)"manualwb_mode",
        [MANUALWB_CCT]                      = (char *const)"manualwb_cct",
        [MANUALWB_GAINS]                    = (char *const)"manualwb_gains",
        [MANUAL_AF_MODE]                    = (char *const)"manualafmode",
        [MANUAL_AE_MODE]                    = (char *const)"manualaemode",
        [MANUAL_AE_ANTIBANDING_MODE]        = (char *const)"manualantimode",
        [MANUAL_COLOR_CORRECTION_MODE]      = (char *const)"manualcorcorrectionmode",
        [MANUAL_CONTROL_MODE]               = (char *const)"manualctrmode",
        [MANUAL_ZSL_MODE]                   = (char *const)"manualzslmode",
        [ZOOM]                              = (char *const)"zoom",
        [TOTAL_NUM_FRAMES]                  = (char *const)"numframes",
        [EXPOSURE_METERING]                 = (char *const)"expmetering",
        [SELECT_PRIORITY]                   = (char *const)"selPriority",
        [EXP_PRIORITY]                      = (char *const)"expPriority",
        [JPEG_QUALITY]                      = (char *const)"jpegquality",
        [CROP_REGION]                       = (char *const)"cropregion",
        NULL
    };
    char* value;
    int errfnd = 0;
    int res = 0;

    sp<VendorTagDescriptor> vTags =
        android::VendorTagDescriptor::getGlobalVendorTagDescriptor();


    while (*order != '\0' && !errfnd) {
        switch ( getsubopt(&order, token, &value)){
        case MANUAL_EXPOSURE:{
            QCAMX_PRINT("exposure value:%s\n",value);
            float expTimeMs;
            sscanf(value,"%f",&expTimeMs);
            int64_t expTimeNs = (int64_t)(expTimeMs*1000000L);
            uint8_t aemode = 0;
            (*metaUpdate).update(ANDROID_CONTROL_AE_MODE,&(aemode),1);
            (*metaUpdate).update(ANDROID_SENSOR_EXPOSURE_TIME,&(expTimeNs),1);
            break;
        }
        case MANUAL_ISO:{
            QCAMX_PRINT("iso value:%s\n",value);
            int32_t iso;
            uint8_t aemode = 0;
            sscanf(value,"%d",&iso);
            (*metaUpdate).update(ANDROID_CONTROL_AE_MODE,&(aemode),1);
            (*metaUpdate).update(ANDROID_SENSOR_SENSITIVITY,&(iso),1);
            break;
        }
        case ANTBANDING:{
            uint8_t antimode;
            sscanf(value,"%c",&antimode);
            (*metaUpdate).update(ANDROID_CONTROL_AE_ANTIBANDING_MODE,&antimode,1);
            break;
        }
        case MANUAL_SENSITIVIYT:{
            int sensitivity = 0;
            int64_t expTimeNs;
            QCAMX_PRINT("sensor sensitivity:%s\n",value);
            sscanf(value,"%d",&sensitivity);
            (*metaUpdate).update(ANDROID_SENSOR_SENSITIVITY, &(sensitivity),1);
            if (100 == sensitivity) {
                expTimeNs = 10000000;
                (*metaUpdate).update(ANDROID_SENSOR_EXPOSURE_TIME,&(expTimeNs),1);
            } else if (200 == sensitivity) {
                expTimeNs = 20000000;
                (*metaUpdate).update(ANDROID_SENSOR_EXPOSURE_TIME,&(expTimeNs),1);
            } else if (400 == sensitivity) {
                expTimeNs = 40000000;
                (*metaUpdate).update(ANDROID_SENSOR_EXPOSURE_TIME,&(expTimeNs),1);
            } else if (800 == sensitivity) {
                expTimeNs = 60000000;
                (*metaUpdate).update(ANDROID_SENSOR_EXPOSURE_TIME,&(expTimeNs),1);
            } else if (1600 == sensitivity) {
                expTimeNs = 80000000;
                (*metaUpdate).update(ANDROID_SENSOR_EXPOSURE_TIME,&(expTimeNs),1);
            }
            break;
        }
        case MANUAL_AWB_MODE:{
            uint8_t awbmode;
            QCAMX_PRINT("awb mode:%s 0:off 1:auto\n",value);
            sscanf(value,"%c",&awbmode);
            (*metaUpdate).update(ANDROID_CONTROL_AWB_MODE, &(awbmode), 1);
            break;
        }
        case MANUALWB_MODE:{
            QCAMX_PRINT("manual wb mode:%s 0:disable 1: CCT 2: Gains\n",value);
            uint32_t tag = 0;
            int32_t mwbmode;
            sscanf(value,"%d",&mwbmode);
            CameraMetadata::getTagFromName("org.codeaurora.qcamera3.manualWB.partial_mwb_mode",vTags.get(), &tag);
            (*metaUpdate).update(tag, &mwbmode, 1);
            break;
        }
        case MANUALWB_CCT:{
            QCAMX_PRINT("manual wb cct:%s\n",value);
            uint32_t tag = 0;
            int32_t mwb_cct;
            sscanf(value,"%d",&mwb_cct);
            CameraMetadata::getTagFromName("org.codeaurora.qcamera3.manualWB.color_temperature",vTags.get(), &tag);
            (*metaUpdate).update(tag, &mwb_cct, 1);
            break;
        }
        case MANUALWB_GAINS:{
            QCAMX_PRINT("manual wb gains:%s\n",value);
            uint32_t tag = 0;
            float mwb_gains[3];
            sscanf(value,"%f-%f-%f",&mwb_gains[0], &mwb_gains[1], &mwb_gains[2]);
            CameraMetadata::getTagFromName("org.codeaurora.qcamera3.manualWB.gains",vTags.get(), &tag);
            (*metaUpdate).update(tag, mwb_gains, 3);
            break;
        }
        case MANUAL_AF_MODE:{
            uint8_t afmode;
            QCAMX_PRINT("af mode:%s 0:off 1:auto\n",value);
            sscanf(value,"%c",&afmode);
            (*metaUpdate).update(ANDROID_CONTROL_AF_MODE, &(afmode), 1);
            break;
        }
        case MANUAL_AE_MODE:{
            uint8_t aemode = 0;
            sscanf(value,"%c",&aemode);
            QCAMX_PRINT("ae mode:%d 0:off 1:on\n",aemode);
            (*metaUpdate).update(ANDROID_CONTROL_AE_MODE, &(aemode), 1);
            break;
        }
        case MANUAL_AE_ANTIBANDING_MODE:{
            uint8_t antibandingmode;
            QCAMX_PRINT("antibanding mode :%s 0:off 1:50hz 2:60hz 3:auto\n",value);
            sscanf(value,"%c",&antibandingmode);
            (*metaUpdate).update(ANDROID_CONTROL_AE_ANTIBANDING_MODE, &(antibandingmode), 1);
            break;
        }
        case MANUAL_COLOR_CORRECTION_MODE:{
            uint8_t colorCorrectMode;
            QCAMX_PRINT("color correction mode:%s 0:matrix 1:fast 2:hightQuality\n",value);
            sscanf(value,"%c",&colorCorrectMode);
            (*metaUpdate).update(ANDROID_COLOR_CORRECTION_MODE, &(colorCorrectMode), 1);
            break;
        }
        case MANUAL_CONTROL_MODE:{
            uint8_t ctrlMode;
            QCAMX_PRINT("contorl mode:%s 0:off 1:auto\n",value);
            sscanf(value,"%c",&ctrlMode);
            (*metaUpdate).update(ANDROID_CONTROL_MODE, &(ctrlMode), 1);
            break;
        }
        case MANUAL_ZSL_MODE:{
            uint8_t zslMode;
            sscanf(value,"%c",&zslMode);
            QCAMX_PRINT("enble zslMode:%d\n 0:false 1:true\n",zslMode);
            (*metaUpdate).update(ANDROID_CONTROL_ENABLE_ZSL, &(zslMode), 1);
            break;
        }
        case ZOOM:{
            int32_t cropregion[4] = {0};
            int32_t zoom;
            QCAMX_PRINT("zoom:%s \n",value);
            sscanf(value,"%d",&zoom);

            camera_metadata_ro_entry activeArraySize =
                ((const CameraMetadata)mStaticMeta).find(ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE);
            int32_t activeWidth;
            int32_t activeHeight;
            if (activeArraySize.count == 2) {
                activeWidth = activeArraySize.data.i32[0];
                activeHeight = activeArraySize.data.i32[1];
            } else if (activeArraySize.count == 4) {
                activeWidth = activeArraySize.data.i32[2];
                activeHeight = activeArraySize.data.i32[3];
            } else {
                QCAMX_PRINT("faile to get active size \n");
                break;
            }

            int32_t dstWidth = activeWidth / zoom;
            int32_t dstHeight = activeHeight / zoom;
            cropregion[0] = (activeWidth - dstWidth) / 2;
            cropregion[1] = (activeHeight - dstHeight) / 2;
            cropregion[2] = dstWidth;
            cropregion[3] = dstHeight;

            QCAMX_PRINT("active size: %d x %d, cropRegion:[%d,%d,%d,%d] \n",
                activeWidth, activeHeight, cropregion[0], cropregion[1], cropregion[2], cropregion[3]);

            (*metaUpdate).update(ANDROID_SCALER_CROP_REGION, cropregion, 4);
            break;
        }
        case TOTAL_NUM_FRAMES:{
            uint32_t tag = 0;
            int32_t numFrames= 0;
            sscanf(value,"%d",&numFrames);
            CameraMetadata::getTagFromName("org.quic.camera2.mfnrconfigs.MFNRTotalNumFrames",vTags.get(), &tag);
            (*metaUpdate).update(tag,&numFrames,1);
            break;
        }
        case EXPOSURE_METERING:{
            uint32_t tag = 0;
            int32_t metering= 0;
            sscanf(value,"%d",&metering);
            CameraMetadata::getTagFromName("org.codeaurora.qcamera3.exposure_metering.exposure_metering_mode",vTags.get(), &tag);
            (*metaUpdate).update(tag,&metering,1);
            break;
        }
        case SELECT_PRIORITY:{
            uint32_t tag = 0;
            int32_t selPriority= 0;
            sscanf(value,"%d",&selPriority);
            CameraMetadata::getTagFromName("org.codeaurora.qcamera3.iso_exp_priority.select_priority",vTags.get(), &tag);
            (*metaUpdate).update(tag,&selPriority,1);
            break;
        }
        case EXP_PRIORITY:{
            uint32_t tag = 0;
            int64_t expPriority= 0;
            sscanf(value,"%ld",&expPriority);
            CameraMetadata::getTagFromName("org.codeaurora.qcamera3.iso_exp_priority.use_iso_exp_priority",vTags.get(), &tag);
            (*metaUpdate).update(tag,&expPriority,1);
            break;
        }
        case JPEG_QUALITY:{
            QCAMX_PRINT("jpegquality value:%s\n",value);
            uint8_t jpegquality = 0;
            sscanf(value,"%c",&jpegquality);
            (*metaUpdate).update(ANDROID_JPEG_QUALITY,&(jpegquality),1);
            break;
        }
        case CROP_REGION:{
            int32_t cropregion[4] = {0};
            int32_t x;
            int32_t y;
            int32_t width;
            int32_t height;
            QCAMX_PRINT("cropregion:%s \n", value);
            sscanf(value,"%dx%dx%dx%d",&x, &y, &width, &height);

            camera_metadata_ro_entry activeArraySize =
                ((const CameraMetadata)mStaticMeta).find(ANDROID_SENSOR_INFO_ACTIVE_ARRAY_SIZE);
            int32_t activeWidth;
            int32_t activeHeight;
            if (activeArraySize.count == 2) {
                activeWidth = activeArraySize.data.i32[0];
                activeHeight = activeArraySize.data.i32[1];
            } else if (activeArraySize.count == 4) {
                activeWidth = activeArraySize.data.i32[2];
                activeHeight = activeArraySize.data.i32[3];
            } else {
                QCAMX_PRINT("failed to get active size \n");
                break;
            }

            if (x < 0 || y < 0 || width < 0 || height < 0 ||
                activeWidth < (x + width) || activeHeight < (y + height))
            {
                QCAMX_PRINT("Invalid input cropregion: [%d,%d,%d,%d] active size: %d x %d \n",
                   x, y, width, height, activeWidth, activeHeight);
                break;
            }

            cropregion[0] = x;
            cropregion[1] = y;
            cropregion[2] = width;
            cropregion[3] = height;

            QCAMX_PRINT("active size: %d x %d, cropRegion:[%d,%d,%d,%d] \n",
               activeWidth, activeHeight, cropregion[0], cropregion[1], cropregion[2], cropregion[3]);

            (*metaUpdate).update(ANDROID_SCALER_CROP_REGION, cropregion, 4);
            break;
        }
        default:
            break;
        }
    }
    if (errfnd) res = -1;
    return res;
}


/************************************************************************
* name : parseCommandlineMetaDump
* function: get dump meta info from cmd.
************************************************************************/
int QCamxHAL3TestConfig::parseCommandlineMetaDump(int ordersize,char* order)
{
    enum {
        EXPOSURE_VALUE = 0,
        ISO_VALUE ,
        AE_MODE,
        AWB_MODE,
        AF_MODE,
        AF_VALUE,
        AE_ANTIBANDING_MODE,
        COLOR_CORRECTION_MODE,
        COLOR_CORRECTION_VALUE,
        CONTROL_MODE,
        SCENE_MODE,
        HDR_MODE,
        ZOOM_VALUE,
        ZSL_MODE,
        TOTAL_NUM_FRAMES,
        EXPOSURE_METERING,
        SELECT_PRIORITY,
        EXP_PRIORITY,
        SHOW_FPS,
        JPEG_QUALITY,
        RESULT_FILE,
        RESULT_LOG_TAG,
        SHOW_CROP_REGION,
    };
    char *const token[] = {
        [EXPOSURE_VALUE]         = (char *const)"expvalue",
        [ISO_VALUE]              = (char *const)"isovalue",
        [AE_MODE]                = (char *const)"aemode",
        [AWB_MODE]               = (char *const)"awbmode",
        [AF_MODE]                = (char *const)"afmode",
        [AF_VALUE]               = (char *const)"afvalue",
        [AE_ANTIBANDING_MODE]    = (char *const)"ae_antimode",
        [COLOR_CORRECTION_MODE]  = (char *const)"color_correctmode",
        [COLOR_CORRECTION_VALUE] = (char *const)"color_correctvalue",
        [CONTROL_MODE]           = (char *const)"controlmode",
        [SCENE_MODE]             = (char *const)"scenemode",
        [HDR_MODE]               = (char *const)"hdrmode",
        [ZOOM_VALUE]             = (char *const)"zoomvalue",
        [ZSL_MODE]               = (char *const)"zslmode",
        [TOTAL_NUM_FRAMES]       = (char *const)"numframes",
        [EXPOSURE_METERING]      = (char *const)"expmetering",
        [SELECT_PRIORITY]        = (char *const)"selPriority",
        [EXP_PRIORITY]           = (char *const)"expPriority",
        [SHOW_FPS]               = (char *const)"showfps",
        [JPEG_QUALITY]           = (char *const)"jpegquality",
        [RESULT_FILE]            = (char *const)"file",
        [RESULT_LOG_TAG]         = (char *const)"tag",
        [SHOW_CROP_REGION]       = (char *const)"showcropregion",
        NULL
    };
    char* value;
    int errfnd = 0;
    int res = 0;
    QCAMX_DBG("order:%s\n",order);
    while (*order != '\0' && !errfnd) {
        char opt = getsubopt(&order, token, &value);
        switch (opt){
        case EXPOSURE_VALUE:{
            int exp = atoi(value);
            mMetaDump.exposureValue = exp;
            QCAMX_PRINT("exposure time:%d\n",mMetaDump.exposureValue);
            break;
        }
        case ISO_VALUE:{
            int iso = atoi(value);
            mMetaDump.isoValue = iso;
            QCAMX_PRINT("iso value:%d\n",mMetaDump.isoValue);
            break;
        }
        case AE_MODE:{
            int ae_mode = atoi(value);
            mMetaDump.aeMode = ae_mode;
            QCAMX_PRINT("AE mode:%d\n",mMetaDump.aeMode);
            break;
        }
        case AWB_MODE:{
            int awb_mode = atoi(value);
            mMetaDump.awbMode = awb_mode;
            QCAMX_PRINT("AWB mode:%d\n",mMetaDump.awbMode);
            break;
        }
        case AF_MODE:{
            int af_mode = atoi(value);
            mMetaDump.afMode = af_mode;
            QCAMX_PRINT("AF mode:%d\n",mMetaDump.afMode);
            break;
        }
        case AF_VALUE:{
            int af_value = atoi(value);
            mMetaDump.afValue = af_value;
            QCAMX_PRINT("AF value:%d\n",mMetaDump.afValue);
            break;
        }
        case AE_ANTIBANDING_MODE:{
            int anti = atoi(value);
            mMetaDump.aeAntiMode = anti;
            QCAMX_PRINT("aeAnti Mode:%d\n",mMetaDump.aeAntiMode);
            break;
        }
        case COLOR_CORRECTION_MODE:{
            int cc_mode = atoi(value);
            mMetaDump.colorCorrectMode = cc_mode;
            QCAMX_PRINT("colorCorrect Mode:%d\n",mMetaDump.colorCorrectMode);
            break;
        }
        case COLOR_CORRECTION_VALUE:{
            int cc_value = atoi(value);
            mMetaDump.colorCorrectValue = cc_value;
            QCAMX_PRINT("colorCorrect Value:%d\n",mMetaDump.colorCorrectValue);
            break;
        }
        case CONTROL_MODE:{
            int control = atoi(value);
            mMetaDump.controlMode = control;
            QCAMX_PRINT("control mode:%d\n",mMetaDump.controlMode);
        }
        case SCENE_MODE:{
            int scene = atoi(value);
            mMetaDump.sceneMode = scene;
            QCAMX_PRINT("scene mode:%d\n",mMetaDump.sceneMode);
            break;
        }
        case HDR_MODE:{
            int hdr = atoi(value);
            mMetaDump.hdrMode = hdr;
            QCAMX_PRINT("hdr mode:%d\n",mMetaDump.hdrMode);
            break;
        }
        case ZOOM_VALUE:{
            int zoom = atoi(value);
            mMetaDump.zoomValue = zoom;
            QCAMX_PRINT("zoom mode:%d\n",mMetaDump.zoomValue);
            break;
        }
        case ZSL_MODE:{
            int zsl = atoi(value);
            mMetaDump.zslMode = zsl;
            QCAMX_PRINT("zsl mode:%d\n",mMetaDump.zslMode);
            break;
        }
        case TOTAL_NUM_FRAMES:{
            int frame_num = atoi(value);
            mMetaDump.numFrames = frame_num;
            QCAMX_PRINT("exp metering:%d\n",mMetaDump.numFrames);
            break;
        }
        case EXPOSURE_METERING:{
            int exp_metering = atoi(value);
            mMetaDump.expMetering = exp_metering;
            QCAMX_PRINT("exp metering:%d\n",mMetaDump.expMetering);
            break;
        }
        case SELECT_PRIORITY:{
            int priority = atoi(value);
            mMetaDump.selPriority = priority;
            QCAMX_PRINT("exp metering:%d\n",mMetaDump.selPriority);
            break;
        }
        case EXP_PRIORITY:{
            int exp_priority = atoi(value);
            mMetaDump.expPriority = exp_priority;
            QCAMX_PRINT("exp metering:%d\n",mMetaDump.expPriority);
            break;
        }
        case RESULT_FILE:{
            char file[200] = {0};
            sscanf(value,"%s",file);
            mDump->setPath(file);
            break;
        }
        case RESULT_LOG_TAG:{
            if (mDump) {
                mDump->mTag = "[" + string(value) + "] ";
            }
            break;
        }
        case SHOW_FPS:{
            int showfps = 0;
            sscanf(value,"%d",&showfps);
            QCAMX_PRINT("show fps:%d\n",showfps);
            mShowFps = showfps;
            break;
        }
        case JPEG_QUALITY:{
            int jpeg_quality = atoi(value);
            mMetaDump.jpegquality = jpeg_quality;
            QCAMX_PRINT("jpegquality value:%d\n",mMetaDump.jpegquality);
            break;
        }
        case SHOW_CROP_REGION:{
            int showcropregion = atoi(value);
            mMetaDump.showCropRegion = showcropregion;
            QCAMX_PRINT("show crop region:%d\n",mMetaDump.showCropRegion);
            break;
        }
        default:{
            QCAMX_PRINT("opt:%d order:%s not support\n",opt,value);
            break;
        }
        }
    }
    if (errfnd) res = -1;
    return res;
}

/************************************************************************
* name : parseCommandlineAdd
* function: get Initialize info from cmd for open camera.
************************************************************************/
int QCamxHAL3TestConfig::parseCommandlineAdd(int ordersize,char* order)
{
    enum {
        ID_OPT = 0,
        PREVIEW_SIZE_OPT,
        SNAPSHOT_SIZE_OPT,
        VIDEO_SIZE_OPT,
        PREVIEW_FORMAT_OPT,
        SNAPSHOT_FORMAT_OPT,
        VIDEO_FORMAT_OPT,
        SHOT_NUMBER,
        RESULT_FILE,
        LOG_FILE,
        FPS_RANGE,
        CODEC_TYPE,
        ZSL_MODE,
        BITRATE,
        TARGET_BITRATE,
        IS_BITRATE_CONST,
        TOF_RANGE_MODE,
        TOF_IMAGE_TYPE,
    };
    char *const token[] = {
        [ID_OPT]                = (char *const)"id",
        [PREVIEW_SIZE_OPT]      = (char *const)"psize",
        [SNAPSHOT_SIZE_OPT]     = (char *const)"ssize",
        [VIDEO_SIZE_OPT]        = (char *const)"vsize",
        [PREVIEW_FORMAT_OPT]    = (char *const)"pformat",
        [SNAPSHOT_FORMAT_OPT]   = (char *const)"sformat",
        [VIDEO_FORMAT_OPT]      = (char *const)"vformat",
        [SHOT_NUMBER]           = (char *const)"snapnum",
        [RESULT_FILE]           = (char *const)"resultfile",
        [LOG_FILE]              = (char *const)"logfile",
        [FPS_RANGE]             = (char *const)"fpsrange",
        [CODEC_TYPE]            = (char *const)"codectype",
        [ZSL_MODE]              = (char *const)"zsl",
        [BITRATE]               = (char *const)"bitrate",
        [TARGET_BITRATE]        = (char *const)"targetbitrate",
        [IS_BITRATE_CONST]      = (char *const)"isbitrateconst",
        [TOF_RANGE_MODE]        = (char *const)"mode",
        [TOF_IMAGE_TYPE]        = (char *const)"itype",
        NULL
    };
    enum {
        CONTROL_RATE_CONSTANT = 1,
    };

    char* value;
    int errfnd = 0;
    int width;
    int height;
    int res = 0;
    int modeConfig = 0;
    QCAMX_INFO("Command Add:%s\n",order);
    while (*order != '\0' && !errfnd) {
        switch ( getsubopt(&order, token, &value)){
        case ID_OPT:{
            QCAMX_PRINT("camera:%s\n",value);
            int id = atoi(value);
            mCameraId = id;
        }
            break;
        case PREVIEW_SIZE_OPT:{
            QCAMX_PRINT("preview size:%s\n",value);
            sscanf(value,"%dx%d",&width,&height);
            mPreviewStream.width = width;
            mPreviewStream.height = height;
            modeConfig |= (1 << TESTMODE_PREVIEW);
        }
            break;
        case SNAPSHOT_SIZE_OPT:{
            QCAMX_PRINT("snapshot size:%s\n",value);
            sscanf(value,"%dx%d",&width,&height);
            mSnapshotStream.width = width;
            mSnapshotStream.height = height;
            modeConfig |= (1 << TESTMODE_SNAPSHOT);
        }
            break;
        case VIDEO_SIZE_OPT:{
            QCAMX_PRINT("video size:%s\n video format:%s\n",value,"yuv420");
            sscanf(value,"%dx%d",&width,&height);
            mVideoStream.width = width;
            mVideoStream.height = height;
            mVideoStream.format = HAL_PIXEL_FORMAT_YCBCR_420_888;
            modeConfig |= (1 << TESTMODE_VIDEO);
        }
            break;
        case PREVIEW_FORMAT_OPT:{
            QCAMX_PRINT("preview format:%s\n",value);
            /****
              support:
              raw16         HAL_PIXEL_FORMAT_RAW16                  32
              jpeg          HAL_PIXEL_FORMAT_BLOB                   33
              yuv_ubwc      HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED 34
              yuv_ubwc_enc  HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED 34
              yuv420        HAL_PIXEL_FORMAT_YCBCR_420_888          35
              raw_opaque    HAL_PIXEL_FORMAT_RAW_OPAQUE             36
              raw10         HAL_PIXEL_FORMAT_RAW10                  37
              raw12         HAL_PIXEL_FORMAT_RAW12                  38
             *****/
            mPreviewStream.type = CAMERA3_TEMPLATE_PREVIEW;
            if (!strcmp("yuv420", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_YCBCR_420_888;
            } else if (!strcmp("yuv_ubwc", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED;
            } else if (!strcmp("yuv_ubwc_enc", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED;
                mPreviewStream.type   = CAMERA3_TEMPLATE_VIDEO_RECORD;
            } else if (!strcmp("raw10", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_RAW10;
            } else if (!strcmp("raw12", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_RAW12;
            } else if (!strcmp("raw16", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_RAW16;
            } else if (!strcmp("y16", value)) {
                mPreviewStream.format = HAL_PIXEL_FORMAT_Y16;
            }
        }
            break;
        case SNAPSHOT_FORMAT_OPT:{
            QCAMX_PRINT("snapshot format:%s\n",value);
            if (!strcmp("yuv420", value)) {
                mSnapshotStream.format = HAL_PIXEL_FORMAT_YCBCR_420_888;
            } else if (!strcmp("jpeg", value)) {
                mSnapshotStream.format = HAL_PIXEL_FORMAT_BLOB;
            } else if (!strcmp("raw10", value)) {
                mSnapshotStream.format = HAL_PIXEL_FORMAT_RAW10;
            } else if (!strcmp("raw12", value)) {
                mSnapshotStream.format = HAL_PIXEL_FORMAT_RAW12;
            } else if (!strcmp("raw16", value)) {
                mSnapshotStream.format = HAL_PIXEL_FORMAT_RAW16;
            }
        }
            break;
        case VIDEO_FORMAT_OPT:{
            QCAMX_PRINT("video format:%s\n", value);
            mVideoStream.type   = CAMERA3_TEMPLATE_VIDEO_RECORD;
            if (!strcmp("yuv420", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_YCBCR_420_888;
            } else if (!strcmp("yuv_ubwc", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED;
            } else if (!strcmp("yuv_ubwc_enc", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED;
                mVideoStream.type   = CAMERA3_TEMPLATE_VIDEO_RECORD;
            } else if (!strcmp("raw10", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_RAW10;
            } else if (!strcmp("raw12", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_RAW12;
            } else if (!strcmp("raw16", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_RAW16;
            } else if (!strcmp("y16", value)) {
                mVideoStream.format = HAL_PIXEL_FORMAT_Y16;
            }
        }
            break;
        case SHOT_NUMBER:{
            QCAMX_PRINT("shot number:%s\n",value);
            int num;
            sscanf(value,"%d",&num);
            mSnapshotStream.requestNumber = num;
        }
            break;
        case RESULT_FILE:
            QCAMX_PRINT("result file:%s\n",value);
            break;
        case LOG_FILE:
            QCAMX_PRINT("log file:%s\n",value);
            break;
        case FPS_RANGE:{
            int fps_range[2];
            sscanf(value,"%d-%d",&fps_range[0], &fps_range[1]);
            if (fps_range[0]>fps_range[1]) {
                QCAMX_PRINT("FPS_RANGE Wrong: min:%d is bigger than max:%d exchange them\n",
                    fps_range[0],fps_range[1]);
                mFpsRange[0] = fps_range[1];
                mFpsRange[1] = fps_range[0];
            } else {
                QCAMX_PRINT("FPS_RANGE: min:%d max:%d\n",fps_range[0],fps_range[1]);
                mFpsRange[0] = fps_range[0];
                mFpsRange[1] = fps_range[1];
            }
            break;
        }

        case CODEC_TYPE:
            QCAMX_PRINT("codec type: %s\n",value);
            mIsH265 = atoi(value);
            break;
        case ZSL_MODE:{
            int isZSL = atoi(value);
            QCAMX_PRINT("in %sZSL mode",isZSL ? "":"Non-");
            if (isZSL == 0){
               mZslEnabled = false;
            }
            break;
        }
        case BITRATE:{
            uint32_t bitrate = 0;
            sscanf(value, "%u", &bitrate);
            QCAMX_PRINT("bitrate: %u\n", bitrate);
            mVideoRateConfig.bitrate = bitrate * 1024 * 1024;
            break;
        }
        case TARGET_BITRATE:{
            uint32_t targetBitrate = 0;
            sscanf(value, "%u", &targetBitrate);
            QCAMX_PRINT("targetBitrate: %u\n", targetBitrate);
            mVideoRateConfig.targetBitrate = targetBitrate * 1024 * 1024;
            break;
        }
        case IS_BITRATE_CONST:{
            int isBitRateConstant = atoi(value);
            QCAMX_PRINT("%sbitRateConstant mode\n", isBitRateConstant ? "" : "Non-");
            if (isBitRateConstant == (int) CONTROL_RATE_CONSTANT) {
                mVideoRateConfig.isBitRateConstant = true;
            }
            break;
        }

        /****************************************************
        "0: short range mode"
        "1: long  range mode"
        ****************************************************/
        case TOF_RANGE_MODE:{
            int rangeMode = atoi(value);
            QCAMX_PRINT("rangeMode:%d\n", rangeMode);
            if (rangeMode >= 0 && rangeMode <= 1) {
                mRangeMode = rangeMode;
            }
            else {
                QCAMX_PRINT("Invalid range mode:%d, valid value:0/1\n", rangeMode);
                errfnd = 1;
            }
            break;
        }
        /****************************************************
           "0: TL_E_IMAGE_TYPE_VGA_DEPTH_QVGA_IR_BG"
           "1: TL_E_IMAGE_TYPE_QVGA_DEPTH_IR_BG"
           "2: TL_E_IMAGE_TYPE_VGA_DEPTH_IR"
           "3: TL_E_IMAGE_TYPE_VGA_IR_QVGA_DEPTH"
           "4: TL_E_IMAGE_TYPE_VGA_IR_BG");
        ****************************************************/
        case TOF_IMAGE_TYPE:{
            int imageType = atoi(value);
            QCAMX_PRINT("imageType:%d\n", imageType);
            if (imageType >= 0 && imageType <= 4) {
                mImageType = imageType;
            }
            else {
                QCAMX_PRINT("Invalid range mode:%d, valid value:0/1/2/3/4\n", imageType);
                errfnd = 1;
            }
            break;
        }

        default:
            QCAMX_PRINT("WARNING Command Add unsupport order param: %s \n", value);
            break;
        }
    }
    switch (modeConfig){
        case (1 << TESTMODE_PREVIEW):
            mTestMode = TESTMODE_PREVIEW;
            break;
        case ((1 << TESTMODE_PREVIEW) | (1 << TESTMODE_SNAPSHOT)):
            mTestMode = TESTMODE_SNAPSHOT;
            break;
        case ((1 << TESTMODE_PREVIEW) | (1 << TESTMODE_VIDEO)):
        case ((1 << TESTMODE_PREVIEW) | (1 << TESTMODE_SNAPSHOT) | (1 << TESTMODE_VIDEO)):
            mTestMode = TESTMODE_VIDEO;
            break;
        case (1 << TESTMODE_VIDEO):
            mTestMode = TESTMODE_VIDEO_ONLY;
            break;
        default:
            res = -1;
            break;
    }
    if (errfnd) res = -1;
    return res;
}
