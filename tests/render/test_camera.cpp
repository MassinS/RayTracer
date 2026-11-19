#include "geometry/sphere.h"
#include "render/camera.h"
#include "material/material.h"
#include "scene/scene.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

#include <memory>

TEST_CASE("Camera ray through its only pixel starts at the eye")
{
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("Camera ray through its only pixel points to the screen centre")
{
    const Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2);
    const Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

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
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 6), 5, Material(Colour(1, 0, 0))));
    const Image image = camera.render(scene, 5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);

    for (int row = 0; row < image.height(); ++row)
    {
        for (int column = 0; column < image.width(); ++column)
        {
            const bool isCentre = row == 1 && column == 2;
            const bool isNeighbour =
                (row == 1 && (column == 1 || column == 3)) ||
                (column == 2 && (row == 0 || row == 2));
            const Colour expected = isCentre
                ? Colour(1, 0, 0)
                : isNeighbour ? Colour(0.8, 0, 0) : Colour(0, 0, 0);
            requireColoursEqual(image.pixel(column, row), expected);
        }
    }
}
