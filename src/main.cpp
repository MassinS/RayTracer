#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"
#include "math/vector.h"
#include "render/camera.h"

#include <iostream>

int main()
{
    Camera camera(Vector(0, 0, -1), Vector(0, 0, 0));
    Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));
    Ray ray = camera.rayThroughCentre();
    Colour pixel(0, 0, 0);

    if (sphere.isHitBy(ray))
    {
        pixel = sphere.colour();
    }

    std::cout << "(" << pixel.r() << ", " << pixel.g() << ", " << pixel.b() << ")\n";
    return 0;
}
