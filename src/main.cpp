#include "colour/colour.h"
#include "geometry/sphere.h"
#include "image/image.h"
#include "math/vector.h"
#include "render/camera.h"
#include "output/png_saver.h"

#include <iostream>
#include <string>

int main()
{
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));
    Image image = camera.render(sphere, 400, 300);
    std::string path = "image.png";
    PngSaver saver;
    saver.save(image, path);

    std::cout << path << "\n";
    return 0;
}
