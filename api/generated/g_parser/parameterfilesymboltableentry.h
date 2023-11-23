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
/// @file  parameterfilesymboltableentry.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PARAMETERSYMBOLTABLEENTRY_H
#define PARAMETERSYMBOLTABLEENTRY_H

#include "parametertypes.h"
#include "parameterutils.h"

/*******************************************************************************
* Forward declarations
*******************************************************************************/
class ParameterFileSymbolTable;
/* To prevent misaligned pointer access, make this value greater than TYPE_LEN
   and 8 byte aligned */
#define TYPE_CHAR_ARRAY_LEN 40

class ParameterFileSymbolTableEntry
{
public:
    // ID 0 is reserved for Parent ID to indicate the entry is a Module
    static const UINT32 MODULE_PARENT_ID = 0;
    static const UINT32 START_ID         = 1;
    static const INT32  TYPE_LEN         = 32;
    static const INT32  TYPE_START_LEN   = TYPE_LEN / 4;
    static const INT32  TYPE_END_LEN     = TYPE_LEN - TYPE_START_LEN - 1;
    static const CHAR   TYPE_SEPARATOR   = '-';
    static const INT32  PREFIX_COUNT     = 2;

    // Symbol table entry size as defined in the Chromatix Data Access Design document
    static const INT32  SYMBOL_ENTRY_SIZE_LEGACY = 4 +       // ID
                                                   TYPE_LEN +// Type
                                                   2 +       // Version: Major
                                                   2 +       // Version: Minor
                                                   4 +       // Version: Patch
                                                   2 +       // Mode
                                                   2 +       // Selector
                                                   4 +       // Selector Data
                                                   4 +       // Mode ID
                                                   4 +       // Data Offset
                                                   4;        // Data Size

    // Symbol table entry size as defined in the Chromatix Data Access Design document
    static const INT32  SYMBOL_ENTRY_SIZE =        8 +       // ID
                                                   TYPE_LEN +// Type
                                                   2 +       // Version: Major
                                                   2 +       // Version: Minor
                                                   4 +       // Version: Patch
                                                   8 +       // Mode ID
                                                   8 +       // Data Offset
                                                   8;        // Data Size

    static const INT32  MODE_ENTRY_SIZE_LEGACY =   4 +       // ID
                                                   2 +       // Mode
                                                   2 +       // SubMode
                                                   4 +       // Group
                                                   4;        // Parent ID

    static const INT32  MODE_ENTRY_SIZE_NOLINK =   8 +       // ID
                                                   2 +       // Mode
                                                   2 +       // SubMode
                                                   4 +       // Group
                                                   8;        // Parent ID

    static const INT32  MODE_ENTRY_SIZE =          8 +       // ID
                                                   2 +       // Mode
                                                   2 +       // SubMode
                                                   4 +       // Group
                                                   8 +       // Parent ID
                                                   8;        // Link ID

    ParameterFileSymbolTableEntry();

    ~ParameterFileSymbolTableEntry();

    VOID Init(
        ParameterFileSymbolTable* table);

    BOOL Load(
        BYTE*       buffer,
        UINT64      length,
        UINT64*     pos,
        UINT32      dataOffset,
        IModeTable* modeTable,
        UINT64      alignment);

    static CHAR* GetType(
        CHAR*       outputType,
        const CHAR* moduleName);

    inline BOOL IsModule()
    {
        const UINT32 NON_MODULE_PARENT_ID = 0xFFFFFFFF;
        return ModeId != NON_MODULE_PARENT_ID;
    }

    template<typename T> inline BOOL Read(
        T*     value,
        UINT64 alignment)
    {
        return ParameterUtils::Read(value, m_data, m_dataSize, &m_position, alignment);
    }

    template<typename T> inline T* ReadArray(
        UINT64 count,
        UINT64 alignment)
    {
        return ParameterUtils::ReadArray<T>(m_data, m_dataSize, &m_position, count, alignment);
    }

    template<typename T> inline BOOL ReadArray(
        T*     value,
        UINT64 count,
        UINT64 alignment)
    {
        return ParameterUtils::ReadArray(value, m_data, m_dataSize, &m_position, count, alignment);
    }

    inline BOOL ReadString(
        CHAR** value,
        UINT64 maxChars,
        UINT64 alignment)
    {
        *value = ParameterUtils::ReadString(m_data, m_dataSize, &m_position, maxChars, alignment);
        return *value != NULL;
    }

    inline UINT32 ReadEnum(
        BOOL*  result,
        UINT64 alignment)
    {
        UINT32 value = 0;
        *result = ParameterUtils::Read(&value, m_data, m_dataSize, &m_position, alignment);
        return value;
    }

    ParameterFileSymbolTable* Table;

    UINT32       ID;
    CHAR         Type[TYPE_CHAR_ARRAY_LEN];
    VersionUnion Version;
    ModeUnion    Mode;
    UINT32       ModeId;

private:
    UINT32 m_dataSize;
    BYTE*  m_data;
    UINT64 m_position;
};

#endif