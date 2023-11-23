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
/// @file  abf_3_4_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "abf_3_4_0.h"
#include "parametersetmanager.h"

ABF_3_4_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_abf34TypeClass::chromatix_abf34TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(dynamic_enable_triggers);
    PARAMETER_INITIALIZE(chromatix_abf34_reserve);
    PARAMETER_INITIALIZE(chromatix_abf34_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_abf34TypeClass::chromatix_abf34TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(dynamic_enable_triggers);
    PARAMETER_INITIALIZE(chromatix_abf34_reserve);
    PARAMETER_INITIALIZE(chromatix_abf34_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_abf34TypeClass::~chromatix_abf34TypeClass()
{
    Unloadchromatix_abf34Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_abf34TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "abf34_ife")) == 0)
    {
        name = "abf34_ife";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->bpc_fmax, alignment);
    result = result && entry->Read(&structure->bpc_fmin, alignment);
    result = result && entry->Read(&structure->bpc_maxshft, alignment);
    result = result && entry->Read(&structure->bpc_minshft, alignment);
    result = result && entry->Read(&structure->bpc_offset, alignment);
    result = result && entry->Read(&structure->blk_pix_matching_rb, alignment);
    result = result && entry->Read(&structure->blk_pix_matching_g, alignment);
    result = result && Loadabf34_rgn_dataType_noise_stdlut_level_tabStruct(entry, &structure->noise_stdlut_level_tab, alignment);
    result = result && Loadabf34_rgn_dataType_distance_ker_tabStruct(entry, &structure->distance_ker_tab, alignment);
    result = result && Loadabf34_rgn_dataType_curve_offset_tabStruct(entry, &structure->curve_offset_tab, alignment);
    result = result && entry->Read(&structure->noise_prsv_anchor_lo, alignment);
    result = result && entry->Read(&structure->noise_prsv_anchor_hi, alignment);
    result = result && Loadabf34_rgn_dataType_noise_prsv_lo_tabStruct(entry, &structure->noise_prsv_lo_tab, alignment);
    result = result && Loadabf34_rgn_dataType_noise_prsv_hi_tabStruct(entry, &structure->noise_prsv_hi_tab, alignment);
    result = result && Loadabf34_rgn_dataType_radial_gain_tabStruct(entry, &structure->radial_gain_tab, alignment);
    result = result && entry->Read(&structure->edge_softness, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType_noise_stdlut_level_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType_noise_stdlut_level_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType::noise_stdlut_level_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->noise_stdlut_level, 65, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType_distance_ker_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType_distance_ker_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType::distance_ker_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->distance_ker, 6, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType_curve_offset_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType_curve_offset_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType::curve_offset_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->curve_offset, 4, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType_noise_prsv_lo_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType_noise_prsv_lo_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType::noise_prsv_lo_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->noise_prsv_lo, 2, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType_noise_prsv_hi_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType_noise_prsv_hi_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType::noise_prsv_hi_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->noise_prsv_hi, 2, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf34_rgn_dataType_radial_gain_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadabf34_rgn_dataType_radial_gain_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf34_rgn_dataType::radial_gain_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_gain, 10, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf34_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadmod_abf34_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_abf34_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadabf34_rgn_dataType(entry, &structure->abf34_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf34_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadmod_abf34_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_abf34_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_abf34_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf34_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadmod_abf34_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_abf34_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_abf34_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_abf34_aec_dataCount, alignment);
        structure->mod_abf34_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_abf34_aec_data = PARAMETER_NEW mod_abf34_aec_dataType[structure->mod_abf34_aec_dataCount];
        }
        if (!result || structure->mod_abf34_aec_data == NULL)
        {
            structure->mod_abf34_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_abf34_aec_dataCount; i++)
        {
            result = Loadmod_abf34_aec_dataType(pointerEntry, &structure->mod_abf34_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf34_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadmod_abf34_drc_gain_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_abf34_drc_gain_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->drc_gain_trigger, alignment);
    result = result && Loadmod_abf34_drc_gain_dataType_drc_gain_dataStruct(entry, &structure->drc_gain_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf34_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadmod_abf34_drc_gain_dataType_drc_gain_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_abf34_drc_gain_dataType::drc_gain_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_abf34_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_abf34_hdr_aec_dataCount, alignment);
        structure->mod_abf34_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_abf34_hdr_aec_data = PARAMETER_NEW mod_abf34_hdr_aec_dataType[structure->mod_abf34_hdr_aec_dataCount];
        }
        if (!result || structure->mod_abf34_hdr_aec_data == NULL)
        {
            structure->mod_abf34_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_abf34_hdr_aec_dataCount; i++)
        {
            result = Loadmod_abf34_hdr_aec_dataType(pointerEntry, &structure->mod_abf34_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf34_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadchromatix_abf34_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_abf34_drc_gain_data from symbol table
    {
        result = entry->Read(&structure->mod_abf34_drc_gain_dataCount, alignment);
        structure->mod_abf34_drc_gain_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_abf34_drc_gain_data = PARAMETER_NEW mod_abf34_drc_gain_dataType[structure->mod_abf34_drc_gain_dataCount];
        }
        if (!result || structure->mod_abf34_drc_gain_data == NULL)
        {
            structure->mod_abf34_drc_gain_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_abf34_drc_gain_dataCount; i++)
        {
            result = Loadmod_abf34_drc_gain_dataType(pointerEntry, &structure->mod_abf34_drc_gain_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf34_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadchromatix_abf34_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->cross_plane_en, alignment);
    result = result && Loadchromatix_abf34_reserveType_radial_anchor_tabStruct(entry, &structure->radial_anchor_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf34_reserveType_radial_anchor_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadchromatix_abf34_reserveType_radial_anchor_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34_reserveType::radial_anchor_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_anchor, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf34Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadchromatix_abf34Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loaddynamic_enable_triggersStruct(entry, &structure->dynamic_enable_triggers, alignment);
    result = result && Loadchromatix_abf34_reserveType(entry, &structure->chromatix_abf34_reserve, alignment);
    result = result && Loadchromatix_abf34_coreType(entry, &structure->chromatix_abf34_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->abf_enable, alignment);
    result = result && entry->Read(&structure->sbpc_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::module_versionStruct* structure,
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
BOOL chromatix_abf34TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::parameter_versionStruct* structure,
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
/// Load control_variablesStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 3; i++)
    {
        structure->control_var_type[i] = (chromatix_abf34Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);
    structure->aec_hdr_control = (ispglobalelements::tuning_control_aec_hdr_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loaddynamic_enable_triggersStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::dynamic_enable_triggersStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loaddynamic_enable_triggersStruct_abf_enableStruct(entry, &structure->abf_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct_abf_enableStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf34TypeClass::Loaddynamic_enable_triggersStruct_abf_enableStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf34Type::dynamic_enable_triggersStruct::abf_enableStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enable, alignment);
    structure->hyst_control_var = (ispglobalelements::control_var_type)entry->ReadEnum(&result, alignment);
    structure->hyst_mode = (ispglobalelements::hyst_direction)entry->ReadEnum(&result, alignment);
    result = result && ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_couplet_type(entry, &structure->hyst_trigger, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf34_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadmod_abf34_hdr_aec_dataType(
    mod_abf34_hdr_aec_dataType* structure)
{
    Unloadmod_abf34_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf34_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadmod_abf34_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_abf34_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_abf34_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf34_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadmod_abf34_drc_gain_dataType(
    mod_abf34_drc_gain_dataType* structure)
{
    Unloadmod_abf34_drc_gain_dataType_drc_gain_dataStruct(&structure->drc_gain_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf34_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadmod_abf34_drc_gain_dataType_drc_gain_dataStruct(
    mod_abf34_drc_gain_dataType::drc_gain_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_abf34_hdr_aec_dataCount; i++)
    {
        Unloadmod_abf34_hdr_aec_dataType(&structure->mod_abf34_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_abf34_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_abf34_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadchromatix_abf34_coreType(
    chromatix_abf34_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_abf34_drc_gain_dataCount; i++)
    {
        Unloadmod_abf34_drc_gain_dataType(&structure->mod_abf34_drc_gain_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_abf34_drc_gain_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_abf34Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadchromatix_abf34Type(
    chromatix_abf34Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_abf34_coreType(&structure->chromatix_abf34_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf34TypeClass::Unloadparameter_versionStruct(
    chromatix_abf34Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_abf34TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_abf34TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_abf34TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_abf34Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


ABF_3_4_0_NAMESPACE_END