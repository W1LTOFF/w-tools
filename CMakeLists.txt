cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -Wall -w")
file(GLOB WTOOLS_LIB_SRC_CORE
    src/wtools/core/*.cpp
    src/wtools/system/windows/*.cpp
)

set(WTOOLS_LIB_SRC_ALL ${WTOOLS_LIB_SRC_CORE})

# option(WTOOLS_BUILD_EXAMLES ON)

project(w-tools)

# if (WTOOLS_BUILD_EXAMLES)
add_subdirectory(examples)
# endif()

add_library(${PROJECT_NAME} STATIC
    ${WTOOLS_LIB_SRC_ALL}
)

target_include_directories(w-tools PUBLIC
    src
)

