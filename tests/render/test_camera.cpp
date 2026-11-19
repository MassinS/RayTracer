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

TEST_CASE("Camera ray through the centre pixel points forward")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(2, 1, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("Camera ray through the top right pixel points up and right")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(4, 0, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(2, 1, 1));
}

TEST_CASE("Camera ray through the bottom left pixel points down and left")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(0, 2, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(-2, -1, 1));
}

TEST_CASE("Camera renders the sphere as a red plus on the pixel grid")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Sphere sphere(Vector(0, 0, 6), 5, Colour(1, 0, 0));
    const Image image = camera.render(sphere, 5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);

    for (int row = 0; row < image.height(); ++row)
    {
        for (int column = 0; column < image.width(); ++column)
        {
            const bool isRed =
                (column == 2) || (row == 1 && column >= 1 && column <= 3);
            const Colour expected = isRed
                ? Colour(1, 0, 0)
                : Colour(0, 0, 0);
            requireColoursEqual(image.pixel(column, row), expected);
        }
    }
}
