cmake_minimum_required(VERSION 2.8)
include(CMakeDependentOption)

if (NOT APPLE AND NOT WIN32)
message(FATAL_ERROR
"This dependency pack is intended for use on Apple OS X and MS Windows only. "
"For other systems, such as GNU/Linux, please consult your package manager or "
"distribution maintainer to discover how to install the libraries you wish to "
"use with CEGUI.  Thanks!")
endif()

if (APPLE)
    set( CMAKE_OSX_ARCHITECTURES x86_64 CACHE STRING "Build architectures for Mac OS X" )
    set( CMAKE_BUILD_TYPE Release CACHE STRING "Sets the configuration to build (Release, Debug, etc...)")
endif()
    if(MSVC OR MINGW OR SKBUILD) # other platforms dont need this
        message(STATUS "Download Dependencies")
        file(DOWNLOAD
            https://github.com/cegui/cegui-dependencies/archive/refs/tags/0.8.x.zip
            ${PROJECT_BINARY_DIR}/cegui-dependencies.tar.gz)
        execute_process(COMMAND ${CMAKE_COMMAND} 
            -E tar xf cegui-dependencies.tar.gz WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
        execute_process(COMMAND ${CMAKE_COMMAND}
            -E make_directory ${PROJECT_BINARY_DIR}/src)
        execute_process(COMMAND ${BUILD_COMMAND_COMMON}
            -DSDL_STATIC=FALSE
            ${PROJECT_BINARY_DIR}/cegui-dependencies
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/cegui-dependencies)
        execute_process(COMMAND ${CMAKE_COMMAND}
            --build ${PROJECT_BINARY_DIR}/SDL2-build ${BUILD_COMMAND_OPTS})
    endif()
