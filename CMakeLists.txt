cmake_minimum_required(VERSION 3.8.2)

project(rpcs3)

option(WITH_GDB "WITH_GDB" OFF)
option(USE_NATIVE_INSTRUCTIONS "USE_NATIVE_INSTRUCTIONS makes rpcs3 compile with -march=native, which is useful for local builds, but not good for packages." ON)

option(WITH_LLVM "Enable usage of LLVM library" ON)
option(BUILD_LLVM_SUBMODULE "Build LLVM from git submodule" ON)

option(USE_ALSA "ALSA audio backend" ON)
option(USE_PULSE "PulseAudio audio backend" ON)
option(USE_LIBEVDEV "libevdev-based joystick support" ON)

option(USE_SYSTEM_ZLIB "Prefer system ZLIB instead of the builtin one" ON)

option(USE_VULKAN "Vulkan render backend" ON)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/rpcs3/cmake_modules")

set(CMAKE_CXX_STANDARD 17)
include(CheckCXXCompilerFlag)

if (WITH_GDB)
	add_definitions(-DWITH_GDB_DEBUGGER)
endif()

if (NOT CMAKE_BUILD_TYPE)
	message(STATUS "No build type selected, default to Release")
	set(CMAKE_BUILD_TYPE "Release")
endif()

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions(-DNDEBUG)
endif()

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
	message( FATAL_ERROR "RPCS3 can only be compiled on 64-bit platforms." )
endif()

find_program(CCACHE_FOUND ccache)
if (CCACHE_FOUND)
	set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
	set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()

if(WIN32)
	add_definitions(-DUNICODE)
	add_definitions(-D_WIN32_WINNT=0x0602)
endif()

if(APPLE)
	include_directories(/opt/local/include)
	link_directories(/opt/local/lib)
endif()

add_subdirectory(Vulkan EXCLUDE_FROM_ALL)
add_subdirectory(asmjitsrc EXCLUDE_FROM_ALL)
add_subdirectory(3rdparty)

# TODO: do real installation, including copying directory structure
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${PROJECT_BINARY_DIR}/bin")

add_subdirectory(rpcs3)
