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
/// @file  aecdepth.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AECDEPTH_H
#define AECDEPTH_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "aecglobalelements.h"

#define AECDEPTH_NAMESPACE_BEGIN namespace aecDepth {
#define AECDEPTH_NAMESPACE_END }

AECDEPTH_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DepthConvergenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DepthConvergenceType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// convSpeedAdjRatio
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   specify the adjustment of convergence speed during Depth AEC convergence
    /// Type:          float
    /// Range:         [0,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT convSpeedAdjRatio;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DepthWeightZoneDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DepthWeightZoneDataType
{
    FLOAT weight;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DepthWeightZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DepthWeightZoneType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerPt
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::TriggerPointType        triggerPt;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    DepthWeightZoneDataType triggerData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DepthMapLUT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DepthMapLUT
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// knees - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32               kneesCount;
    UINT32               kneesID;
    DepthWeightZoneType* knees;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// type
    /// Default Value: DepthLUTDistance
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECDepthLUTType      type;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DepthMeteringType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct DepthMeteringType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// depthMeteringWeight - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32               depthMeteringWeightCount;
    UINT32               depthMeteringWeightID;
    DepthWeightZoneType* depthMeteringWeight;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mapsLUTs - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32               mapsLUTsCount;
    UINT32               mapsLUTsID;
    DepthMapLUT*         mapsLUTs;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// temporalFilter
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   temporal filter for frame to frame metering of depth ROI
    /// Type:          float
    /// Range:         [0.0,1.0]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                temporalFilter;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECDepthType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AECDepthType
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
    /// enableFlag
    ///
    /// Tuning Level:  often_tune
    /// Description:   Enable Flag for Depth-based AEC Adjustments
    /// Default Value: false
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                 enableFlag;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lumaDiffThres
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Threshold of luma difference for triggering rebasing mode from tracking mode
    /// Default Value: 8
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                lumaDiffThres;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// decisionMapValidGridCntThres
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   EThreshold of auto-focus selection grid count number for entering tracking mode from tracking mode
    /// Default Value: 20
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                decisionMapValidGridCntThres;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// consecInvalidFrameCntThres
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Threshold of consecutive invalid frame for triggering rebasing mode from tracking mode
    /// Default Value: 6
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                consecInvalidFrameCntThres;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// initValidFrameCntThres
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Threshold of valid frame for entering rebasing mode from initialization mode
    /// Default Value: 4
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                initValidFrameCntThres;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// selectMapValidGridCntThres
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Threshold of auto-focus selection grid count number to determine the input auto-focus selection map is
    ///                valid
    /// Default Value: 3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                selectMapValidGridCntThres;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// displayDebugMsg
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Flag to display DEPTHAEC debug message for display tool
    /// Default Value: false
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                 displayDebugMsg;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// depthMtr
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    DepthMeteringType    depthMtr;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// depthConv
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    DepthConvergenceType depthConv;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECDepthTypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AECDepthTypeClass : public ParameterModule, public AECDepthType
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
    AECDepthTypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECDepthTypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~AECDepthTypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DepthConvergenceType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDepthConvergenceType(
        ParameterFileSymbolTableEntry* entry,
        DepthConvergenceType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DepthWeightZoneDataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDepthWeightZoneDataType(
        ParameterFileSymbolTableEntry* entry,
        DepthWeightZoneDataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DepthWeightZoneType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDepthWeightZoneType(
        ParameterFileSymbolTableEntry* entry,
        DepthWeightZoneType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DepthMapLUT
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDepthMapLUT(
        ParameterFileSymbolTableEntry* entry,
        DepthMapLUT* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load DepthMeteringType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadDepthMeteringType(
        ParameterFileSymbolTableEntry* entry,
        DepthMeteringType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load AECDepthType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadAECDepthType(
        ParameterFileSymbolTableEntry* entry,
        AECDepthType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECDepthType::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECDepthType::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload DepthMapLUT
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadDepthMapLUT(
        DepthMapLUT* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload DepthMeteringType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadDepthMeteringType(
        DepthMeteringType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload AECDepthType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadAECDepthType(
        AECDepthType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        AECDepthType::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class AECDepthTypeClass

AECDEPTH_NAMESPACE_END
#endif // AECDEPTH_H

