cmake_minimum_required(VERSION 3.29)
project(cpp_sort)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Install Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Google Test (Windows): Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add src/ as SortStrategies library
add_library(SortStrategies INTERFACE)
target_include_directories(SortStrategies INTERFACE ${PROJECT_SOURCE_DIR}/src)

add_executable(
        sort_tests
        tests/test_quick_sort.cpp
        tests/test_bubble_sort.cpp
)

target_link_libraries(
        sort_tests
        SortStrategies
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sort_tests)
