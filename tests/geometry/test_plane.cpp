#include "geometry/plane.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("Plane hit returns the floor intersection and its material")
{
    const Plane floor(
        Vector(0, 0, 0), Vector(0, 1, 0), Material(Colour(0, 1, 0)));
    const Ray ray(Vector(0, 8, 0), Vector(3, -4, 0));

    const std::optional<Hit> hit = floor.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(2, tolerance));
    requireVectorsEqual(hit->point, Vector(6, 0, 0));
    requireVectorsEqual(hit->normal, Vector(0, 1, 0));
    requireColoursEqual(hit->material.colour(), Colour(0, 1, 0));
}

TEST_CASE("Plane hit normalises a non-unit normal")
{
    const Plane plane(
        Vector(8, 0, 0), Vector(3, 4, 0), Material(Colour(0, 1, 0)));
    const Ray ray(Vector(-8, 0, 0), Vector(4, 3, 0));

    const std::optional<Hit> hit = plane.hit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(2, tolerance));
    requireVectorsEqual(hit->point, Vector(0, 6, 0));
    requireVectorsEqual(hit->normal, Vector(0.6, 0.8, 0));
}

TEST_CASE("Plane does not hit a parallel ray")
{
    const Plane floor(
        Vector(0, 0, 0), Vector(0, 1, 0), Material(Colour(0, 1, 0)));
    const Ray ray(Vector(0, 8, 0), Vector(5, 0, 0));

    REQUIRE_FALSE(floor.hit(ray).has_value());
}

TEST_CASE("Plane does not hit behind the ray origin")
{
    const Plane floor(
        Vector(0, 0, 0), Vector(0, 1, 0), Material(Colour(0, 1, 0)));
    const Ray ray(Vector(0, 8, 0), Vector(3, 4, 0));

    REQUIRE_FALSE(floor.hit(ray).has_value());
}
