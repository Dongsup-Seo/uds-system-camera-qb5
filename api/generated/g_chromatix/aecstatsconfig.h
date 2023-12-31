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
/// @file  aecstatsconfig.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AECSTATSCONFIG_H
#define AECSTATSCONFIG_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "aecglobalelements.h"

#define AECSTATSCONFIG_NAMESPACE_BEGIN namespace aecStatsConfig {
#define AECSTATSCONFIG_NAMESPACE_END }

AECSTATSCONFIG_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECROIConfigControlType
/// Comments:       Core Stats Configuration Tuning Definition
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class AECROIConfigControlType
{
    AECROIConfigControlTypeCroppedFOV = 0,
    AECROIConfigControlTypeFullFOV    = 1
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECGridStatsConfig
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AECGridStatsConfig
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// numOfRegionsHorizontal
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Number of Horizontal Regions for AEC stats grid
    /// Type:          ushort
    /// Range:         [1,64]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT16                  numOfRegionsHorizontal;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// numOfRegionsVertical
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Number of Vertical Regions for AEC stats grid
    /// Type:          ushort
    /// Range:         [1,48]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT16                  numOfRegionsVertical;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableStatsQuadSync
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Flag to enable bayer pixel Quad sync for saturated stats handling. Enabling will synchronize saturation
    ///                decision for each pixel quad
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                    enableStatsQuadSync;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableSaturatedStats
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Flag to enable Saturated Stats output. Enabling this will give more information on saturated pixels with
    ///                bigger stats output buffer size. Disable if power is of higher concern.
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                    enableSaturatedStats;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableYComputedStats
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Flag to enable Luma stats to be computed from color channels into single Channel Stats
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                    enableYComputedStats;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// YComputationColorWeight - Array
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   RGB channel weight for computing Y luma for HW stats. If enableYComputedStats is set to true, these
    ///                values will be used to compute Y value
    /// Type:          float
    /// Range:         [0, 1]
    /// Length:        3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                   YComputationColorWeight[3];

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// minStatsChannelThreshold - Array
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Logical value of minimun pixel value of each bayer channel (R, Gr, Gb, B) to be accumulated, value below
    ///                this value will be dropped, given HW support min thresholding. Value Range between 0 to 1. Value will be
    ///                translated to HW Bit Depth
    /// Type:          float
    /// Range:         [0, 1]
    /// Length:        4
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                   minStatsChannelThreshold[4];

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// maxStatsChannelThreshold - Array
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Logical value of maximum pixel value of each bayer channel (R, Gr, Gb, B) to be accumulated, value above
    ///                this value will be dropped. Value Range between 0 to 1. Value will be translated to HW Bit Depth
    /// Type:          float
    /// Range:         [0, 1]
    /// Length:        4
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                   maxStatsChannelThreshold[4];

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// HWStatsSkipFactor
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify HW grid skipping pattern based on power and accuracy trade-off. value of X means keeping 1 grid
    ///                every 2^X grid. value of zero means no skipping. Maximum supported value is 2
    /// Type:          byte
    /// Range:         [0,2]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT8                   HWStatsSkipFactor;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ROIConfigControl
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Select ROI configuration type. AECROIConfigControlTypeCroppedFOV means follow Zoomed FOV;
    ///                AECROIConfigControlTypeFullFOV means use Full FOV from Sensor. Default value:
    ///                AECROIConfigControlTypeCroppedFOV
    /// Default Value: AECROIConfigControlTypeCroppedFOV
    /// Range:         [0,1]
    /// Comments:       Core Stats Configuration Tuning Definition
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECROIConfigControlType ROIConfigControl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// bitDepth
    ///
    /// Tuning Level:  never_tune
    /// Description:   stats bit depth
    /// Default Value: 14
    /// Range:         [8,14]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                   bitDepth;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// siteSelection
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   select where in ISP stats are tapped out
    /// Default Value: BeforeDemosaic
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsSiteSelection   siteSelection;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pixelExpSelect
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   select short or long exposure pixels
    /// Default Value: ShortPixels
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsPixelExpSelect  pixelExpSelect;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// regionSampling
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   advanced sampling configuration
    /// Default Value: 65535
    /// Range:         [0,65535]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                   regionSampling;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// HistIndividualConfigType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct HistIndividualConfigType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// histogramType
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   identifies which histogram is being requested
    /// Default Value: HistogramHDRBHIST
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsHistogramType           histogramType;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// binUniformity
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   some histograms can be configured to output uneven bins with more resolution is shadows and less in
    ///                highlights
    /// Default Value: Even
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsHistogramUniformityType binUniformity;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// colorChannel
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   select histogram color channel
    /// Default Value: ChannelRGrB
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsHistogramChannelType    colorChannel;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// siteSelection
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   select where in ISP stats are tapped out
    /// Default Value: BeforeDemosaic
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsSiteSelection           siteSelection;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// pixelExpSelect
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   select short or long exposure pixels
    /// Default Value: ShortPixels
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECStatsPixelExpSelect          pixelExpSelect;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ROIConfigControl
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Select ROI configuration type. AECROIConfigControlTypeCroppedFOV means follow Zoomed FOV;
    ///                AECROIConfigControlTypeFullFOV means use Full FOV from Sensor. Default value:
    ///                AECROIConfigControlTypeCroppedFOV
    /// Default Value: AECROIConfigControlTypeCroppedFOV
    /// Range:         [0,1]
    /// Comments:       Core Stats Configuration Tuning Definition
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECROIConfigControlType         ROIConfigControl;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECHistStatsConfig
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AECHistStatsConfig
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ROIConfigControl
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Select ROI configuration type. AECROIConfigControlTypeCroppedFOV means follow Zoomed FOV;
    ///                AECROIConfigControlTypeFullFOV means use Full FOV from Sensor. Default value:
    ///                AECROIConfigControlTypeCroppedFOV
    /// Default Value: AECROIConfigControlTypeCroppedFOV
    /// Range:         [0,1]
    /// Comments:       Core Stats Configuration Tuning Definition
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECROIConfigControlType   ROIConfigControl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// histograms - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                    histogramsCount;
    UINT32                    histogramsID;
    HistIndividualConfigType* histograms;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECStatsConfig
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AECStatsConfig
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
    /// histStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECHistStatsConfig histStatsConfig;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// gridStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECGridStatsConfig gridStatsConfig;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECStatsConfigClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AECStatsConfigClass : public ParameterModule, public AECStatsConfig
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
    AECStatsConfigClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECStatsConfigClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~AECStatsConfigClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load AECGridStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadAECGridStatsConfig(
        ParameterFileSymbolTableEntry* entry,
        AECGridStatsConfig* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load HistIndividualConfigType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadHistIndividualConfigType(
        ParameterFileSymbolTableEntry* entry,
        HistIndividualConfigType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load AECHistStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadAECHistStatsConfig(
        ParameterFileSymbolTableEntry* entry,
        AECHistStatsConfig* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load AECStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadAECStatsConfig(
        ParameterFileSymbolTableEntry* entry,
        AECStatsConfig* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECStatsConfig::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECStatsConfig::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload AECHistStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadAECHistStatsConfig(
        AECHistStatsConfig* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload AECStatsConfig
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadAECStatsConfig(
        AECStatsConfig* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        AECStatsConfig::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class AECStatsConfigClass

AECSTATSCONFIG_NAMESPACE_END
#endif // AECSTATSCONFIG_H

