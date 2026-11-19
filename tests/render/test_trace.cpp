#include "geometry/sphere.h"
#include "math/vector.h"
#include "render/trace.h"
#include "material/material.h"
#include "scene/scene.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

#include <memory>

TEST_CASE("trace returns the sphere colour for a fully lit hit")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));

    const Colour pixel = trace(ray, scene);

    requireColoursEqual(pixel, Colour(1, 0, 0));
}

TEST_CASE("trace shades a sphere hit by the light direction")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0.6, 0, -0.8));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));

    const Colour pixel = trace(ray, scene);

    requireColoursEqual(pixel, Colour(0.8, 0, 0));
}

TEST_CASE("trace shades a sphere hit away from its centre line")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(3, 0, 9), 5, Material(Colour(1, 0, 0))));

    requireColoursEqual(
        trace(ray, scene),
        Colour(0.8, 0, 0));
}

TEST_CASE("trace returns black for a miss")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));

    requireColoursEqual(
        trace(ray, scene),
        Colour(0, 0, 0));
}
