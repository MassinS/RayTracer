# 0006: Organize Code by Concept

## Context

The project currently has only a few source files, but ray tracing will add
concepts such as vectors, rays, shapes, cameras, and images. Keeping every
source and test in flat folders will make related files harder to find as the
project grows.

## Decision

Organize source files into folders named for their concepts under `src/`, and
mirror that structure under `tests/`. Include project headers from the `src/`
root, such as `#include "math/vector.h"`.

## Status

Proposed

## Consequences

Related implementation and test files are easier to locate, and include paths
show which concept a header belongs to. The structure adds directories and
longer paths to a small project, and moving files requires updating includes
and build configuration. This organization does not create dependency
boundaries between concepts.

We deliberately defer:

- **Namespaces:** worth adding when names collide or partner studios need to
  use this code alongside their own types.
- **One library per folder:** worth adding when the build needs to prevent
  dependencies between concepts, or build times become a problem.
- **A separate `include/` folder:** worth adding when the ray tracer is shipped
  as a library and public headers must be separated from private ones.
