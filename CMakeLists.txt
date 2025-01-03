cmake_minimum_required(VERSION 3.10...3.29)
project(softloq-whatwg-infra-project VERSION 1.0.0 LANGUAGES CXX)
option(BUILD_SHARED_LIBS "Generate Shared Library" OFF)
option(SOFTLOQ_MULTITHREADING "Generate with Multithreading Support" OFF)
option(SOFTLOQ_WHATWG_INFRA_BUILD_TESTING "Generate Unit-Testing" OFF)

# Build settings
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()
if(NOT CMAKE_CXX_STANDARD_REQUIRED)
    set(CMAKE_CXX_STANDARD_REQUIRED)
endif()
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

include(CTest)

# Default values
set(LIBRARY_TYPE STATIC)
set(PUBLIC_DEFINITIONS "")
set(PRIVATE_DEFINITIONS "")
set(PUBLIC_LINK_LIBRARIES "")
set(PRIVATE_LINK_LIBRARIES "")
set(MT_LIBRARY "")

# Library settings
if(BUILD_SHARED_LIBS)
    set(LIBRARY_TYPE SHARED)
    list(APPEND PUBLIC_DEFINITIONS SOFTLOQ_WHATWG_INFRA_USE_API)
    list(APPEND PRIVATE_DEFINITIONS SOFTLOQ_WHATWG_INFRA_BUILD_API)
endif()

if(SOFTLOQ_MULTITHREADING)
    include(FindThreads)
    list(APPEND PUBLIC_DEFINITIONS SOFTLOQ_MULTITHREADING)
    list(APPEND MT_LIBRARY Threads::Threads)
endif()

# Library build
file(GLOB_RECURSE CXX_FILES src/**.cpp)
add_library(softloq-whatwg-infra ${LIBRARY_TYPE} ${CXX_FILES})
add_library(softloq::whatwg-infra ALIAS softloq-whatwg-infra)
target_include_directories(softloq-whatwg-infra PUBLIC include)
target_compile_definitions(softloq-whatwg-infra PUBLIC ${PUBLIC_DEFINITIONS})
target_compile_definitions(softloq-whatwg-infra PRIVATE ${PRIVATE_DEFINITIONS})
target_link_libraries(softloq-whatwg-infra PUBLIC ${PUBLIC_LINK_LIBRARIES})
target_link_libraries(softloq-whatwg-infra PRIVATE ${PRIVATE_LINK_LIBRARIES} ${MT_LIBRARY})

# Unit testing
if(BUILD_TESTING AND SOFTLOQ_WHATWG_INFRA_BUILD_TESTING)
    add_executable(softloq-whatwg-infra-test tests/example.cpp)
    add_dependencies(softloq-whatwg-infra-test softloq::whatwg-infra)
    target_link_libraries(softloq-whatwg-infra-test PRIVATE softloq::whatwg-infra ${MT_LIBRARY})
endif()
