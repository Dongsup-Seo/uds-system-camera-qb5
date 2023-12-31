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
/// @file  aecdepth.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "aecdepth.h"
#include "parametersetmanager.h"

AECDEPTH_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECDepthTypeClass::AECDepthTypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(lumaDiffThres);
    PARAMETER_INITIALIZE(decisionMapValidGridCntThres);
    PARAMETER_INITIALIZE(consecInvalidFrameCntThres);
    PARAMETER_INITIALIZE(initValidFrameCntThres);
    PARAMETER_INITIALIZE(selectMapValidGridCntThres);
    PARAMETER_INITIALIZE(displayDebugMsg);
    PARAMETER_INITIALIZE(depthMtr);
    PARAMETER_INITIALIZE(depthConv);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECDepthTypeClass::AECDepthTypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(lumaDiffThres);
    PARAMETER_INITIALIZE(decisionMapValidGridCntThres);
    PARAMETER_INITIALIZE(consecInvalidFrameCntThres);
    PARAMETER_INITIALIZE(initValidFrameCntThres);
    PARAMETER_INITIALIZE(selectMapValidGridCntThres);
    PARAMETER_INITIALIZE(displayDebugMsg);
    PARAMETER_INITIALIZE(depthMtr);
    PARAMETER_INITIALIZE(depthConv);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECDepthTypeClass::~AECDepthTypeClass()
{
    UnloadAECDepthType(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* AECDepthTypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "aecDepth")) == 0)
    {
        name = "aecDepth";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load DepthConvergenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::LoadDepthConvergenceType(
    ParameterFileSymbolTableEntry* entry,
    DepthConvergenceType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->convSpeedAdjRatio, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load DepthWeightZoneDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::LoadDepthWeightZoneDataType(
    ParameterFileSymbolTableEntry* entry,
    DepthWeightZoneDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->weight, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load DepthWeightZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::LoadDepthWeightZoneType(
    ParameterFileSymbolTableEntry* entry,
    DepthWeightZoneType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = aecglobalelements::aecglobalelementsClass::LoadTriggerPointType(entry, &structure->triggerPt, alignment);
    result = result && LoadDepthWeightZoneDataType(entry, &structure->triggerData, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load DepthMapLUT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::LoadDepthMapLUT(
    ParameterFileSymbolTableEntry* entry,
    DepthMapLUT* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array knees from symbol table
    {
        result = entry->Read(&structure->kneesCount, alignment);
        structure->kneesID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->knees = PARAMETER_NEW DepthWeightZoneType[structure->kneesCount];
        }
        if (!result || structure->knees == NULL)
        {
            structure->kneesCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->kneesCount; i++)
        {
            result = LoadDepthWeightZoneType(pointerEntry, &structure->knees[i], alignment);
        }
    }
    structure->type = (aecglobalelements::AECDepthLUTType)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load DepthMeteringType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::LoadDepthMeteringType(
    ParameterFileSymbolTableEntry* entry,
    DepthMeteringType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array depthMeteringWeight from symbol table
    {
        result = entry->Read(&structure->depthMeteringWeightCount, alignment);
        structure->depthMeteringWeightID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->depthMeteringWeight = PARAMETER_NEW DepthWeightZoneType[structure->depthMeteringWeightCount];
        }
        if (!result || structure->depthMeteringWeight == NULL)
        {
            structure->depthMeteringWeightCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->depthMeteringWeightCount; i++)
        {
            result = LoadDepthWeightZoneType(pointerEntry, &structure->depthMeteringWeight[i], alignment);
        }
    }

    // Reading Array mapsLUTs from symbol table
    {
        result = result && entry->Read(&structure->mapsLUTsCount, alignment);
        structure->mapsLUTsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mapsLUTs = PARAMETER_NEW DepthMapLUT[structure->mapsLUTsCount];
        }
        if (!result || structure->mapsLUTs == NULL)
        {
            structure->mapsLUTsCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mapsLUTsCount; i++)
        {
            result = LoadDepthMapLUT(pointerEntry, &structure->mapsLUTs[i], alignment);
        }
    }
    result = result && entry->Read(&structure->temporalFilter, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load AECDepthType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::LoadAECDepthType(
    ParameterFileSymbolTableEntry* entry,
    AECDepthType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && entry->Read(&structure->enableFlag, alignment);
    result = result && entry->Read(&structure->lumaDiffThres, alignment);
    result = result && entry->Read(&structure->decisionMapValidGridCntThres, alignment);
    result = result && entry->Read(&structure->consecInvalidFrameCntThres, alignment);
    result = result && entry->Read(&structure->initValidFrameCntThres, alignment);
    result = result && entry->Read(&structure->selectMapValidGridCntThres, alignment);
    result = result && entry->Read(&structure->displayDebugMsg, alignment);
    result = result && LoadDepthMeteringType(entry, &structure->depthMtr, alignment);
    result = result && LoadDepthConvergenceType(entry, &structure->depthConv, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECDepthType::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECDepthTypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECDepthType::parameter_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading String revision from symbol table
    {
        UINT32 count = 0;
        result = entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->revision = NULL;
        result = result && stringPointerEntry->ReadString(&structure->revision, count, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload DepthMapLUT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECDepthTypeClass::UnloadDepthMapLUT(
    DepthMapLUT* structure)
{
    PARAMETER_DELETE[] structure->knees;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload DepthMeteringType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECDepthTypeClass::UnloadDepthMeteringType(
    DepthMeteringType* structure)
{
    PARAMETER_DELETE[] structure->depthMeteringWeight;
    for (UINT32 i = 0; i < structure->mapsLUTsCount; i++)
    {
        UnloadDepthMapLUT(&structure->mapsLUTs[i]);
    }
    PARAMETER_DELETE[] structure->mapsLUTs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload AECDepthType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECDepthTypeClass::UnloadAECDepthType(
    AECDepthType* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    UnloadDepthMeteringType(&structure->depthMtr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECDepthTypeClass::Unloadparameter_versionStruct(
    AECDepthType::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* AECDepthTypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    AECDepthTypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW AECDepthTypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadAECDepthType(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


AECDEPTH_NAMESPACE_END
