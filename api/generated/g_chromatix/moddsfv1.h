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
/// @file  moddsfv1.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODDSFV1_H
#define MODDSFV1_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "awbglobalelements.h"

#define MODDSFV1_NAMESPACE_BEGIN namespace moddsfv1 {
#define MODDSFV1_NAMESPACE_END }

MODDSFV1_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDSFV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDSFV1Type
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
    awbglobalelements::moduleIDType             moduleID;

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
    awbglobalelements::enableFlagType           enableFlag;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerPt
    ///
    /// Tuning Level:  never_tune
    /// Description:   Dummy data for consistent data structure
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::triggerPointType         triggerPt;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerData - Array
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Trigger control type: Lux Index
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                   triggerDataCount;
    UINT32                   triggerDataID;
    awbglobalelements::awbTriggerDataFloatType* triggerData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDSFV1TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatixDSFV1TypeClass : public ParameterModule, public chromatixDSFV1Type
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
    chromatixDSFV1TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDSFV1TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatixDSFV1TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDSFV1Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDSFV1Type(
        ParameterFileSymbolTableEntry* entry,
        chromatixDSFV1Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixDSFV1Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDSFV1Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDSFV1Type(
        chromatixDSFV1Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatixDSFV1TypeClass

MODDSFV1_NAMESPACE_END
#endif // MODDSFV1_H
