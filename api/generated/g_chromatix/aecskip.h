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
/// @file  aecskip.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AECSKIP_H
#define AECSKIP_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "aecglobalelements.h"

#define AECSKIP_NAMESPACE_BEGIN namespace aecSkip {
#define AECSKIP_NAMESPACE_END }

AECSKIP_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DFSSkipCountZoneDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DFSSkipCountZoneDataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DFSSkipCount
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify the adjusted max number of frames to be skipped for stable scene.
    /// Type:          int
    /// Range:         [0, 10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 DFSSkipCount;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DFSMinSettleThreshold
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify the minimal count of settle down.
    /// Type:          int
    /// Range:         [1,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 DFSMinSettleThreshold;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DFSSkipCountZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DFSSkipCountZoneType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// zoneTrigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::TriggerPointType         zoneTrigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// zoneData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    DFSSkipCountZoneDataType zoneData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECSkipCtrlType
/// Comments:       Snapshot Tuning Definition
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AECSkipCtrlType
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

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
    /// DFSEnable
    ///
    /// Tuning Level:  often_tune
    /// Description:   Enable aec dynamic frame skip
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                  DFSEnable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DFSExpIndexTolerance
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify the Exposure index tolerance for dynamic frame skip
    /// Type:          float
    /// Range:         [0.5,3]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                 DFSExpIndexTolerance;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DFSMaxHistoryCount
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify the history count for exp index used in skip.
    /// Type:          int
    /// Range:         [1,30]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                 DFSMaxHistoryCount;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DFSSkipCountZone - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                DFSSkipCountZoneCount;
    UINT32                DFSSkipCountZoneID;
    DFSSkipCountZoneType* DFSSkipCountZone;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECSkipCtrlTypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AECSkipCtrlTypeClass : public ParameterModule, public AECSkipCtrlType
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 8;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECSkipCtrlTypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECSkipCtrlTypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~AECSkipCtrlTypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DFSSkipCountZoneDataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDFSSkipCountZoneDataType(
        ParameterFileSymbolTableEntry* entry,
        DFSSkipCountZoneDataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DFSSkipCountZoneType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDFSSkipCountZoneType(
        ParameterFileSymbolTableEntry* entry,
        DFSSkipCountZoneType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load AECSkipCtrlType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadAECSkipCtrlType(
        ParameterFileSymbolTableEntry* entry,
        AECSkipCtrlType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECSkipCtrlType::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECSkipCtrlType::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload AECSkipCtrlType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadAECSkipCtrlType(
        AECSkipCtrlType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        AECSkipCtrlType::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class AECSkipCtrlTypeClass

AECSKIP_NAMESPACE_END
#endif // AECSKIP_H
