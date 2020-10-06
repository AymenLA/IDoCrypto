cmake_minimum_required (VERSION 2.6)

project (idocrypto)

# The version number.
set (affi_VERSION_MAJOR 1)
set (affi_VERSION_MINOR 0)

# sources and headers dir for the main application
set(SOURCE_DIR src)
set(TOOLS_SOURCE_DIR ../tools/src)
set(INCLUDE_DIR include)
set(TOOLS_INCLUDE_DIR ../tools/include)
set(DEF_INCLUDE_DIR ../defines)

# sources and headers dir for the test application - NOT USED
# set(TEST_DIR tests/test_storage)

# config file and header for the configuration - NOT USED
# set(CONFIG_DIR config)

# the install dir
set(INSTALL_DIR install/usr/local/bin)

# additional includes
include_directories(${INCLUDE_DIR} ${TOOLS_INCLUDE_DIR} ${DEF_INCLUDE_DIR})

# main file will be the master of the opration
# get_config file allows to read the configuration and to choose how to do stuff
# build_configuration will automatically generate the configuration file to be used and will update it whenever it changes
# csv_order file will generate cvs paterns
# binary_order will generate binary counter file

set(TARGET_SOURCES ${SOURCE_DIR}/main.c ${SOURCE_DIR}/configure.c ${SOURCE_DIR}/idocrypto.c ${TOOLS_SOURCE_DIR}/dump.c)
set(HEADER_FILES ${INCLUDE_DIR}/idocrypto.h ${INCLUDE_DIR}/config.h ${INCLUDE_DIR}/config.h ${TOOLS_INCLUDE_DIR}/dump.h ${DEF_INCLUDE_DIR}/app_error_codes.h) 

add_definitions(-DDEBUG_L1=1)
add_definitions(-DBUILD_APP)

#add_custom_target(tests)
add_executable(idocrypto ${TARGET_SOURCES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES(idocrypto crypto)