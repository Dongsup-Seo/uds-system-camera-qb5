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
/// @file  modmlczv3.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODMLCZV3_H
#define MODMLCZV3_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "awbglobalelements.h"

#define MODMLCZV3_NAMESPACE_BEGIN namespace modmlczv3 {
#define MODMLCZV3_NAMESPACE_END }

MODMLCZV3_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// awbMLCZoneConfigTypeV3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct awbMLCZoneConfigTypeV3
{
    CHAR*              Description;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// groupID
    ///
    /// Description:   Zone group ID. Each zone group can consist of several zones
    /// Type:          int
    /// Range:         [0,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32              groupID;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// zoneType
    ///
    /// Description:   Options of zone Type: Rectangle, Triangle
    /// Type:          awbZoneType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::awbZoneType        zoneType;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerLevel
    ///
    /// Description:   Number of triggering dimension
    /// Type:          int
    /// Range:         [1,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32              triggerLevel;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerCtrlType - Array
    /// Length:        3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::awbTriggerCtrlType triggerCtrlType[3];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// awbMLCDetecionZoneTypeV3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct awbMLCDetecionZoneTypeV3
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// zoneConfigData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbMLCZoneConfigTypeV3  zoneConfigData;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerPt
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::triggerPointType        triggerPt;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerData - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                  triggerDataCount;
    UINT32                  triggerDataID;
    awbglobalelements::awbTriggerDataZoneType* triggerData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// modMLCZoneWeightDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct modMLCZoneWeightDataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerType - Array
    /// Length:        2
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::awbTriggerCtrlType         triggerType[2];

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerPt
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::triggerPointType           triggerPt;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerData - Array
    ///
    /// Description:   1st triggering level
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                     triggerDataCount;
    UINT32                     triggerDataID;
    awbglobalelements::awbSAConfidenceLevel2Type* triggerData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// awbMLCZoneTypeV3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct awbMLCZoneTypeV3
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// zoneConfigData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbMLCZoneConfigTypeV3        zoneConfigData;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerPt
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::triggerPointType              triggerPt;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerData - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                        triggerDataCount;
    UINT32                        triggerDataID;
    awbglobalelements::awbTriggerDataZoneLevel1Type* triggerData;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// MLCZoneWeight - Array
    ///
    /// Tuning Level:  often_tune
    /// Description:   MLC zone setting with configurable trigger control type
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                        MLCZoneWeightCount;
    UINT32                        MLCZoneWeightID;
    modMLCZoneWeightDataType*     MLCZoneWeight;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixMLCZV3Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixMLCZV3Type
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// moduleID
    ///
    /// Tuning Level:  never_tune
    /// Description:   Define module ID, sub module ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::moduleIDType              moduleID;

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
    awbglobalelements::enableFlagType            enableFlag;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// detectionZoneV3 - Array
    ///
    /// Tuning Level:  often_tune
    /// Description:   define detection zone that will be used for triggering control typ for MLCZ
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                    detectionZoneV3Count;
    UINT32                    detectionZoneV3ID;
    awbMLCDetecionZoneTypeV3* detectionZoneV3;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// MLCZV3 - Array
    ///
    /// Tuning Level:  often_tune
    /// Description:   MLC zone setting with configurable trigger control type
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                    MLCZV3Count;
    UINT32                    MLCZV3ID;
    awbMLCZoneTypeV3*         MLCZV3;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixMLCZV3TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatixMLCZV3TypeClass : public ParameterModule, public chromatixMLCZV3Type
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
    chromatixMLCZV3TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixMLCZV3TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatixMLCZV3TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load awbMLCZoneConfigTypeV3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadawbMLCZoneConfigTypeV3(
        ParameterFileSymbolTableEntry* entry,
        awbMLCZoneConfigTypeV3* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load awbMLCDetecionZoneTypeV3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadawbMLCDetecionZoneTypeV3(
        ParameterFileSymbolTableEntry* entry,
        awbMLCDetecionZoneTypeV3* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load modMLCZoneWeightDataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadmodMLCZoneWeightDataType(
        ParameterFileSymbolTableEntry* entry,
        modMLCZoneWeightDataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load awbMLCZoneTypeV3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadawbMLCZoneTypeV3(
        ParameterFileSymbolTableEntry* entry,
        awbMLCZoneTypeV3* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixMLCZV3Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixMLCZV3Type(
        ParameterFileSymbolTableEntry* entry,
        chromatixMLCZV3Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixMLCZV3Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixMLCZV3Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload awbMLCZoneConfigTypeV3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadawbMLCZoneConfigTypeV3(
        awbMLCZoneConfigTypeV3* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload awbMLCDetecionZoneTypeV3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadawbMLCDetecionZoneTypeV3(
        awbMLCDetecionZoneTypeV3* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload modMLCZoneWeightDataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadmodMLCZoneWeightDataType(
        modMLCZoneWeightDataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload awbMLCZoneTypeV3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadawbMLCZoneTypeV3(
        awbMLCZoneTypeV3* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixMLCZV3Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixMLCZV3Type(
        chromatixMLCZV3Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatixMLCZV3Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatixMLCZV3TypeClass

MODMLCZV3_NAMESPACE_END
#endif // MODMLCZV3_H
