#pragma once

#include "math/vector.h"
#include "geometry/ray.h"

class Camera
{
public:
    Camera(const Vector& eye, const Vector& screenCentre, double screenWidth);

    Ray rayThroughCentre() const;
    Ray rayThroughPixel(int column, int row, int width, int height) const;

private:
    Vector _eye;
    Vector _screenCentre;
    double _screenWidth;
};
