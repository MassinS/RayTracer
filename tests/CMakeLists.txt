add_executable(raytracer_tests
    colour/test_colour.cpp
    geometry/test_ray.cpp
    hello_test.cpp
    math/test_vector.cpp
    render/test_camera.cpp
    test_helpers.cpp
)
target_include_directories(raytracer_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/tests
)
target_link_libraries(raytracer_tests PRIVATE raytracer_hello Catch2::Catch2WithMain)

catch_discover_tests(raytracer_tests)
