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
/// @file  tintless_2_0_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TINTLESS_2_0_0_H
#define TINTLESS_2_0_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define TINTLESS_2_0_0_NAMESPACE_BEGIN namespace tintless_2_0_0 {
#define TINTLESS_2_0_0_NAMESPACE_END }

TINTLESS_2_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// tintless20_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct tintless20_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// tintless_threshold_tab
    ///
    /// Tuning Level:  must_tune
    /// Description:   Determine how much color shading will be treated as tint based on intensity.
    /// Type:          uint
    /// Default Value: 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
    /// Range:         [0,10]
    /// Bit Depth:     4uQ0
    /// Length:        16
    /// Conversion:    no conversion needed
    /// Notes:         Higher threshold will correct more color shading, but will also over correct actual color in scene.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct tintless_threshold_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// tintless_threshold - Array
        ///
        /// Tuning Level:  must_tune
        /// Default Value: 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
        /// Length:        16
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT tintless_threshold[16];
    } tintless_threshold_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// tintless_high_accuracy_mode
    ///
    /// Tuning Level:  often_tune
    /// Description:   Enable this to alleviate tint in shadow regions. A noisy sensor could use a higher value.
    /// Type:          uint
    /// Default Value: 8
    /// Range:         [0,255]
    /// Bit Depth:     8uQ0
    /// Conversion:    no conversion needed
    /// Notes:         Can be used to run tintless on a noisy sensor.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                  tintless_high_accuracy_mode;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// tintless_update_delay
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Controls how frequently the color lens shade correction is updated.
    /// Type:          uint
    /// Default Value: 3
    /// Range:         [1,30]
    /// Bit Depth:     5uQ0
    /// Conversion:    no conversion needed
    /// Notes:         A lower value means more frequent updates. The default value has the effect of updating the correction
    ///                table every 3rd preview frame
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                  tintless_update_delay;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// tintless_trace_percentage
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Tracing percentage of tintless to apply rolloff table.
    /// Type:          float
    /// Default Value: 0.4
    /// Range:         [0.0,1.0]
    /// Bit Depth:     8uQ0
    /// Conversion:    no conversion needed
    /// Notes:         A lower value means less tracing. Rolloff may not be updated 100% as new tintless output and tracing
    ///                slowly. A higher value mean more aggressive tracing so it matches with new tintless output. It may cause
    ///                flickering.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                  tintless_trace_percentage;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// center_weight
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   center compensation weight
    /// Type:          float
    /// Default Value: 1
    /// Range:         [0.0,1.0]
    /// Bit Depth:     16uQ0
    /// Conversion:    no conversion needed
    /// Notes:         give center compensation weight and if it is 0, it means don't give weight on center
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                  center_weight;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// corner_weight
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   corner compensation weight
    /// Type:          float
    /// Default Value: 1
    /// Range:         [0.0,1.0]
    /// Bit Depth:     16uQ0
    /// Conversion:    no conversion needed
    /// Notes:         give corner compensation weight and if it is 0, it means don't give weight on corner
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                  corner_weight;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_tintless20_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_tintless20_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    globalelements::trigger_pt_type_aec     aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// tintless20_rgn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tintless20_rgn_dataType tintless20_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_tintless20_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_tintless20_hdr_aec_dataType
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
        /// mod_tintless20_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                       mod_tintless20_aec_dataCount;
        UINT32                       mod_tintless20_aec_dataID;
        mod_tintless20_aec_dataType* mod_tintless20_aec_data;
    } hdr_aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_tintless20_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_tintless20_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_tintless20_hdr_aec_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                           mod_tintless20_hdr_aec_dataCount;
    UINT32                           mod_tintless20_hdr_aec_dataID;
    mod_tintless20_hdr_aec_dataType* mod_tintless20_hdr_aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_tintless20Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_tintless20Type
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
        globalelements::enable_flag_type tintless_en;
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
    /// Default Value: control_aec_exp_sensitivity_ratio, control_lux_idx
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_aec_exp_sensitivity_ratio, control_lux_idx
        /// Length:        2
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_lux_idx                   = 0,
            control_gain                      = 1,
            control_exp_time_ratio            = 3,
            control_aec_exp_sensitivity_ratio = 4,
            control_exp_gain_ratio            = 5
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
    /// dynamic_enable_triggers
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct dynamic_enable_triggersStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// tintless_en
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct tintless_enStruct
        {
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// Binary file symbol table entry ID
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            UINT32 SymbolTableID;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// enable
            ///
            /// Tuning Level:  rarely_tune
            /// Description:   enable Tintless 2.0 module
            /// Type:          int
            /// Default Value: 0
            /// Range:         [0,1]
            /// Bit Depth:     1uQ0
            /// Conversion:    no conversion needed
            /// Notes:         none
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            globalelements::enable_flag_type        enable;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// hyst_control_var
            ///
            /// Tuning Level:  rarely_tune
            /// Description:   enable Tintless 2.0 module
            /// Type:          uint
            /// Default Value: control_gain
            /// Range:         [0,1]
            /// Bit Depth:     1uQ0
            /// Conversion:    no conversion needed
            /// Notes:         none
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ispglobalelements::control_var_type        hyst_control_var;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// hyst_mode
            /// Default Value: UPWARD
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ispglobalelements::hyst_direction          hyst_mode;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// hyst_trigger
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ispglobalelements::trigger_pt_couplet_type hyst_trigger;
        } tintless_en;
    } dynamic_enable_triggers;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_tintless20_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_tintless20_coreType chromatix_tintless20_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_tintless20TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_tintless20TypeClass : public ParameterModule, public chromatix_tintless20Type
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
    chromatix_tintless20TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_tintless20TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_tintless20TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load tintless20_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadtintless20_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        tintless20_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load tintless20_rgn_dataType_tintless_threshold_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadtintless20_rgn_dataType_tintless_threshold_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        tintless20_rgn_dataType::tintless_threshold_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_tintless20_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_tintless20_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_tintless20_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_tintless20_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_tintless20_hdr_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_tintless20_hdr_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_tintless20_hdr_aec_dataType::hdr_aec_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_tintless20_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_tintless20_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_tintless20Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_tintless20Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_methodStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_methodStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::control_methodStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load dynamic_enable_triggersStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loaddynamic_enable_triggersStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::dynamic_enable_triggersStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load dynamic_enable_triggersStruct_tintless_enStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loaddynamic_enable_triggersStruct_tintless_enStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_tintless20Type::dynamic_enable_triggersStruct::tintless_enStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_tintless20_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_tintless20_hdr_aec_dataType(
        mod_tintless20_hdr_aec_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct(
        mod_tintless20_hdr_aec_dataType::hdr_aec_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_tintless20_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_tintless20_coreType(
        chromatix_tintless20_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_tintless20Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_tintless20Type(
        chromatix_tintless20Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_tintless20Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_tintless20TypeClass

TINTLESS_2_0_0_NAMESPACE_END
#endif // TINTLESS_2_0_0_H

