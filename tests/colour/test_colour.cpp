#include "colour/colour.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Colour returns its red green and blue components")
{
    const Colour colour(1, 0.5, 0);

    REQUIRE(colour.r() == 1);
    REQUIRE(colour.g() == 0.5);
    REQUIRE(colour.b() == 0);
}

TEST_CASE("A scalar on the left scales a colour")
{
    const Colour colour = 0.5 * Colour(1, 0.5, 0);

    requireColoursEqual(colour, Colour(0.5, 0.25, 0));
}
