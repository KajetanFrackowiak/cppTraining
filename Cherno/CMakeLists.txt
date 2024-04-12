cmake_minimum_required(VERSION 3.14)
project(cherno VERSION 0.1.0 LANGUAGES CUDA CXX)

include(CTest)
enable_testing()

# Check for CUDA
find_package(CUDAToolkit REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Gather C++ and CUDA sources
file(GLOB CPP_SOURCES "*.cpp")
file(GLOB CUDA_SOURCES "*.cu")

# Add CUDA language explicitly
enable_language(CUDA)

# Add executable
add_executable(cherno Maps.cpp ${CPP_SOURCES} ${CUDA_SOURCES})

# Include OpenCV
find_package(OpenCV REQUIRED PATHS /usr NO_DEFAULT_PATH)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(cherno ${OpenCV_LIBS})

# Set CPack metadata
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
