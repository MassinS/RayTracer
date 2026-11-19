#include "math/vector.h"
#include "render/camera.h"
#include "render/trace.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("trace returns the sphere colour for a hit")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughCentre();
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));

    const Colour pixel = trace(ray, sphere);

    requireColoursEqual(pixel, Colour(1, 0, 0));
}

TEST_CASE("trace returns black for a miss")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughCentre();
    const Sphere sphere(Vector(6, 0, 9), 5, Colour(1, 0, 0));

    const Colour pixel = trace(ray, sphere);

    requireColoursEqual(pixel, Colour(0, 0, 0));
}
