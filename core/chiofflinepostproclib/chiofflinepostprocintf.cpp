////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  chiofflinepostprocintf.cpp
/// @brief Static functions implemented for PostProc library. These are used by HIDL Library.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "chiofflinejpegencode.h"
#include "chiofflinepostprocintf.h"

// NOWHINE FILE GR017: Used intrinsic data types

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CameraPostProc_Create
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void* CameraPostProc_Create(
    PostProcCreateParams* pParams)
{
    ChiFeature2PostProcBase* pEncoder = NULL;

    if (YUVToJPEG == pParams->processMode)
    {
        pEncoder = ChiOfflineJpegEncode::Create(pParams);
    }
    else
    {
        CHX_LOG_ERROR("processMode %d is not supported", pParams->processMode);
    }

    return reinterpret_cast<void*>(pEncoder);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CameraPostProc_Process
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PostProcResultInfo CameraPostProc_Process(
    void*                   pPostProcInstance,
    PostProcSessionParams*  pSessionParams)
{
    ChiFeature2PostProcBase*    pProcBase       = reinterpret_cast<ChiFeature2PostProcBase*>(pPostProcInstance);
    PostProcResultInfo          postProcStatus  = {0};

    if (NULL != pProcBase)
    {
        postProcStatus = pProcBase->PostProcess(pSessionParams);
    }
    else
    {
        postProcStatus.size     = 0;
        postProcStatus.result   = POSTPROCFAILED;
    }

    return postProcStatus;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CameraPostProc_Destroy
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CameraPostProc_Destroy(
    void* pPostProcInstance)
{
    ChiFeature2PostProcBase* pProcBase = reinterpret_cast<ChiFeature2PostProcBase*>(pPostProcInstance);

    if (NULL != pProcBase)
    {
        pProcBase->Destroy();
    }
}
