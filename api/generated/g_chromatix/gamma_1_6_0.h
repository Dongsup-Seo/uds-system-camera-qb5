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
/// @file  gamma_1_6_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GAMMA_1_6_0_H
#define GAMMA_1_6_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define GAMMA_1_6_0_NAMESPACE_BEGIN namespace gamma_1_6_0 {
#define GAMMA_1_6_0_NAMESPACE_END }

GAMMA_1_6_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// gamma16_rgn_dataType
///
/// Tuning Level:  must_tune
/// Description:   Gamma table per channel
/// Type:          int
/// Default Value: 0 64 108 144 176 205 232 258 282 304 326 347 367 386 405 423 441 458 475 491 507 523 538 553 568 583 597 611 625 638 651 665 678 690 703 715 728 740 752 764 775 787 798 810 821 832 843 854 865 875 886 896 907 917 927 937 947 957 967 977 987 996 1006 1015 1023
/// Range:         [0,1023]
/// Bit Depth:     (16+2*b)sQ0
/// Length:        65
/// Conversion:    no conversion needed
/// Notes:         none
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct gamma16_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// table - Array
    ///
    /// Tuning Level:  must_tune
    /// Default Value: 0 64 108 144 176 205 232 258 282 304 326 347 367 386 405 423 441 458 475 491 507 523 538 553 568 583 597 611 625 638 651 665 678 690 703 715 728 740 752 764 775 787 798 810 821 832 843 854 865 875 886 896 907 917 927 937 947 957 967 977 987 996 1006 1015 1023
    /// Length:        65
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT table[65];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_gamma16_channel_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_gamma16_channel_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// channel_type
    /// Comments:      Channel type selection for R/G/B/All
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::channel_rgb_type     channel_type;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// gamma16_rgn_data
    ///
    /// Tuning Level:  must_tune
    /// Description:   Gamma table per channel
    /// Type:          int
    /// Default Value: 0 64 108 144 176 205 232 258 282 304 326 347 367 386 405 423 441 458 475 491 507 523 538 553 568 583 597 611 625 638 651 665 678 690 703 715 728 740 752 764 775 787 798 810 821 832 843 854 865 875 886 896 907 917 927 937 947 957 967 977 987 996 1006 1015 1023
    /// Range:         [0,1023]
    /// Bit Depth:     (16+2*b)sQ0
    /// Length:        65
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    gamma16_rgn_dataType gamma16_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_gamma16_cct_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_gamma16_cct_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// cct_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type cct_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// cct_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct cct_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_gamma16_channel_data - Array
        /// Min Length:    1
        /// Max Length:    3
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                        mod_gamma16_channel_dataCount;
        UINT32                        mod_gamma16_channel_dataID;
        mod_gamma16_channel_dataType* mod_gamma16_channel_data;
    } cct_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_gamma16_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_gamma16_aec_dataType
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
        /// mod_gamma16_cct_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                    mod_gamma16_cct_dataCount;
        UINT32                    mod_gamma16_cct_dataID;
        mod_gamma16_cct_dataType* mod_gamma16_cct_data;
    } aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_gamma16_led_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_gamma16_led_dataType
{
    ispglobalelements::trigger_pt_type_led_idx led_idx_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// led_idx_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct led_idx_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_gamma16_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                    mod_gamma16_aec_dataCount;
        UINT32                    mod_gamma16_aec_dataID;
        mod_gamma16_aec_dataType* mod_gamma16_aec_data;
    } led_idx_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_gamma16_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_gamma16_hdr_aec_dataType
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
        /// mod_gamma16_led_idx_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                    mod_gamma16_led_idx_dataCount;
        UINT32                    mod_gamma16_led_idx_dataID;
        mod_gamma16_led_dataType* mod_gamma16_led_idx_data;
    } hdr_aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_gamma16_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_gamma16_drc_gain_dataType
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
        /// mod_gamma16_hdr_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                        mod_gamma16_hdr_aec_dataCount;
        UINT32                        mod_gamma16_hdr_aec_dataID;
        mod_gamma16_hdr_aec_dataType* mod_gamma16_hdr_aec_data;
    } drc_gain_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_gamma16_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_gamma16_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_gamma16_drc_gain_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                         mod_gamma16_drc_gain_dataCount;
    UINT32                         mod_gamma16_drc_gain_dataID;
    mod_gamma16_drc_gain_dataType* mod_gamma16_drc_gain_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_gamma16Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_gamma16Type
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
        globalelements::enable_flag_type gamma_enable;
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
    /// Default Value: control_drc_gain, control_aec_exp_sensitivity_ratio, control_led_idx, control_lux_idx, control_cct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_drc_gain, control_aec_exp_sensitivity_ratio, control_led_idx, control_lux_idx, control_cct
        /// Length:        5
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_lux_idx                   = 0,
            control_gain                      = 1,
            control_drc_gain                  = 2,
            control_exp_time_ratio            = 3,
            control_aec_exp_sensitivity_ratio = 4,
            control_exp_gain_ratio            = 5,
            control_cct                       = 6,
            control_led_idx                   = 9
        } control_var_type[5];
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
    /// private_information
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct private_informationStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// led_sensitivity_trigger
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ispglobalelements::trigger_pt_type led_sensitivity_trigger;
    } private_information;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_gamma16_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_gamma16_coreType chromatix_gamma16_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_gamma16TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_gamma16TypeClass : public ParameterModule, public chromatix_gamma16Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 1;
    static const UINT16 MINOR = 6;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_gamma16TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_gamma16TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_gamma16TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load gamma16_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadgamma16_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        gamma16_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_channel_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_channel_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_channel_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_cct_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_cct_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_cct_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_cct_dataType_cct_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_cct_dataType_cct_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_cct_dataType::cct_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_aec_dataType_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_aec_dataType_aec_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_aec_dataType::aec_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_led_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_led_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_led_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_led_dataType_led_idx_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_led_dataType_led_idx_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_led_dataType::led_idx_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_hdr_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_hdr_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_hdr_aec_dataType::hdr_aec_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_drc_gain_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_drc_gain_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_drc_gain_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_gamma16_drc_gain_dataType_drc_gain_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_gamma16_drc_gain_dataType_drc_gain_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_gamma16_drc_gain_dataType::drc_gain_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_gamma16_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_gamma16_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_gamma16Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_gamma16Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_methodStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_methodStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type::control_methodStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load private_informationStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadprivate_informationStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_gamma16Type::private_informationStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_cct_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_cct_dataType(
        mod_gamma16_cct_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_cct_dataType_cct_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_cct_dataType_cct_dataStruct(
        mod_gamma16_cct_dataType::cct_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_aec_dataType(
        mod_gamma16_aec_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_aec_dataType_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_aec_dataType_aec_dataStruct(
        mod_gamma16_aec_dataType::aec_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_led_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_led_dataType(
        mod_gamma16_led_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_led_dataType_led_idx_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_led_dataType_led_idx_dataStruct(
        mod_gamma16_led_dataType::led_idx_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_hdr_aec_dataType(
        mod_gamma16_hdr_aec_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct(
        mod_gamma16_hdr_aec_dataType::hdr_aec_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_drc_gain_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_drc_gain_dataType(
        mod_gamma16_drc_gain_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_gamma16_drc_gain_dataType_drc_gain_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_gamma16_drc_gain_dataType_drc_gain_dataStruct(
        mod_gamma16_drc_gain_dataType::drc_gain_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_gamma16_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_gamma16_coreType(
        chromatix_gamma16_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_gamma16Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_gamma16Type(
        chromatix_gamma16Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_gamma16Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_gamma16TypeClass

GAMMA_1_6_0_NAMESPACE_END
#endif // GAMMA_1_6_0_H

