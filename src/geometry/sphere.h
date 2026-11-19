#pragma once

#include "material/material.h"
#include "geometry/hit.h"
#include "geometry/shape.h"
#include "math/vector.h"
#include "geometry/ray.h"

#include <optional>

class Sphere : public Shape
{
public:
    Sphere(const Vector& centre, double radius, const Material& material);

    std::optional<Hit> hit(const Ray& ray) const override;

private:
    Vector _centre;
    double _radius;
    Material _material;
};
