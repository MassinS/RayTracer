# 0007: Model Colour as a Separate Type

## Context

Both `Vector` and colour use three numeric components, but they represent
different concepts. A vector needs geometric operations such as dot product
and normalization. A colour represents red, green, and blue channels used by
materials and image pixels. Reusing `Vector` for colour would expose
operations that do not make sense for colours and would allow accidental
mixing of colours and geometric values.

The pinhole spike needs a `Colour` held by `Sphere`, and the future `Image`
will store a colour for each pixel.

## Decision

Represent colour with a dedicated `Colour` class containing red, green, and
blue components. `Sphere` stores a `Colour`, and `Image` will store colours
for its pixels. Do not use `Vector` to represent colour.

The class does not currently enforce a channel range. The policy for values
outside 0 to 1 remains open because lighting may produce values above 1.

## Status

Proposed

## Consequences

The type system distinguishes colour values from vectors, and the class
provides only colour-specific accessors. This adds a small class and its
associated tests, rather than reusing the existing `Vector` implementation.
Colour range handling and conversion to image-file values must be decided
when image output and lighting are implemented.

## Alternative Considered

Use `Vector` for the red, green, and blue components. This would avoid a
separate type, but would also expose geometric operations on colours and
make it possible to mix colours and vectors unintentionally.
