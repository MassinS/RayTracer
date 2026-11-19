# 0009: Use x-right, y-up, z-forward Coordinates

## Context

The camera and geometry use world coordinates, while image pixels are indexed
from the top left. The two systems must map consistently so that a row at the
top of the image represents points above the screen centre in the world.

## Decision

Use x to the right, y up, and z forward. Count image columns from the left and
rows from the top, both starting at zero. Aim camera rays toward positive z.
Place each ray through the centre of its pixel, converting the downward image
row direction to upward world y.

## Status

Proposed

## Consequences

The camera converts between image indices and world coordinates when it
computes pixel rays. This keeps image storage in the same top-to-bottom order
as PNG files while retaining an upward-positive y axis for geometry.

## Alternative Considered

Use negative z as the forward direction, as some ray-tracing references do.
That would also work, but would require changing the convention already used
by the pinhole spike and the ray-through-pixel calculations.
