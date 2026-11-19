#include "image/image.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Image reports its width and height")
{
    const Image image(5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);
}

TEST_CASE("Image pixels start black")
{
    const Image image(5, 3);

    for (int row = 0; row < image.height(); ++row)
    {
        for (int column = 0; column < image.width(); ++column)
        {
            requireColoursEqual(image.pixel(column, row), Colour(0, 0, 0));
        }
    }
}

TEST_CASE("setting a pixel changes only that pixel")
{
    Image image(5, 3);
    image.setPixel(4, 0, Colour(1, 0, 0));

    for (int row = 0; row < image.height(); ++row)
    {
        for (int column = 0; column < image.width(); ++column)
        {
            const Colour expected = column == 4 && row == 0
                ? Colour(1, 0, 0)
                : Colour(0, 0, 0);
            requireColoursEqual(image.pixel(column, row), expected);
        }
    }
}
