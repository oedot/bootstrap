#
cmake_minimum_required(VERSION 3.6.0)
#
project(Bootstrap VERSION 1.0.0)

#
add_executable(
    Bootstrap
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
)

#
target_compile_features(
    Bootstrap
        INTERFACE
            cxx_std_17
)
