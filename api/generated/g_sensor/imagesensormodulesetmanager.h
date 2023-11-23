////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2023 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// THIS IS AUTO-GENERATED CODE.  PLEASE DO NOT EDIT (File bug reports against tools).
///
/// Auto-generated by: Parameter Parser V2.0.0 (1907311625)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  imagesensormodulesetmanager.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "parametersetmanager.h"
#include "parametermodule.h"
#include "parametertypes.h"
#include "camxmoduleconfig.h"
#include "camxactuatordriver.h"
#include "camxpdafconfig.h"
#include "camxeepromdriver.h"
#include "camxflashdriver.h"
#include "camxeebindriver.h"
#include "camxsensordriver.h"
#include "camxoisdriver.h"

#define IMAGESENSORMODULE_DEFAULT_MODULE_COUNT 9
#ifndef IMAGESENSORMODULESETMANAGER_H
#define IMAGESENSORMODULESETMANAGER_H

#include <iostream>
#include <unordered_map>

class ImageSensorModuleSetManager : public ParameterSetManager
{
public:
    ImageSensorModuleSetManager();
    virtual ~ImageSensorModuleSetManager()
    {
        for (UINT32 i = 0; i < IMAGESENSORMODULE_DEFAULT_MODULE_COUNT; i++)
        {
            PARAMETER_DELETE m_defaultModules[i];
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// UpdateBinaryParameters
    ///
    /// @brief Replaces exising parameters with the ones in a buffer. LoadBinaryParameters must be called first
    /// @brief After calling UpdateBinaryParameters, call FreeReplacedParameter to free up any replaced parameter objects
    ///
    /// @param buffer   Binary parameter buffer
    /// @param length   Length of the binary parameter buffer
    ///
    /// @return Node
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL UpdateBinaryParameters(
        UINT8* buffer,
        UINT64 length);

    CamX::CameraModuleData* GetModule_cameraModuleData(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::ActuatorDriverData* GetModule_actuatorDriver(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::ActuatorDriverData* GetModule_actuatorDriver1(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::PDAFConfigurationData* GetModule_PDConfigData(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::EEPROMDriverData* GetModule_EEPROMDriverData(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::FlashDriverData* GetModule_flashDriverData(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::EEbinDriver* GetModule_EEbinDriver(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::SensorDriverData* GetModule_sensorDriverData(
        TuningMode* modeBranch,
        UINT32 modeCount);

    CamX::OISDriverData* GetModule_OISDriver(
        TuningMode* modeBranch,
        UINT32 modeCount);


protected:
    virtual const ParameterModule* GetDefaultModule(
        char* type)
    {
        const ParameterModule* module = (const ParameterModule*)m_moduleMap[type];

        return module;
    }

    const ParameterModule* m_defaultModules[IMAGESENSORMODULE_DEFAULT_MODULE_COUNT];
    std::unordered_map<std::string, void*> m_moduleMap;
};

#endif