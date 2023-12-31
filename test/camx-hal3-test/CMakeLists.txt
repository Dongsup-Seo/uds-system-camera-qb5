# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# Common Include
include (${CMAKE_CURRENT_LIST_DIR}/../../core/build/linuxembedded/common.cmake)

add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
add_definitions ( -DLINUX_ENABLED )
add_definitions ( -DUSE_GBM )
add_definitions ( -DDISABLE_META_MODE=1 )
add_definitions ( -DCAMERA_STORAGE_DIR="/data/misc/camera/" )
if (DEFINED ENABLE_VIDEO_ENCODER)
add_definitions ( -DENABLE_VIDEO_ENCODER)
endif ()

# Include Paths
include_directories (.)

include_directories (${CAMX_C_INCLUDES})

# kernel headers
include_directories (${KERNEL_INCDIR}/usr/include)

# media headers
include_directories (${SYSTEM_INC_PATH}/media/hardware)
include_directories (${SYSTEM_INC_PATH}/libstagefrighthw)
include_directories (${SYSTEM_INC_PATH}/mm-core)

set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Bdynamic")

#########################################libomx_encoder#########################################################
if (DEFINED ENABLE_VIDEO_ENCODER)
add_library( libomx_encoder SHARED
    QCamxHAL3TestOMXEncoder.cpp
    QCamxHAL3TestVideoEncoder.cpp
    QCamxHAL3TestDevice.cpp
)

target_link_libraries (libomx_encoder cutils)
target_link_libraries (libomx_encoder utils)
target_link_libraries (libomx_encoder log)
#target_link_libraries (libomx_encoder hardware)
target_link_libraries (libomx_encoder OmxCore)

set (OMXENCODER_INCLUDE_HEADERS
    QCamxHAL3TestOMXEncoder.h
)

install (TARGETS libomx_encoder LIBRARY DESTINATION /usr/lib/ )
install(FILES ${OMXENCODER_INCLUDE_HEADERS} DESTINATION include )
endif ()
#########################################camx-hal3-test#########################################################
add_custom_target (autogen_version_camxtest ALL
    COMMAND perl ${CMAKE_CURRENT_LIST_DIR}/version.pl ${CMAKE_CURRENT_LIST_DIR}/g_version.h
    COMMENT "autogen version file"
)

# Files and Build Type
add_executable( camx-hal3-test
     QCamxHAL3TestCase.cpp
     QCamxHAL3TestBufferManager.cpp
     QCamxHAL3TestDevice.cpp
     QCamxHAL3TestSnapshot.cpp
     QCamxHAL3TestMain.cpp
     QCamxHAL3TestVideo.cpp
     QCamxHAL3TestConfig.cpp
     QCamxHAL3TestPreviewOnly.cpp
     QCamxHAL3TestVideoOnly.cpp
     QCamxHAL3TestLog.cpp
)

add_dependencies( camx-hal3-test
    autogen_version_camxtest
)

# Libraries to compile
target_link_libraries (camx-hal3-test cutils)
target_link_libraries (camx-hal3-test utils)
target_link_libraries (camx-hal3-test log)
#target_link_libraries (camx-hal3-test hardware)
target_link_libraries (camx-hal3-test camera_metadata)
target_link_libraries (camx-hal3-test gbm)
if (DEFINED ENABLE_VIDEO_ENCODER)
target_link_libraries (camx-hal3-test libomx_encoder)
endif ()

install (TARGETS camx-hal3-test RUNTIME DESTINATION /usr/bin/ )
#########################################libcamxffbm_utils#########################################################
#add_library( libcamxffbm_utils SHARED
#     QCamxHAL3TestBufferManager.cpp
#     QCamxHAL3TestDevice.cpp
#     QCamxHAL3TestCase.cpp
#     QCamxHAL3TestPreviewOnly.cpp
#     QCamxHAL3TestSnapshot.cpp
#     QCamxHAL3TestConfig.cpp
#     QCamxHAL3TestLog.cpp
#)

#target_link_libraries (libcamxffbm_utils cutils)
#target_link_libraries (libcamxffbm_utils utils)
#target_link_libraries (libcamxffbm_utils log)
#target_link_libraries (libcamxffbm_utils hardware)
#target_link_libraries (libcamxffbm_utils camera_metadata)
#target_link_libraries (libcamxffbm_utils glib-2.0)
#target_link_libraries (libcamxffbm_utils dl)
#target_link_libraries (libcamxffbm_utils stdc++)
#target_link_libraries (libcamxffbm_utils atomic)
#target_link_libraries (libcamxffbm_utils pthread)
#target_link_libraries (libcamxffbm_utils camera_client)
#target_link_libraries (libcamxffbm_utils gbm)

#set (FASTMMI_INCLUDE_HEADERS
#    QCamxHAL3TestConfig.h
#    QCamxHAL3TestCase.h
#    QCamxHAL3TestPreviewOnly.h
#    QCamxHAL3TestSnapshot.h
#    QCamxHAL3TestDevice.h
#    QCamxHAL3TestBufferManager.h
#    QCamxHAL3TestLog.h
#)

#install(TARGETS libcamxffbm_utils LIBRARY DESTINATION /usr/lib/ )
#install(FILES ${FASTMMI_INCLUDE_HEADERS} DESTINATION include )
###############################################################################################################
