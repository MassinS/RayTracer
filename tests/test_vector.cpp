#include "vector.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("adding vectors adds their coordinates")
{
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);
    const Vector sum = first + second;

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 0);
}

TEST_CASE("adding vectors adds nonzero z coordinates")
{
    const Vector first(3, 4, 1);
    const Vector second(4, -3, 2);
    const Vector sum = first + second;

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 3);
}

TEST_CASE("subtracting vectors subtracts their coordinates")
{
    const Vector first(4, 5, 0);
    const Vector second(1, 1, 0);
    const Vector difference = first - second;

    REQUIRE(difference.x() == 3);
    REQUIRE(difference.y() == 4);
    REQUIRE(difference.z() == 0);

    const Vector third(4, 5, 6);
    const Vector fourth(1, 1, 2);
    const Vector difference_with_nonzero_z = third - fourth;

    REQUIRE(difference_with_nonzero_z.x() == 3);
    REQUIRE(difference_with_nonzero_z.y() == 4);
    REQUIRE(difference_with_nonzero_z.z() == 4);
}

TEST_CASE("a scalar on the left scales a vector")
{
    const Vector vector(3, -4, 1);
    const Vector scaled = 2.0 * vector;

    REQUIRE(scaled.x() == 6);
    REQUIRE(scaled.y() == -8);
    REQUIRE(scaled.z() == 2);
}

TEST_CASE("the ray equation gives a point along the ray")
{
    const Vector O(0, 8, 0);
    const Vector D(3, -4, 0);
    const double t = 2;
    const Vector point = O + t * D;

    REQUIRE(point.x() == 6);
    REQUIRE(point.y() == 0);
    REQUIRE(point.z() == 0);
}

TEST_CASE("dot product returns the sum of coordinate products")
{
    const Vector first(3, 4, 0);
    const Vector second(4, 3, 0);

    REQUIRE(first.dot(second) == 24);
}

TEST_CASE("dot product can be zero")
{
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);

    REQUIRE(first.dot(second) == 0);
}

TEST_CASE("dot product includes the z coordinate")
{
    const Vector first(3, 4, 12);
    const Vector second(4, 3, 1);

    REQUIRE(first.dot(second) == 36);
}

TEST_CASE("length returns the vector magnitude")
{
    const Vector vector(3, -4, 0);

    REQUIRE(vector.length() == 5);
}

TEST_CASE("length includes the z coordinate")
{
    const Vector vector(3, 4, 12);

    REQUIRE(vector.length() == 13);
}

TEST_CASE("normalised returns a vector in the same direction")
{
    const Vector vector(3, -4, 0);
    const Vector normalised = vector.normalised();

    REQUIRE_THAT(normalised.x(), Catch::Matchers::WithinAbs(0.6, 1e-9));
    REQUIRE_THAT(normalised.y(), Catch::Matchers::WithinAbs(-0.8, 1e-9));
    REQUIRE_THAT(normalised.z(), Catch::Matchers::WithinAbs(0, 1e-9));
}

TEST_CASE("normalised vectors have length one")
{
    const Vector vector(3, 4, 12);

    REQUIRE_THAT(vector.normalised().length(),
                 Catch::Matchers::WithinAbs(1, 1e-9));
}
