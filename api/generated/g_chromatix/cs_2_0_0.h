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
/// @file  cs_2_0_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CS_2_0_0_H
#define CS_2_0_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define CS_2_0_0_NAMESPACE_BEGIN namespace cs_2_0_0 {
#define CS_2_0_0_NAMESPACE_END }

CS_2_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// cs20_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct cs20_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// knee_point_lut_tab
    ///
    /// Tuning Level:  often_tune
    /// Description:   luma knee point LUT. Define the luma points users want to control
    /// Type:          float
    /// Default Value: 0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 256
    /// Range:         [0,256]
    /// Bit Depth:     8uQ0
    /// Length:        16
    /// Conversion:    i. cs_luma_threshold1 to knee_point_lut[1]. ii. cs_luma_threshold2 to knee_point_lut[2]. iii. cs_luma_threshold3 to knee_point_lut[13]. iv. cs_luma_threshold4 to knee_point_lut[14].
    /// Notes:         i. LUTs are always programmed in ascending order. ii. First LUT is always 0. iii. Last LUT is always Max.
    ///                iv. No two entries for the LUT can be equal. v. must satisfy (knee_point_lut[i+1] -
    ///                knee_point_lut[i])>=2^(luma_q+1). By default, luma_q=1, so must have (knee_point_lut[i+1] -
    ///                knee_point_lut[i])>=1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct knee_point_lut_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// knee_point_lut - Array
        ///
        /// Tuning Level:  often_tune
        /// Default Value: 0 17 34 51 68 85 102 119 136 153 170 187 204 221 238 256
        /// Length:        16
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT knee_point_lut[16];
    } knee_point_lut_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// y_weight_lut_tab
    ///
    /// Tuning Level:  must_tune
    /// Description:   define luma weight for chroma suppression at luma knee points. Higher value makes less suppression and
    ///                lower value makes more suppression
    /// Type:          float
    /// Default Value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    /// Range:         [0.0,1.0]
    /// Bit Depth:     11uQ10
    /// Length:        16
    /// Conversion:    i. y_weight_lut[0] = y_weight_lut[0] = 0.0f. ii. y_weight_lut[2 ... 13] = 1.0f.  iii. y_weight_lut[14] = y_weight_lut[15] = 0.0f.
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct y_weight_lut_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// y_weight_lut - Array
        ///
        /// Tuning Level:  must_tune
        /// Default Value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
        /// Length:        16
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT y_weight_lut[16];
    } y_weight_lut_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// c_thr1_lut_tab
    ///
    /// Tuning Level:  must_tune
    /// Description:   Define chroma threshold1. Chroma value smaller than this threshold will be suppressed with y_weight.
    ///                Higher value makes more suppression and lower value makes less suppression
    /// Type:          float
    /// Default Value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    /// Range:         [0,128]
    /// Bit Depth:     7uQ0
    /// Length:        16
    /// Conversion:    i. cs_chroma_threshold1 to c_thr1_lut[0 .. 15] all the same
    /// Notes:         related with c_thr2_lut
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct c_thr1_lut_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// c_thr1_lut - Array
        ///
        /// Tuning Level:  must_tune
        /// Default Value: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
        /// Length:        16
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT c_thr1_lut[16];
    } c_thr1_lut_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// c_thr2_lut_tab
    ///
    /// Tuning Level:  must_tune
    /// Description:   Define chroma threshold2. Chroma value bigger than this threshold will not be suppressed. Higher value
    ///                makes more suppression and lower value makes less suppression
    /// Type:          float
    /// Default Value: 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
    /// Range:         [1,128]
    /// Bit Depth:     7uQ0
    /// Length:        16
    /// Conversion:    i. cs_chroma_threshold2 to c_thr2_lut[0 .. 15] all the same
    /// Notes:         i. This value must be bigger then c_thr1_lut. ii. must satisfy (c_th2_lut[i] -
    ///                c_th1_lut[i])>=2^(chroma_q+1). By default, chroma_q=1, so must have (c_th2_lut[i] - c_th1_lut[i])>=1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct c_thr2_lut_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// c_thr2_lut - Array
        ///
        /// Tuning Level:  must_tune
        /// Default Value: 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
        /// Length:        16
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT c_thr2_lut[16];
    } c_thr2_lut_tab;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_cs20_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_cs20_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    globalelements::trigger_pt_type_aec aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// cs20_rgn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cs20_rgn_dataType   cs20_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_cs20_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_cs20_hdr_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hdr_aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type_aec_hdr hdr_aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hdr_aec_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct hdr_aec_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_cs20_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                 mod_cs20_aec_dataCount;
        UINT32                 mod_cs20_aec_dataID;
        mod_cs20_aec_dataType* mod_cs20_aec_data;
    } hdr_aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_cs20_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_cs20_drc_gain_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// drc_gain_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type drc_gain_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// drc_gain_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct drc_gain_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_cs20_hdr_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                     mod_cs20_hdr_aec_dataCount;
        UINT32                     mod_cs20_hdr_aec_dataID;
        mod_cs20_hdr_aec_dataType* mod_cs20_hdr_aec_data;
    } drc_gain_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_cs20_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_cs20_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_cs20_drc_gain_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                      mod_cs20_drc_gain_dataCount;
    UINT32                      mod_cs20_drc_gain_dataID;
    mod_cs20_drc_gain_dataType* mod_cs20_drc_gain_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_cs20_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_cs20_reserveType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// luma_q
    ///
    /// Tuning Level:  never_tune
    /// Description:   Q factor to define constraints on knee_point_lut
    /// Type:          uint
    /// Default Value: 1
    /// Range:         [0,3]
    /// Bit Depth:     2uQ0
    /// Conversion:    no conversion needed
    /// Notes:         knee_point_lut must satisfy (knee_point_lut[i+1] - knee_point_lut[i])>=2^(luma_q+1). By default,
    ///                luma_q=1, so must have (knee_point_lut[i+1] - knee_point_lut[i])>=1.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 luma_q;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chroma_q
    ///
    /// Tuning Level:  never_tune
    /// Description:   Q factor to define constraints on c_thr1_lut and c_thr2_lut
    /// Type:          uint
    /// Default Value: 1
    /// Range:         [0,3]
    /// Bit Depth:     2uQ0
    /// Conversion:    no conversion needed
    /// Notes:         must satisfy (c_th2_lut[i] - c_th1_lut[i])>=2^(chroma_q+1). By default, chroma_q=1, so must have
    ///                (c_th2_lut[i] - c_th1_lut[i])>=1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 chroma_q;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_cs20Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_cs20Type
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enable_section
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct enable_sectionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        globalelements::enable_flag_type chroma_suppression_enable;
    } enable_section;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// module_version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct module_versionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        INT32 major_revision;
        INT32 minor_revision;
        INT32 incr_revision;
    } module_version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// parameter_version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct parameter_versionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        CHAR* revision;
    } parameter_version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// control_variables
    ///
    /// Default Value: control_drc_gain, control_aec_exp_sensitivity_ratio, control_lux_idx
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_drc_gain, control_aec_exp_sensitivity_ratio, control_lux_idx
        /// Length:        3
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_lux_idx                   = 0,
            control_gain                      = 1,
            control_drc_gain                  = 2,
            control_exp_time_ratio            = 3,
            control_aec_exp_sensitivity_ratio = 4,
            control_exp_gain_ratio            = 5
        } control_var_type[3];
    } control_variables;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// control_method
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_methodStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// aec_exp_control
        /// Default Value: control_lux_idx
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ispglobalelements::tuning_control_aec_type     aec_exp_control;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// aec_hdr_control
        /// Default Value: control_aec_exp_sensitivity_ratio
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ispglobalelements::tuning_control_aec_hdr_type aec_hdr_control;
    } control_method;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_cs20_reserve
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_cs20_reserveType chromatix_cs20_reserve;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_cs20_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_cs20_coreType    chromatix_cs20_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_cs20TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_cs20TypeClass : public ParameterModule, public chromatix_cs20Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 2;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_cs20TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_cs20TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_cs20TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cs20_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcs20_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        cs20_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cs20_rgn_dataType_knee_point_lut_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcs20_rgn_dataType_knee_point_lut_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        cs20_rgn_dataType::knee_point_lut_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cs20_rgn_dataType_y_weight_lut_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcs20_rgn_dataType_y_weight_lut_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        cs20_rgn_dataType::y_weight_lut_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cs20_rgn_dataType_c_thr1_lut_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcs20_rgn_dataType_c_thr1_lut_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        cs20_rgn_dataType::c_thr1_lut_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cs20_rgn_dataType_c_thr2_lut_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcs20_rgn_dataType_c_thr2_lut_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        cs20_rgn_dataType::c_thr2_lut_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_cs20_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_cs20_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_cs20_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_cs20_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_cs20_hdr_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_cs20_hdr_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_cs20_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_cs20_hdr_aec_dataType_hdr_aec_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_cs20_hdr_aec_dataType::hdr_aec_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_cs20_drc_gain_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_cs20_drc_gain_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_cs20_drc_gain_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_cs20_drc_gain_dataType_drc_gain_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_cs20_drc_gain_dataType_drc_gain_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_cs20_drc_gain_dataType::drc_gain_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_cs20_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_cs20_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_cs20_reserveType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_cs20_reserveType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20_reserveType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_cs20Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_cs20Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_methodStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_methodStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_cs20Type::control_methodStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_cs20_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_cs20_hdr_aec_dataType(
        mod_cs20_hdr_aec_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_cs20_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_cs20_hdr_aec_dataType_hdr_aec_dataStruct(
        mod_cs20_hdr_aec_dataType::hdr_aec_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_cs20_drc_gain_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_cs20_drc_gain_dataType(
        mod_cs20_drc_gain_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_cs20_drc_gain_dataType_drc_gain_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_cs20_drc_gain_dataType_drc_gain_dataStruct(
        mod_cs20_drc_gain_dataType::drc_gain_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_cs20_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_cs20_coreType(
        chromatix_cs20_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_cs20Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_cs20Type(
        chromatix_cs20Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_cs20Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_cs20TypeClass

CS_2_0_0_NAMESPACE_END
#endif // CS_2_0_0_H

