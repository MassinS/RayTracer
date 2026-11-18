cmake_minimum_required(VERSION 3.21)

project(RayTracer VERSION 0.1.0 LANGUAGES CXX)

include(CTest)

add_library(raytracer_hello
    src/hello.cpp
)
target_include_directories(raytracer_hello PUBLIC include)
target_compile_features(raytracer_hello PUBLIC cxx_std_17)

add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_hello)

if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(raytracer_tests tests/hello_test.cpp)
    target_link_libraries(raytracer_tests PRIVATE raytracer_hello Catch2::Catch2WithMain)

    include(Catch)
    catch_discover_tests(raytracer_tests)

    add_test(NAME raytracer_prints_hello_world COMMAND raytracer)
    set_tests_properties(raytracer_prints_hello_world PROPERTIES
        PASS_REGULAR_EXPRESSION "Hello, World!"
    )
endif()
