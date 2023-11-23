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
/// @file  aecsensorconfig.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "aecsensorconfig.h"
#include "parametersetmanager.h"

AECSENSORCONFIG_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECSensorHDRConfigClass::AECSensorHDRConfigClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(SensorLumaComp);
    PARAMETER_INITIALIZE(esRatio);
    PARAMETER_INITIALIZE(LumaCalculationConfig);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECSensorHDRConfigClass::AECSensorHDRConfigClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(SensorLumaComp);
    PARAMETER_INITIALIZE(esRatio);
    PARAMETER_INITIALIZE(LumaCalculationConfig);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECSensorHDRConfigClass::~AECSensorHDRConfigClass()
{
    UnloadAECSensorHDRConfig(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* AECSensorHDRConfigClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "SensorHDRDefaultConfig")) == 0)
    {
        name = "SensorHDRDefaultConfig";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load AECSensorHDRConfig
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECSensorHDRConfigClass::LoadAECSensorHDRConfig(
    ParameterFileSymbolTableEntry* entry,
    AECSensorHDRConfig* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && entry->Read(&structure->SensorLumaComp, alignment);
    result = result && entry->Read(&structure->esRatio, alignment);
    structure->LumaCalculationConfig = (LumaCalculationType)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECSensorHDRConfigClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECSensorHDRConfig::module_versionStruct* structure,
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
BOOL AECSensorHDRConfigClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECSensorHDRConfig::parameter_versionStruct* structure,
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
/// Unload AECSensorHDRConfig
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECSensorHDRConfigClass::UnloadAECSensorHDRConfig(
    AECSensorHDRConfig* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECSensorHDRConfigClass::Unloadparameter_versionStruct(
    AECSensorHDRConfig::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* AECSensorHDRConfigClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    AECSensorHDRConfigClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW AECSensorHDRConfigClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadAECSensorHDRConfig(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


AECSENSORCONFIG_NAMESPACE_END