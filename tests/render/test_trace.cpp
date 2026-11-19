#include "math/vector.h"
#include "render/trace.h"
#include "material/material.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("trace returns the sphere colour for a fully lit hit")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    const Colour pixel = trace(ray, sphere, Vector(0, 0, -1));

    requireColoursEqual(pixel, Colour(1, 0, 0));
}

TEST_CASE("trace shades a sphere hit by the light direction")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    const Colour pixel = trace(ray, sphere, Vector(0.6, 0, -0.8));

    requireColoursEqual(pixel, Colour(0.8, 0, 0));
}

TEST_CASE("trace shades a sphere hit away from its centre line")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(
        trace(ray, sphere, Vector(0, 0, -1)),
        Colour(0.8, 0, 0));
}

TEST_CASE("trace returns black for a miss")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(
        trace(ray, sphere, Vector(0, 0, -1)),
        Colour(0, 0, 0));
}
