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
/// @file  camxmoduleconfig.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CAMXMODULECONFIG_H
#define CAMXMODULECONFIG_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "camxsensorcommon.h"

#define CAMX_NAMESPACE_BEGIN namespace CamX {
#define CAMX_NAMESPACE_END }

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CameraPosition
/// Comments:      Position of the sensor module.
///                Valid values are: REAR, FRONT, REAR_AUX, FRONT_AUX, EXTERNAL
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class CameraPosition
{
    REAR      = 0,
    FRONT     = 1,
    REAR_AUX  = 2,
    FRONT_AUX = 3,
    EXTERNAL  = 4
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CSIInformation
///
/// Description:   CSI Information
/// Comments:      CSI information
///                 element for laneAssign
///                 element for isComboMode
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct CSIInformation
{
    /// lane Assign
    UINT32  laneAssignExists;
    UINT32  laneAssignID;
    UINT16  laneAssign;
    /// Flag to enable combo mode
    /// This flag is enabled if multiple sensors are using same CSI-PHY receiver.
    UINT32  isComboModeExists;
    UINT32  isComboModeID;
    UINT8   isComboMode;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LensInformation
///
/// Description:   Lens Information
/// Comments:      Lens information
///                 element for focalLength
///                 element for fNumber
///                 element for minFocusDistance
///                 element for maxFocusDistance
///                 element for horizontalViewAngle
///                 element for verticalViewAngle
///                 element for maxRollDegree
///                 element for maxPitchDegree
///                 This corresponds to the camera mountAngle
///                 element for maxYawDegree
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct LensInformation
{
    /// Focal length of the lens in millimeters.
    DOUBLE  focalLength;
    /// F-Number of the optical system.
    DOUBLE  fNumber;
    /// Minimum focus distance in meters.
    DOUBLE  minFocusDistance;
    /// Total focus distance in meters.
    DOUBLE  maxFocusDistance;
    /// Horizontal view angle in degrees.
    DOUBLE  horizontalViewAngle;
    /// Vertical view angle in degrees.
    DOUBLE  verticalViewAngle;
    /// Maximum Roll Degree: Camera mount rotation along X axis
    /// Valid values: 0-359; 360 corresponds to invalid roll degree
    UINT32  maxRollDegreeExists;
    UINT32  maxRollDegreeID;
    DOUBLE  maxRollDegree;
    /// Maximum Pitch degree: Camera mount rotation along Y axis
    /// Valid values: 0, 90, 180, 270; 360 corresponds to invalid pitch degree
    UINT32  maxPitchDegreeExists;
    UINT32  maxPitchDegreeID;
    DOUBLE  maxPitchDegree;
    /// Maximum Yaw degree: Camera mount rotation along Z axis
    /// Valid values: 0-359; 360 corresponds to invalid yaw degree
    UINT32  maxYawDegreeExists;
    UINT32  maxYawDegreeID;
    DOUBLE  maxYawDegree;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ModuleConfiguration
///
/// Description:   Module configuration
/// Comments:      Module configuration
///                 element for CameraId
///                 element for module name
///                 Element for sensorName
///                 Element for sensorVersion
///                 Element for actuatorName
///                 Element for oisName
///                 Element for eepromName
///                 Element for flashName
///                 Element for chromatixName
///                 element for position
///                 element for CSIInfo
///                 element for lensInfo
///                 Element for pdafName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ModuleConfiguration
{
    /// CameraId is the id to which DTSI node is mapped.
    /// Typically CameraId is the slot Id for non combo mode.
    /// External sensor use the upper 8bit to specified the slot Id
    UINT16                              cameraId;
    /// Name of the module integrator
    UINT32                              moduleNameExists;
    UINT32                              moduleNameID;
    CHAR*                               moduleName;
    /// Name of the sensor in the image sensor module
    CHAR*                               sensorName;
    /// Version of the sensor in the image sensor module
    UINT16                              sensorVersion;
    /// Sensor slave adddress to over ride the value present in the binary
    /// This is an optional element. Do not use this entry if override is not required.
    UINT32                              sensorSlaveAddressExists;
    UINT32                              sensorSlaveAddressID;
    UINT16                              sensorSlaveAddress;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// sensorI2CFrequencyMode - Optional
    /// Min Length:    0
    /// Max Length:    1
    /// Comments:      I2C frequency mode of slave
    ///                Supported modes are: STANDARD (100 KHz), FAST (400 KHz), FAST_PLUS (1 MHz), CUSTOM (Custom frequency in
    ///                DTSI)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                              sensorI2CFrequencyModeExists;
    UINT32                              sensorI2CFrequencyModeID;
    I2CFrequencyMode  sensorI2CFrequencyMode;
    /// Actuator name in the image sensor module
    /// This is an optional element. Skip this element if actuator is not present
    UINT32                              actuatorNameExists;
    UINT32                              actuatorNameID;
    CHAR*                               actuatorName;
    /// OIS name in the image sensor module
    /// This is an optional element. Skip this element if OIS is not present
    UINT32                              oisNameExists;
    UINT32                              oisNameID;
    CHAR*                               oisName;
    /// EEPROM name in the image sensor module
    /// This is an optional element. Skip this element if EEPROM is not present
    UINT32                              eepromNameExists;
    UINT32                              eepromNameID;
    CHAR*                               eepromName;
    /// eeprom slave adddress to over ride the value present in the binary
    /// This is an optional element. Do not use this entry if override is not required.
    UINT32                              eepromSlaveAddressExists;
    UINT32                              eepromSlaveAddressID;
    UINT16                              eepromSlaveAddress;
    /// Flash name is used to used to open binary.
    /// Binary name is of form flashName_flash.bin Ex:- pmic_flash.bin
    UINT32                              flashNameExists;
    UINT32                              flashNameID;
    CHAR*                               flashName;
    /// Chromatix name is used to used to open binary.
    /// Binary name is of the form sensor_model_chromatix.bin
    UINT32                              chromatixNameExists;
    UINT32                              chromatixNameID;
    CHAR*                               chromatixName;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// position
    /// Comments:      Position of the sensor module.
    ///                Valid values are: REAR, FRONT, REAR_AUX, FRONT_AUX, EXTERNAL
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CameraPosition                      position;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// CSIInfo
    ///
    /// Description:   CSI Information
    /// Comments:      CSI information
    ///                 element for laneAssign
    ///                 element for isComboMode
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CSIInformation                      CSIInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lensInfo
    ///
    /// Description:   Lens Information
    /// Comments:      Lens information
    ///                 element for focalLength
    ///                 element for fNumber
    ///                 element for minFocusDistance
    ///                 element for maxFocusDistance
    ///                 element for horizontalViewAngle
    ///                 element for verticalViewAngle
    ///                 element for maxRollDegree
    ///                 element for maxPitchDegree
    ///                 This corresponds to the camera mountAngle
    ///                 element for maxYawDegree
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    LensInformation                     lensInfo;
    UINT32                              pdafNameExists;
    UINT32                              pdafNameID;
    CHAR*                               pdafName;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ModuleGroup
/// Comments:      Module group can contain either 1 module or 2 modules
///                Dual camera, stereo camera use cases contain 2 modules in the group
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ModuleGroup
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// moduleConfiguration - Array
    ///
    /// Description:   Module configuration
    /// Min Length:    1
    /// Max Length:    Unbounded
    /// Comments:      Module configuration
    ///                 element for CameraId
    ///                 element for module name
    ///                 Element for sensorName
    ///                 Element for sensorVersion
    ///                 Element for actuatorName
    ///                 Element for oisName
    ///                 Element for eepromName
    ///                 Element for flashName
    ///                 Element for chromatixName
    ///                 element for position
    ///                 element for CSIInfo
    ///                 element for lensInfo
    ///                 Element for pdafName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32               moduleConfigurationCount;
    UINT32               moduleConfigurationID;
    ModuleConfiguration* moduleConfiguration;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CameraModuleData
/// Comments:      Camera module data
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct CameraModuleData
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
    /// moduleGroup
    /// Comments:      Module group can contain either 1 module or 2 modules
    ///                Dual camera, stereo camera use cases contain 2 modules in the group
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ModuleGroup    moduleGroup;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// CameraModuleDataClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CameraModuleDataClass : public ParameterModule, public CameraModuleData
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
    CameraModuleDataClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CameraModuleDataClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~CameraModuleDataClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load CSIInformation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadCSIInformation(
        ParameterFileSymbolTableEntry* entry,
        CSIInformation* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load LensInformation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadLensInformation(
        ParameterFileSymbolTableEntry* entry,
        LensInformation* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ModuleConfiguration
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadModuleConfiguration(
        ParameterFileSymbolTableEntry* entry,
        ModuleConfiguration* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ModuleGroup
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadModuleGroup(
        ParameterFileSymbolTableEntry* entry,
        ModuleGroup* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load CameraModuleData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadCameraModuleData(
        ParameterFileSymbolTableEntry* entry,
        CameraModuleData* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        CameraModuleData::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload ModuleConfiguration
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadModuleConfiguration(
        ModuleConfiguration* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload ModuleGroup
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadModuleGroup(
        ModuleGroup* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload CameraModuleData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadCameraModuleData(
        CameraModuleData* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class CameraModuleDataClass

CAMX_NAMESPACE_END
#endif // CAMXMODULECONFIG_H

