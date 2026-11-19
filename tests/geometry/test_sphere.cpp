#include "geometry/sphere.h"
#include "material/material.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("Sphere centered on the ray is hit")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere three units off the ray is hit")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere six units off the ray is missed")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere behind the ray origin is missed")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, -11), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere returns its colour")
{
    const Colour colour(1, 0, 0);
    const Sphere sphere(Vector(0, 0, 9), 5, Material(colour));
    const Colour actual = sphere.colour();

    requireColoursEqual(actual, colour);
}

TEST_CASE("Sphere hit returns the nearest point and outward normal")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    const std::optional<Hit> hit = sphere.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(5, tolerance));
    requireVectorsEqual(hit->point, Vector(0, 0, 4));
    requireVectorsEqual(hit->normal, Vector(0, 0, -1));
    requireColoursEqual(hit->material.colour(), Colour(1, 0, 0));
}

TEST_CASE("Sphere hit works away from the centre line")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(
        Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    const std::optional<Hit> hit = sphere.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(6, tolerance));
    requireVectorsEqual(hit->point, Vector(0, 0, 5));
    requireVectorsEqual(hit->normal, Vector(-0.6, 0, -0.8));
}

TEST_CASE("Sphere hit misses when the ray passes outside")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(
        Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.hit(ray).has_value());
}

TEST_CASE("Sphere hit misses behind the ray origin")
{
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(
        Vector(0, 0, -11), 5, Material(Colour(1, 0, 0)));

    REQUIRE_FALSE(sphere.hit(ray).has_value());
}
