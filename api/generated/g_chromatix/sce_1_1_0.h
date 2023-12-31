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
/// @file  sce_1_1_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SCE_1_1_0_H
#define SCE_1_1_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define SCE_1_1_0_NAMESPACE_BEGIN namespace sce_1_1_0 {
#define SCE_1_1_0_NAMESPACE_END }

SCE_1_1_0_NAMESPACE_BEGIN
typedef INT32 traingle[2];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// cr_cb_triangle
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct cr_cb_triangle
{
    INT32 point1[2];
    INT32 point2[2];
    INT32 point3[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// cr_cb_triangle_set
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct cr_cb_triangle_set
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// traingle1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle traingle1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// traingle2
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle traingle2;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// traingle3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle traingle3;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// traingle4
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle traingle4;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// traingle5
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle traingle5;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// sce11_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct sce11_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ori_triangle
    ///
    /// Tuning Level:  often_tune
    /// Description:   Three (Cr,Cb) points form a triangle. It changes color from ori triangular area to target triangular
    ///                area.
    /// Default Value: {40, -30, 17, -3, 10, -20}, {40, -30, 70, -25, 17, -3}, {40, -30, 65, -55, 70, -25}, {40, -30, 45, -90, 65, -55}, {40, -30, 10, -20, 45, -90}
    /// Range:         [-128, 127]
    /// Bit Depth:     (8+e)sQ0
    /// Length:        30
    /// Conversion:    no conversion needed
    /// Notes:         Special effect default value (ori == target): i. acc_color_green = {{-64, -64, -10, 0, -128, 0}, {-64,
    ///                -64, 0, -10, -10, 0}, {-64, -64, 0, -128, 0, -10}, {-64, -64, -128, -128, 0, -128}, {-64, -64, -128, 0,
    ///                -128, -128}}; ii. acc_color_blue = {{0, 127, -128, 127, -64, 64}, {-64, 64, -128, 127, -128, 0}, {-64,
    ///                64, -128, 0, 0, 0}, {-64, 64, 0, 0, 0, 64}, {0, 127, -64, 64, 0, 64}}; iii. acc_color_orange = {{127, 0,
    ///                0, 0, 64, -64}, {0, 0, 0, -128, 64, -64}, {64, -64, 0, -128, 127, -128}, {127, -64, 64, -64, 127, -128},
    ///                {127, -0, 64, -64, 127, -64}}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle_set ori_triangle;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// target_triangle
    ///
    /// Tuning Level:  often_tune
    /// Description:   Three (Cr,Cb) points form a triangle. It changes color from ori triangular area to target triangular
    ///                area.
    /// Default Value: {40, -30, 17, -3, 10, -20}, {40, -30, 70, -25, 17, -3}, {40, -30, 65, -55, 70, -25}, {40, -30, 45, -90, 65, -55}, {40, -30, 10, -20, 45, -90}
    /// Range:         [-128, 127]
    /// Bit Depth:     (8+e)sQ0
    /// Length:        30
    /// Conversion:    no conversion needed
    /// Notes:         Special effect default value (ori == target): i. acc_color_green = {{-64, -64, -10, 0, -128, 0}, {-64,
    ///                -64, 0, -10, -10, 0}, {-64, -64, 0, -128, 0, -10}, {-64, -64, -128, -128, 0, -128}, {-64, -64, -128, 0,
    ///                -128, -128}}; ii. acc_color_blue = {{0, 127, -128, 127, -64, 64}, {-64, 64, -128, 127, -128, 0}, {-64,
    ///                64, -128, 0, 0, 0}, {-64, 64, 0, 0, 0, 64}, {0, 127, -64, 64, 0, 64}}; iii. acc_color_orange = {{127, 0,
    ///                0, 0, 64, -64}, {0, 0, 0, -128, 64, -64}, {64, -64, 0, -128, 127, -128}, {127, -64, 64, -64, 127, -128},
    ///                {127, -0, 64, -64, 127, -64}}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cr_cb_triangle_set target_triangle;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// shift_vector_cb
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   shift vector for Cb.
    /// Type:          float
    /// Default Value: -0.640000
    /// Range:         [0.0,1.0]
    /// Bit Depth:     0uQ0
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT              shift_vector_cb;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// shift_vector_cr
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   shift vector for Cr.
    /// Type:          float
    /// Default Value: 0.768000
    /// Range:         [0.0,1.0]
    /// Bit Depth:     0uQ0
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT              shift_vector_cr;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_sce11_cct_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_sce11_cct_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// cct_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type    cct_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// sce11_rgn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sce11_rgn_dataType sce11_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_sce11_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_sce11_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    globalelements::trigger_pt_type_aec aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// aec_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct aec_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_sce11_cct_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                  mod_sce11_cct_dataCount;
        UINT32                  mod_sce11_cct_dataID;
        mod_sce11_cct_dataType* mod_sce11_cct_data;
    } aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_sce11_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_sce11_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_sce11_aec_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                  mod_sce11_aec_dataCount;
    UINT32                  mod_sce11_aec_dataID;
    mod_sce11_aec_dataType* mod_sce11_aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_sce11_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_sce11_reserveType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// a
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   2x3 affine transform matrix for colors outside region. Usually used for special effect.
    /// Type:          float
    /// Default Value: 1.0
    /// Range:         [-2048,2047]
    /// Bit Depth:     12sQ0
    /// Conversion:    no conversion needed
    /// Notes:         cr' = [ a b c] cr; cb' = [d e f] cb; 1 = [0 0 1] 1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT a;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// b
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   2x3 affine transform matrix for colors outside region. Usually used for special effect.
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [-2048,2047]
    /// Bit Depth:     12sQ0
    /// Conversion:    no conversion needed
    /// Notes:         cr' = [ a b c] cr; cb' = [d e f] cb; 1 = [0 0 1] 1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT b;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// c
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   2x3 affine transform matrix for colors outside region. Usually used for special effect.
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [-2048,2047]
    /// Bit Depth:     12sQ0
    /// Conversion:    no conversion needed
    /// Notes:         cr' = [ a b c] cr; cb' = [d e f] cb; 1 = [0 0 1] 1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT c;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// d
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   2x3 affine transform matrix for colors outside region. Usually used for special effect.
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [-2048,2047]
    /// Bit Depth:     12sQ0
    /// Conversion:    no conversion needed
    /// Notes:         cr' = [ a b c] cr; cb' = [d e f] cb; 1 = [0 0 1] 1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT d;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// e
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   2x3 affine transform matrix for colors outside region. Usually used for special effect.
    /// Type:          float
    /// Default Value: 1.0
    /// Range:         [-2048,2047]
    /// Bit Depth:     12sQ0
    /// Conversion:    no conversion needed
    /// Notes:         cr' = [ a b c] cr; cb' = [d e f] cb; 1 = [0 0 1] 1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT e;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// f
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   2x3 affine transform matrix for colors outside region. Usually used for special effect.
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [-2048,2047]
    /// Bit Depth:     12sQ0
    /// Conversion:    no conversion needed
    /// Notes:         cr' = [ a b c] cr; cb' = [d e f] cb; 1 = [0 0 1] 1
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT f;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_sce11Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_sce11Type
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
        globalelements::enable_flag_type sce_enable;
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
    /// Default Value: control_lux_idx, control_cct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_lux_idx, control_cct
        /// Length:        2
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_lux_idx = 0,
            control_gain    = 1,
            control_cct     = 6
        } control_var_type[2];
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
    /// chromatix_sce11_reserve
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_sce11_reserveType chromatix_sce11_reserve;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_sce11_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_sce11_coreType    chromatix_sce11_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_sce11TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_sce11TypeClass : public ParameterModule, public chromatix_sce11Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 1;
    static const UINT16 MINOR = 1;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_sce11TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_sce11TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_sce11TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cr_cb_triangle
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcr_cb_triangle(
        ParameterFileSymbolTableEntry* entry,
        cr_cb_triangle* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load cr_cb_triangle_set
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcr_cb_triangle_set(
        ParameterFileSymbolTableEntry* entry,
        cr_cb_triangle_set* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load sce11_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadsce11_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        sce11_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_sce11_cct_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_sce11_cct_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_sce11_cct_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_sce11_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_sce11_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_sce11_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_sce11_aec_dataType_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_sce11_aec_dataType_aec_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_sce11_aec_dataType::aec_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_sce11_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_sce11_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_sce11_reserveType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_sce11_reserveType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11_reserveType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_sce11Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_sce11Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_methodStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_methodStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_sce11Type::control_methodStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_sce11_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_sce11_aec_dataType(
        mod_sce11_aec_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_sce11_aec_dataType_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_sce11_aec_dataType_aec_dataStruct(
        mod_sce11_aec_dataType::aec_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_sce11_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_sce11_coreType(
        chromatix_sce11_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_sce11Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_sce11Type(
        chromatix_sce11Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_sce11Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_sce11TypeClass

SCE_1_1_0_NAMESPACE_END
#endif // SCE_1_1_0_H

