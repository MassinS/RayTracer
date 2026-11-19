#include "geometry/plane.h"
#include "geometry/sphere.h"
#include "scene/scene.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <memory>

TEST_CASE("Scene returns the nearer plane when added after the sphere")
{
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, 0, 2), Vector(0, 0, -1), Material(Colour(0, 0, 1))));
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    const std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(3, 1e-9));
    REQUIRE(hit->material.colour().b() == 1);
}

TEST_CASE("Scene returns the nearer sphere when added before the plane")
{
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, 0, 20), Vector(0, 0, -1), Material(Colour(0, 0, 1))));
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    const std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(5, 1e-9));
    REQUIRE(hit->material.colour().r() == 1);
}

TEST_CASE("Scene returns no hit when none of its shapes are hit")
{
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    REQUIRE_FALSE(scene.nearestHit(ray).has_value());
}
