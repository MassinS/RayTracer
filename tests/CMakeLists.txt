add_executable(raytracer_tests
    hello_test.cpp
    math/test_vector.cpp
)
target_include_directories(raytracer_tests PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(raytracer_tests PRIVATE raytracer_hello Catch2::Catch2WithMain)

catch_discover_tests(raytracer_tests)
