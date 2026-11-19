#include "geometry/sphere.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Sphere centered on the ray is hit")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere three units off the ray is hit")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(3, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere six units off the ray is missed")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere behind the ray origin is missed")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, -11), 5, Colour(1, 0, 0));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere returns its colour")
{
    const Colour colour(1, 0, 0);
    const Sphere sphere(Vector(0, 0, 9), 5, colour);
    const Colour actual = sphere.colour();

    REQUIRE(actual.r() == 1);
    REQUIRE(actual.g() == 0);
    REQUIRE(actual.b() == 0);
}
