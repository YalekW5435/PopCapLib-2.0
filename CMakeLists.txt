################################################################################
# Project definition
################################################################################
cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
project(PopLib C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "\${ORIGIN}")

################################################################################
# External projects
################################################################################
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
    GIT_SHALLOW ON
    OVERRIDE_FIND_PACKAGE
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
    FETCHCONTENT_UPDATES_DISCONNECTED TRUE
    EXCLUDE_FROM_ALL
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/${name}
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

################################################################################
# Compiler Option
################################################################################
if (MSVC)
    set(warn_flags "")
else ()
    set(warn_flags
        "-Wall"
        "-Wextra"
    )

    if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND UNIX)
        set(warn_flags
            ${warn_flags}
            "-fsanitize=address,undefined"
        )
    endif ()
endif ()

add_executable(${PROJECT_NAME})
target_compile_options(${PROJECT_NAME} PRIVATE ${warn_flags})

target_link_libraries(PopLib PRIVATE sfml-graphics)

if(WIN32)
    add_custom_command(
        TARGET PopLib
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:PopLib>
        VERBATIM)
endif()

################################################################################
# Sub-Directories
################################################################################
add_subdirectory(src)