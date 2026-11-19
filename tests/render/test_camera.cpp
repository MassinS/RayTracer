#include "render/camera.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Camera ray through the centre starts at the eye")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughCentre();

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("Camera ray direction is screen centre minus eye")
{
    const Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2);
    const Ray ray = camera.rayThroughCentre();

    requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}
