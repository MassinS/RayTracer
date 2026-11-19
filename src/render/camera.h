#pragma once

#include "math/vector.h"
#include "geometry/ray.h"

class Camera
{
public:
    Camera(const Vector& eye, const Vector& screenCentre, double screenWidth);

    Ray rayThroughCentre() const;

private:
    Vector _eye;
    Vector _screenCentre;
    double _screenWidth;
};
