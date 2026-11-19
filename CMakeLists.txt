cmake_minimum_required(VERSION 3.21)

project(RayTracer VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
include(FetchContent)

FetchContent_Declare(
    lodepng
    GIT_REPOSITORY https://github.com/lvandeve/lodepng.git
    GIT_TAG 7b2893e35891c0c85bee5595caafaf3c2044b409
)
FetchContent_MakeAvailable(lodepng)

add_library(lodepng STATIC ${lodepng_SOURCE_DIR}/lodepng.cpp)
target_include_directories(lodepng PUBLIC ${lodepng_SOURCE_DIR})

add_library(raytracer_hello
    src/math/vector.cpp
    src/colour/colour.cpp
    src/material/material.cpp
    src/geometry/ray.cpp
    src/geometry/sphere.cpp
    src/image/image.cpp
    src/output/png_saver.cpp
    src/render/camera.cpp
    src/render/trace.cpp
)
target_include_directories(raytracer_hello PRIVATE src)
target_compile_features(raytracer_hello PUBLIC cxx_std_17)
target_link_libraries(raytracer_hello PRIVATE lodepng)

add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_hello)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src)

if(BUILD_TESTING)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)

    include(Catch)
    add_subdirectory(tests)

    add_test(NAME raytracer_saves_image COMMAND raytracer)
    set_tests_properties(raytracer_saves_image PROPERTIES
        PASS_REGULAR_EXPRESSION "image\\.png"
    )
endif()
