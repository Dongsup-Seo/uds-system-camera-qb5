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
/// @file  eis_1_2_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "eis_1_2_0.h"
#include "parametersetmanager.h"

EIS_1_2_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_eis12TypeClass::chromatix_eis12TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(chromatix_eis12_reserve);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_eis12TypeClass::chromatix_eis12TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(chromatix_eis12_reserve);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_eis12TypeClass::~chromatix_eis12TypeClass()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_eis12TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "eis12_sw")) == 0)
    {
        name = "eis12_sw";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadchromatix_eis12_reserveType_topStruct(entry, &structure->top, alignment);
    result = result && Loadchromatix_eis12_reserveType_generalStruct(entry, &structure->general, alignment);
    result = result && Loadchromatix_eis12_reserveType_timingStruct(entry, &structure->timing, alignment);
    result = result && Loadchromatix_eis12_reserveType_blur_maskingStruct(entry, &structure->blur_masking, alignment);
    result = result && Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct(entry, &structure->lens_distortion_correction, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_topStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_topStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::topStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->minimal_total_margin, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_fhd_30, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_fhd_60, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_fhd_120, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_4k_30, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_4k_60, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_4k_120, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_8k_30, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_8k_60, alignment);
    result = result && entry->Read(&structure->requested_total_margins_y_8k_120, alignment);
    result = result && entry->Read(&structure->future_buffer_size_fhd_30, alignment);
    result = result && entry->Read(&structure->future_buffer_size_fhd_60, alignment);
    result = result && entry->Read(&structure->future_buffer_size_fhd_120, alignment);
    result = result && entry->Read(&structure->future_buffer_size_4k_30, alignment);
    result = result && entry->Read(&structure->future_buffer_size_4k_60, alignment);
    result = result && entry->Read(&structure->future_buffer_size_4k_120, alignment);
    result = result && entry->Read(&structure->future_buffer_size_8k_30, alignment);
    result = result && entry->Read(&structure->future_buffer_size_8k_60, alignment);
    result = result && entry->Read(&structure->future_buffer_size_8k_120, alignment);
    result = result && entry->Read(&structure->gyro_frequency, alignment);
    result = result && entry->Read(&structure->ois_frequency, alignment);
    result = result && entry->Read(&structure->acc_frequency, alignment);
    result = result && entry->Read(&structure->mag_frequency, alignment);
    result = result && Loadchromatix_eis12_reserveType_topStruct_res_lut_param_0_tabStruct(entry, &structure->res_lut_param_0_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_topStruct_res_lut_param_0_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_topStruct_res_lut_param_0_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::topStruct::res_lut_param_0_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->res_lut_param_0, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_generalStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_generalStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::generalStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->focal_length, alignment);
    result = result && entry->Read(&structure->gyro_noise_floor, alignment);
    result = result && entry->Read(&structure->ois_noise_floor, alignment);
    result = result && entry->Read(&structure->acc_noise_floor, alignment);
    result = result && entry->Read(&structure->mag_noise_floor, alignment);
    result = result && entry->Read(&structure->output_grid_precision, alignment);
    result = result && entry->Read(&structure->res_param_1, alignment);
    result = result && entry->Read(&structure->res_param_2, alignment);
    result = result && entry->Read(&structure->res_param_3, alignment);
    result = result && entry->Read(&structure->res_param_4, alignment);
    result = result && entry->Read(&structure->res_param_5, alignment);
    result = result && entry->Read(&structure->res_param_6, alignment);
    result = result && entry->Read(&structure->res_param_7, alignment);
    result = result && entry->Read(&structure->res_param_8, alignment);
    result = result && entry->Read(&structure->res_param_9, alignment);
    result = result && entry->Read(&structure->res_param_10, alignment);
    result = result && Loadchromatix_eis12_reserveType_generalStruct_res_lut_param_1_tabStruct(entry, &structure->res_lut_param_1_tab, alignment);
    result = result && Loadchromatix_eis12_reserveType_generalStruct_res_lut_param_2_tabStruct(entry, &structure->res_lut_param_2_tab, alignment);
    result = result && Loadchromatix_eis12_reserveType_generalStruct_res_lut_param_3_tabStruct(entry, &structure->res_lut_param_3_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_generalStruct_res_lut_param_1_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_generalStruct_res_lut_param_1_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::generalStruct::res_lut_param_1_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->res_lut_param_1, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_generalStruct_res_lut_param_2_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_generalStruct_res_lut_param_2_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::generalStruct::res_lut_param_2_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->res_lut_param_2, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_generalStruct_res_lut_param_3_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_generalStruct_res_lut_param_3_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::generalStruct::res_lut_param_3_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->res_lut_param_3, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_timingStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_timingStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::timingStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->s3d_offset, alignment);
    result = result && entry->Read(&structure->ois_offset, alignment);
    result = result && entry->Read(&structure->acc_offset, alignment);
    result = result && entry->Read(&structure->mag_offset, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_blur_maskingStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_blur_maskingStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::blur_maskingStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enable, alignment);
    result = result && entry->Read(&structure->min_strength, alignment);
    result = result && entry->Read(&structure->exposure_time_th, alignment);
    result = result && entry->Read(&structure->start_decrease_at_blur, alignment);
    result = result && entry->Read(&structure->end_decrease_at_blur, alignment);
    result = result && entry->Read(&structure->pan_min_threshold, alignment);
    result = result && entry->Read(&structure->pan_max_threshold, alignment);
    result = result && entry->Read(&structure->blur_masking_res1, alignment);
    result = result && entry->Read(&structure->blur_masking_res2, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_lens_distortion_correctionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::lens_distortion_correctionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->ldc_grid_source, alignment);
    result = result && entry->Read(&structure->ldc_grid_enable, alignment);
    result = result && entry->Read(&structure->ldc_calib_domain, alignment);
    result = result && Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_distorted_input_to_undistorted_ldc_grid_x_tabStruct(entry, &structure->distorted_input_to_undistorted_ldc_grid_x_tab, alignment);
    result = result && Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_distorted_input_to_undistorted_ldc_grid_y_tabStruct(entry, &structure->distorted_input_to_undistorted_ldc_grid_y_tab, alignment);
    result = result && entry->Read(&structure->distorted_input_to_undistorted_ldc_grid_geometry, alignment);
    result = result && Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_undistorted_to_distorted_input_ldc_grid_x_tabStruct(entry, &structure->undistorted_to_distorted_input_ldc_grid_x_tab, alignment);
    result = result && Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_undistorted_to_distorted_input_ldc_grid_y_tabStruct(entry, &structure->undistorted_to_distorted_input_ldc_grid_y_tab, alignment);
    result = result && entry->Read(&structure->undistorted_to_distorted_input_ldc_grid_geometry, alignment);
    result = result && entry->Read(&structure->ldc_model_type, alignment);
    result = result && Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_model_parameters_tabStruct(entry, &structure->model_parameters_tab, alignment);
    result = result && entry->Read(&structure->focal_length_x, alignment);
    result = result && entry->Read(&structure->focal_length_y, alignment);
    result = result && entry->Read(&structure->optical_center_x, alignment);
    result = result && entry->Read(&structure->optical_center_y, alignment);
    result = result && entry->Read(&structure->image_size_distorted_x, alignment);
    result = result && entry->Read(&structure->image_size_distorted_y, alignment);
    result = result && entry->Read(&structure->image_size_undistorted_x, alignment);
    result = result && entry->Read(&structure->image_size_undistorted_y, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_lens_distortion_correctionStruct_distorted_input_to_undistorted_ldc_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_distorted_input_to_undistorted_ldc_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::lens_distortion_correctionStruct::distorted_input_to_undistorted_ldc_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->distorted_input_to_undistorted_ldc_grid_x, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_lens_distortion_correctionStruct_distorted_input_to_undistorted_ldc_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_distorted_input_to_undistorted_ldc_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::lens_distortion_correctionStruct::distorted_input_to_undistorted_ldc_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->distorted_input_to_undistorted_ldc_grid_y, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_lens_distortion_correctionStruct_undistorted_to_distorted_input_ldc_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_undistorted_to_distorted_input_ldc_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::lens_distortion_correctionStruct::undistorted_to_distorted_input_ldc_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->undistorted_to_distorted_input_ldc_grid_x, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_lens_distortion_correctionStruct_undistorted_to_distorted_input_ldc_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_undistorted_to_distorted_input_ldc_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::lens_distortion_correctionStruct::undistorted_to_distorted_input_ldc_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->undistorted_to_distorted_input_ldc_grid_y, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12_reserveType_lens_distortion_correctionStruct_model_parameters_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12_reserveType_lens_distortion_correctionStruct_model_parameters_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12_reserveType::lens_distortion_correctionStruct::model_parameters_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->model_parameters, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_eis12Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadchromatix_eis12Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadchromatix_eis12_reserveType(entry, &structure->chromatix_eis12_reserve, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_eis12TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_eis12Type::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_eis12TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_eis12TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_eis12TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_eis12Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


EIS_1_2_0_NAMESPACE_END