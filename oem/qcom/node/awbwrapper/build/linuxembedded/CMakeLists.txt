# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.stats.awbwrapper SHARED
    ../../src/awbwrapper.cpp
)

# Libraries to compile
target_link_libraries (com.qti.stats.awbwrapper camxosutils)
target_link_libraries (com.qti.stats.awbwrapper camxutils)
target_link_libraries (com.qti.stats.awbwrapper camxgenerated)
target_link_libraries (com.qti.stats.awbwrapper dl)
target_link_libraries (com.qti.stats.awbwrapper cutils)
target_link_libraries (com.qti.stats.awbwrapper log)
target_link_libraries (com.qti.stats.awbwrapper offlinelog)
target_link_libraries (com.qti.stats.awbwrapper sync)
target_link_libraries (com.qti.stats.awbwrapper camximageformatutils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_API_PATH}/common)
include_directories (${CAMX_CHICDK_API_PATH}/stats)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/node/awbwrapper/inc)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.stats.awbwrapper autogen)

install(TARGETS com.qti.stats.awbwrapper LIBRARY DESTINATION lib/${CAMX_LIB_OUTPUT_PATH})

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

