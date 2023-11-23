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
/// @file  bincorr_1_0_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BINCORR_1_0_0_H
#define BINCORR_1_0_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define BINCORR_1_0_0_NAMESPACE_BEGIN namespace bincorr_1_0_0 {
#define BINCORR_1_0_0_NAMESPACE_END }

BINCORR_1_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// bincorr10_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct bincorr10_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ver_bin_corr_w1
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   vertical weight w1
    /// Type:          int
    /// Default Value: 112
    /// Range:         [0,128]
    /// Bit Depth:     8uQ7
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 ver_bin_corr_w1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ver_bin_corr_w2
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   vertical weight w2
    /// Type:          int
    /// Default Value: 112
    /// Range:         [0,128]
    /// Bit Depth:     8uQ7
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 ver_bin_corr_w2;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hor_bin_corr_w1
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   horizontal weight w1
    /// Type:          int
    /// Default Value: 112
    /// Range:         [0,128]
    /// Bit Depth:     8uQ7
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 hor_bin_corr_w1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hor_bin_corr_w2
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   horizontal weight w2
    /// Type:          int
    /// Default Value: 112
    /// Range:         [0,128]
    /// Bit Depth:     8uQ7
    /// Conversion:    no conversion needed
    /// Notes:         none
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 hor_bin_corr_w2;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_bincorr10_pre_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_bincorr10_pre_scale_ratio_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pre_scale_ratio_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type        pre_scale_ratio_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// bincorr10_rgn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bincorr10_rgn_dataType bincorr10_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_bincorr10_post_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_bincorr10_post_scale_ratio_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// post_scale_ratio_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type       post_scale_ratio_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// post_scale_ratio_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct post_scale_ratio_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_bincorr10_pre_scale_ratio_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                                  mod_bincorr10_pre_scale_ratio_dataCount;
        UINT32                                  mod_bincorr10_pre_scale_ratio_dataID;
        mod_bincorr10_pre_scale_ratio_dataType* mod_bincorr10_pre_scale_ratio_data;
    } post_scale_ratio_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_bincorr10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_bincorr10_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_bincorr10_post_scale_ratio_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                   mod_bincorr10_post_scale_ratio_dataCount;
    UINT32                                   mod_bincorr10_post_scale_ratio_dataID;
    mod_bincorr10_post_scale_ratio_dataType* mod_bincorr10_post_scale_ratio_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_bincorr10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_bincorr10Type
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
        globalelements::enable_flag_type bincorr_enable;
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
    /// Default Value: control_post_scale_ratio, control_pre_scale_ratio
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_post_scale_ratio, control_pre_scale_ratio
        /// Length:        2
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_post_scale_ratio = 11,
            control_pre_scale_ratio  = 14
        } control_var_type[2];
    } control_variables;

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
        /// bincorr_enable
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct bincorr_enableStruct
        {
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// Binary file symbol table entry ID
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            UINT32 SymbolTableID;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// enable
            ///
            /// Tuning Level:  rarely_tune
            /// Description:   Enable of the module
            /// Type:          int
            /// Default Value: 1
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
            /// Description:   Enable binning correction 1.0
            /// Type:          uint
            /// Default Value: control_pre_scale_ratio
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
        } bincorr_enable;
    } dynamic_enable_triggers;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_bincorr10_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_bincorr10_coreType chromatix_bincorr10_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_bincorr10TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_bincorr10TypeClass : public ParameterModule, public chromatix_bincorr10Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 1;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_bincorr10TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_bincorr10TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_bincorr10TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load bincorr10_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadbincorr10_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        bincorr10_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bincorr10_pre_scale_ratio_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bincorr10_pre_scale_ratio_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_bincorr10_pre_scale_ratio_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bincorr10_post_scale_ratio_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bincorr10_post_scale_ratio_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_bincorr10_post_scale_ratio_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bincorr10_post_scale_ratio_dataType_post_scale_ratio_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bincorr10_post_scale_ratio_dataType_post_scale_ratio_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_bincorr10_post_scale_ratio_dataType::post_scale_ratio_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_bincorr10_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_bincorr10_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_bincorr10Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_bincorr10Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load dynamic_enable_triggersStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loaddynamic_enable_triggersStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type::dynamic_enable_triggersStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load dynamic_enable_triggersStruct_bincorr_enableStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loaddynamic_enable_triggersStruct_bincorr_enableStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bincorr10Type::dynamic_enable_triggersStruct::bincorr_enableStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_bincorr10_post_scale_ratio_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_bincorr10_post_scale_ratio_dataType(
        mod_bincorr10_post_scale_ratio_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_bincorr10_post_scale_ratio_dataType_post_scale_ratio_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_bincorr10_post_scale_ratio_dataType_post_scale_ratio_dataStruct(
        mod_bincorr10_post_scale_ratio_dataType::post_scale_ratio_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_bincorr10_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_bincorr10_coreType(
        chromatix_bincorr10_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_bincorr10Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_bincorr10Type(
        chromatix_bincorr10Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_bincorr10Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_bincorr10TypeClass

BINCORR_1_0_0_NAMESPACE_END
#endif // BINCORR_1_0_0_H
