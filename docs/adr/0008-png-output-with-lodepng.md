# 0008: Save PNG Images with LodePNG

## Context

The client needs images that open in ordinary viewers. PNG is lossless, so
saved pixel values can be checked exactly, and its compression and checksums
make implementing the format ourselves unnecessarily costly.

We compared:

- **libpng:** the reference library, but its C API takes many calls to save one
  image, and it is not in the dev container.
- **stb_image_write:** a single public-domain header, but a C API with raw
  pointers and larger PNG files.
- **LodePNG:** one `.cpp` and one `.h`, zlib licence, no dependencies, and a
  C++ API using `std::vector`; it is slower at saving than the other libraries.
- **PPM written by hand:** no library dependency, but most viewers cannot open
  it and its files are much larger.

## Decision

Use LodePNG from <https://github.com/lvandeve/lodepng>, fetched by CMake and
pinned to commit `7b2893e35891c0c85bee5595caafaf3c2044b409`. Only code in
`src/output/` may use it, behind the project's `ImageSaver` interface, so a
different format or library can be added as another saver.

## Status

Proposed

## Consequences

The first configure needs network access to fetch LodePNG. Pinning a commit
without a release identifies the exact code in use, and upgrades require an
intentional pin change. Saving is slower than with the other libraries.
`ImageSaver` adds an abstraction layer while there is only one implementation;
it keeps the library-specific API inside the output code.
