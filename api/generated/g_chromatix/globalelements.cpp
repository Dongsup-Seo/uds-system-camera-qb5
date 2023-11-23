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
/// @file  globalelements.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "globalelements.h"
#include "parametersetmanager.h"

GLOBALELEMENTS_NAMESPACE_BEGIN


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load trigger_pt_type_aec
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL globalelementsClass::Loadtrigger_pt_type_aec(
    ParameterFileSymbolTableEntry* entry,
    trigger_pt_type_aec* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->lux_idx_start, alignment);
    result = result && entry->Read(&structure->lux_idx_end, alignment);
    result = result && entry->Read(&structure->gain_start, alignment);
    result = result && entry->Read(&structure->gain_end, alignment);

    return result;
}

GLOBALELEMENTS_NAMESPACE_END