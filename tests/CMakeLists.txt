add_executable(raytracer_tests
    colour/test_colour.cpp
    geometry/test_ray.cpp
    geometry/test_sphere.cpp
    geometry/test_plane.cpp
    image/test_image.cpp
    math/test_vector.cpp
    material/test_material.cpp
    output/test_png_saver.cpp
    render/test_camera.cpp
    render/test_trace.cpp
    scene/test_scene.cpp
    test_helpers.cpp
)
target_include_directories(raytracer_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/tests
)
target_link_libraries(raytracer_tests PRIVATE raytracer_hello Catch2::Catch2WithMain lodepng)

catch_discover_tests(raytracer_tests)
