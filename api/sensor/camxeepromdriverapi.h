////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  camxeepromdriverapi.h
/// @brief EEPROM Driver function declarations
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CAMXEEPROMDRIVERAPI_H
#define CAMXEEPROMDRIVERAPI_H

#include "camxcdktypes.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define HW_ROLLOFF_TABLE_SIZE 221

/// Data that is associated with registerAddr
typedef UINT32 RegisterData;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// I2CRegAddrDataType
///
/// Range:         [1,4]
/// Comments:      Register address / data size in bytes
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef UINT32 I2CRegAddrDataType;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// OperationType
/// Comments:      Type of I2C operation
///                Valid values are: WRITE, WRITE_BURST, WRITE_SEQUENTIAL, READ, POLL
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class OperationType
{
    WRITE            = 0,
    WRITE_BURST      = 1,
    WRITE_SEQUENTIAL = 2,
    READ             = 3,
    POLL             = 4,
    MAX              = 5
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EEPROMIlluminantType
/// Comments:      Type of the illuminant
///                Supported illuminants are D65, TL84, A, D50 and H
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class EEPROMIlluminantType
{
    D65  = 0,
    TL84 = 1,
    A    = 2,
    D50  = 3,
    H    = 4,
    MAX  = 5
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// RegisterSetting
/// Comments:      Register setting configuration
///                Contains: register address, register data, register address type, register data type,
///                operation and delay in micro seconds
///                 element for slaveAddr
///                 element for registerAddr
///                 element for registerData
///                 element for regAddrType
///                 element for regDataType
///                 element for operation
///                 element for delayUs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct RegisterSetting
{
    /// Slave address to communicate with the device
    UINT32             slaveAddrExists;
    UINT32             slaveAddrID;
    UINT16             slaveAddr;
    /// Register address that is accessed
    UINT32             registerAddr;
    /// List of data items in bytes seperated by space as delimiter.
    /// Data may be written to an I2C slave in burst mode.
    /// If operation is WRITE, a single registerData item is to be written into location specified by registerAddr.
    /// For operation WRITE_BURST, a list of 1 or more registerData items will be written serially starting
    /// at the location specified by registerAddr, and the I2C slave will internally increment the address for each
    /// registerData item.
    /// For operation WRITE_SEQUENTIAL, a list of 1 or more registerData items will be written serially starting
    /// at the location specified by registerAddr, but the address is explicitly generated by the driver for each
    /// registerData item in the list.
    /// If operation is READ, registerData is the number of bytes to be read from the specified register address
    UINT32             registerDataCount;
    UINT32             registerDataID;
    RegisterData*      registerData;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// regAddrType
    ///
    /// Range:         [1,4]
    /// Comments:      Register address / data size in bytes
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    I2CRegAddrDataType regAddrType;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// regDataType
    ///
    /// Range:         [1,4]
    /// Comments:      Register address / data size in bytes
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    I2CRegAddrDataType regDataType;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// operation
    /// Default Value: WRITE
    /// Comments:      Type of I2C operation
    ///                Valid values are: WRITE, WRITE_BURST, WRITE_SEQUENTIAL, READ, POLL
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    OperationType      operation;
    /// Delay in micro seconds. Delay is 0 if not explicitly provided
    /// For operation WRITE, the delay value is applied at the end of the single register data item.
    /// For operation WRITE_BURST, WRITE_SEQUENTIAL, the delay value is applied at the end of the burst sequence.
    UINT32             delayUsExists;
    UINT32             delayUsID;
    UINT32             delayUs;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// SettingsInfo
/// Comments:      Sequence of register settings to configure the device
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct SettingsInfo
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// regSetting - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    /// Comments:      Register setting configuration
    ///                Contains: register address, register data, register address type, register data type,
    ///                operation and delay in micro seconds
    ///                 element for slaveAddr
    ///                 element for registerAddr
    ///                 element for registerData
    ///                 element for regAddrType
    ///                 element for regDataType
    ///                 element for operation
    ///                 element for delayUs
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32           regSettingCount;
    UINT32           regSettingID;
    RegisterSetting* regSetting;
};

/// @brief White balance calibration data
struct WBCalibration
{
    BOOL                    isAvailable;    ///< Indicates whether WB calibration data is avialabe or not.
    EEPROMIlluminantType    illuminant;     ///< Indicates color temperature illuminant type
    FLOAT                   rOverG;         ///< R over G data
    FLOAT                   bOverG;         ///< B over G data
    FLOAT                   grOverGB;       ///< GR over GB data
    SettingsInfo            settings;       ///< Contain the register settings to write for WB calibration
};

struct LSCCalibration
{
    BOOL                    isAvailable;                    ///< Indicates whether LSC calibration data is avialabe or not
    EEPROMIlluminantType    illuminant;                     ///< Indicates color temperature illuminant type
    UINT16                  meshHWRollOffSize;              ///< indicates the roll of table size
    FLOAT                   rGain[HW_ROLLOFF_TABLE_SIZE];   ///< R gain table
    FLOAT                   grGain[HW_ROLLOFF_TABLE_SIZE];  ///< GR gain table
    FLOAT                   gbGain[HW_ROLLOFF_TABLE_SIZE];  ///< GB gain table
    FLOAT                   bGain[HW_ROLLOFF_TABLE_SIZE];   ///< B gain table
    SettingsInfo            settings;                       ///< Contain the register settings to write for LSC calibration
};

struct TOFCalibration
{
    BOOL         isAvailable;                     ///< Indicates whether TOF calibration data is avialabe or not
    SettingsInfo settings;                        ///< Contain the register settings to write for TOFcalibration
};

/// @brief APIs in eeprom library
typedef struct EEPROMLibraryAPI
{
    UINT  size;         ///< Size of eeprom library API structure
    UINT  majorVersion; ///< Major version of the Library API
    UINT  minorVersion; ///< Minor version of the Library API

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatLSCSettings
    ///
    /// @brief  Format the LSC settings
    ///
    /// @param  otpdata      pointer to otp data
    /// @param  otpdatasize  size of otp data
    /// @param  pLSCData     pointer to LSC calibration data to fill LSC reg settings
    /// @return 1 if successful else 0
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID (*pFormatLSCSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        LSCCalibration* pLSCData); ///< pointer to FormatLSCSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatAWBSettings
    ///
    /// @brief  Format the awb settings
    ///
    /// @param  otpdata      pointer to otp data
    /// @param  otpdatasize  size of otp data
    /// @param  pWBData      pointer to WB calibration data to fill WB reg settings
    ///
    /// @return 1 if successful else 0
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID (*pFormatWBSettings)(UINT8* otpdata,
        UINT32             otpdatasize,
        WBCalibration* pWBData);  ///< pointer to FormatAutoWhiteBalanceSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatTOFLongRangeModeSettings
    ///
    /// @brief  Format the TOF Long range mode settings
    ///
    /// @param  otpdata      pointer to otp data
    /// @param  otpdatasize  size of otp data
    /// @param  pTOFData     pointer to TOF calibration data to fill TOF reg settings
    /// @return 1 if successful else 0
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    VOID (*pFormatTOFLongRangeModeSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* pLongRangModeData); ///< pointer to FormatTOFLongRangeModeSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatTOFSettings
    ///
    /// @brief  Format the TOF Long range mode settings
    ///
    /// @param  otpdata      pointer to otp data
    /// @param  otpdatasize  size of otp data
    /// @param  pTOFData     pointer to TOF calibration data to fill TOF reg settings
    /// @return 1 if successful else 0
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID (*pFormatTOFShortRangeModeSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* pShortRangModeData); ///< pointer to FormatTOFShortRangeModeSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pOtadataVerify
    ///
    /// @brief  Verify the otpdata
    ///
    /// @param  otpdata        pointer to otp data
    /// @param  otpdatasize    size of otp data
    /// @return 0 if successful else failed.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT8 (*pOtpdataVerify)(UINT8* otpdata,
        UINT32 otpdatasize);                 ///< pointer to OtadataVerify function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatTOFInitSettings
    ///
    /// @brief  Format the TOF init settings
    ///
    /// @param  otpdata        pointer to otp data
    /// @param  otpdatasize    size of otp data
    /// @param  TOFCalibration pointer to TOF calibration data to fill TOF reg settings
    /// @return 0 if successful else failed.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT8 (*pFormatTOFInitSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* TOFCalibration);     ///< pointer to FormatTOFInitSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatTOFResolutonSettings
    ///
    /// @brief  Format the TOF resolution settings
    ///
    /// @param  otpdata        pointer to otp data
    /// @param  otpdatasize    size of otp data
    /// @param  residx       index of resolution
    /// @param  TOFCalibration pointer to TOF calibration data to fill TOF reg settings
    /// @return 0 if successful else failed.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT8 (*pFormatTOFResolutonSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        UINT16 residx,
        TOFCalibration* TOFCalibration);     ///< pointer to FormatTOFResolutionSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatTOFStreamOnSettings
    ///
    /// @brief  Format the TOF stream on settings
    ///
    /// @param  otpdata        pointer to otp data
    /// @param  otpdatasize    size of otp data
    /// @param  TOFCalibration pointer to TOF calibration data to fill TOF reg settings
    /// @return 0 if successful else failed.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT8 (*pFormatTOFStreamOnSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* TOFCalibration);     ///< pointer to FormatTOFStreamOnSettings function

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pFormatTOFStreamOffSettings
    ///
    /// @brief  Format the TOF stream off settings
    ///
    /// @param  otpdata        pointer to otp data
    /// @param  otpdatasize    size of otp data
    /// @param  TOFCalibration pointer to TOF calibration data to fill TOF reg settings
    /// @return 0 if successful else failed.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT8 (*pFormatTOFStreamOffSettings)(UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* TOFCalibration);     ///< pointer to FormatTOFStreamOffSettings function
} EEPROMLibraryAPI;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetEEPROMLibraryAPIs
///
/// @brief Returns the EEPROM library API structure
///
/// @param pEEPROMLibraryAPI pointer to the EEPROM library API structure.
///
/// This function is the entry point for the library. CamX will query the shared library for this method by name.
///
/// @return None
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CDK_VISIBILITY_PUBLIC void GetEEPROMLibraryAPIs(
    EEPROMLibraryAPI* pEEPROMLibraryAPI);

#ifdef __cplusplus
} // CamX Namespace
#endif // __cplusplus

#endif // CAMXEEPROMDRIVERAPI_H
