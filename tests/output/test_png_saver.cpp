#include "image/image.h"
#include "output/png_saver.h"

#include <catch2/catch_test_macros.hpp>
#include <lodepng.h>

#include <string>
#include <vector>

TEST_CASE("PngSaver writes the image as RGB pixels")
{
    const std::string path = "test_png_saver.png";
    Image image(2, 2);
    image.setPixel(1, 0, Colour(1, 0.5, 0));

    const PngSaver saver;
    saver.save(image, path);

    std::vector<unsigned char> decoded;
    unsigned width = 0;
    unsigned height = 0;
    const unsigned error = lodepng::decode(decoded, width, height, path, LCT_RGB);
    REQUIRE(error == 0);
    REQUIRE(width == 2);
    REQUIRE(height == 2);

    const std::vector<int> actual(decoded.begin(), decoded.end());
    const std::vector<int> expected{
        0, 0, 0, 255, 128, 0,
        0, 0, 0, 0, 0, 0
    };
    REQUIRE(actual == expected);
}
