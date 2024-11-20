#Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.29)

#Project's name
project(CMakeTutorial)

#Set the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#OpenGL required
find_package(OpenGL REQUIRED)

#Fetch SFML
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

#spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.x  # Replace with the desired version tag
)
FetchContent_MakeAvailable(spdlog)

# For multi-config generators, add 'DIST' to the configuration types
if(CMAKE_CONFIGURATION_TYPES)
  list(APPEND CMAKE_CONFIGURATION_TYPES DIST)
  set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
      "Available build configurations" FORCE)
endif()

# Default to DIST if no build type is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "DIST" CACHE STRING "Build type" FORCE)
endif()

# Define variables for the DIST configuration
set(CMAKE_C_FLAGS_DIST "${CMAKE_C_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_DIST "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_EXE_LINKER_FLAGS_DIST "${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
set(CMAKE_SHARED_LINKER_FLAGS_DIST "${CMAKE_SHARED_LINKER_FLAGS_RELEASE}")

# Display the build type in the terminal
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}: ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}}")

# Add subdirectories (subprojects)
add_subdirectory(Client)
add_subdirectory(Abacaxiano)

#Set client as the startup project for Visual Studio users
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Client)