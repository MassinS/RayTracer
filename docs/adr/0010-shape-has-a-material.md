# 0010: A Shape Has a Material

## Context

The renderer needs different geometry, such as spheres and planes, to use
different surface materials. Geometry and appearance are separate concepts:
the shape determines where a ray hits, while the material determines how the
surface responds to light.

## Decision

Each concrete shape owns a `Material` and includes it in its `Hit` result.
Shapes implement the common `Shape` interface, while materials provide colour
and shading behavior. This is composition: a sphere has a material, and a
plane has a material.

## Status

Proposed

## Consequences

New geometry can implement `Shape` and own a material without changing the
existing material classes. New materials can be composed with shapes without
creating a separate geometry subclass for every combination. A hit carries a
copy of the material used at that surface.

## Alternative Considered

Use inheritance to create classes such as `MatteSphere`, `MirrorSphere`,
`MattePlane`, and `MirrorPlane`. Each new shape and material combination would
require another subclass, multiplying the classes as the renderer grows.
