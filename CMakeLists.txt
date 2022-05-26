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

#
include(FetchContent)

#
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.7
)

#
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v0.1.36
)

#
FetchContent_MakeAvailable(glfw glad)

#
target_link_libraries(
    Bootstrap
        PRIVATE
            glfw
            glad
)
