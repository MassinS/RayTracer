cmake_minimum_required(VERSION 3.21)

project(RayTracer VERSION 0.1.0 LANGUAGES CXX)

include(CTest)

add_library(raytracer_hello
    src/hello.cpp
    src/math/vector.cpp
    src/colour/colour.cpp
    src/geometry/ray.cpp
    src/geometry/sphere.cpp
    src/render/camera.cpp
    src/render/trace.cpp
)
target_include_directories(raytracer_hello PUBLIC include PRIVATE src)
target_compile_features(raytracer_hello PUBLIC cxx_std_17)

add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_hello)
target_include_directories(raytracer PRIVATE ${PROJECT_SOURCE_DIR}/src)

if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)

    include(Catch)
    add_subdirectory(tests)

    add_test(NAME raytracer_prints_pixel_colour COMMAND raytracer)
    set_tests_properties(raytracer_prints_pixel_colour PROPERTIES
        PASS_REGULAR_EXPRESSION "\\(1, 0, 0\\)"
    )
endif()
