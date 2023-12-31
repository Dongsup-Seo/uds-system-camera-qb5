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
/// @file  statsroidifference.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "statsroidifference.h"
#include "parametersetmanager.h"

STATSROIDIFFERENCE_NAMESPACE_BEGIN


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modFaceRoiDiffTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsroidifferenceClass::LoadmodFaceRoiDiffTriggerDataType(
    ParameterFileSymbolTableEntry* entry,
    modFaceRoiDiffTriggerDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = statsglobalelements::statsglobalelementsClass::LoadglbTriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW statsglobalelements::FaceROIDiffThresholdType[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = statsglobalelements::statsglobalelementsClass::LoadFaceROIDiffThresholdType(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixStatsROIDifferenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsroidifferenceClass::LoadchromatixStatsROIDifferenceType(
    ParameterFileSymbolTableEntry* entry,
    chromatixStatsROIDifferenceType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->statsROIDiffEnable, alignment);
    structure->TriggerCtrlType = (faceTriggerCtrlType)entry->ReadEnum(&result, alignment);
    result = result && LoadmodFaceRoiDiffTriggerDataType(entry, &structure->statsROIDiffThreshold, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload modFaceRoiDiffTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void statsroidifferenceClass::UnloadmodFaceRoiDiffTriggerDataType(
    modFaceRoiDiffTriggerDataType* structure)
{
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixStatsROIDifferenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void statsroidifferenceClass::UnloadchromatixStatsROIDifferenceType(
    chromatixStatsROIDifferenceType* structure)
{
    UnloadmodFaceRoiDiffTriggerDataType(&structure->statsROIDiffThreshold);
}

STATSROIDIFFERENCE_NAMESPACE_END
