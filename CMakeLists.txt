cmake_minimum_required(VERSION 3.0)
project(CppEdu)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable recursive search for source files
file(GLOB_RECURSE CPP_SOURCES "lambdas/*.cpp")

# Iterate over the found source files and create a binary for each one
foreach(CPP_FILE ${CPP_SOURCES})
    # Isolate parent folder name
    get_filename_component(DIR ${CPP_FILE} DIRECTORY)
    get_filename_component(DIR "${DIR}" NAME)

    # Get the base name of the file (without extension)
    get_filename_component(BASE_NAME ${CPP_FILE} NAME_WE)

    # Create an executable target for each source file
    add_executable(${DIR}_${BASE_NAME} ${CPP_FILE})
    set_target_properties(${DIR}_${BASE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./bin)
endforeach()