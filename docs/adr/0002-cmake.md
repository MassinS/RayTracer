# 0002: Use CMake and CTest

## Context

The project needs a maintainable, cross-platform C++ build and automated test
execution to detect regressions as the ray tracer evolves. Alternatives include
Meson, Bazel, or hand-written Makefiles for building, and running test
executables directly instead of using CTest. The repository targets C++17 and
documents GCC, Clang, and MSVC as compiler options.

## Decision

Use CMake with the `unix-debug` Ninja preset to manage configuration and
compilation. Use CTest to discover and run tests as part of the CMake workflow.

## Status

Proposed

## Consequences

Native builds require CMake 3.21 or newer and Ninja. Contributors must learn
CMake's preset workflow and CTest's test-running workflow; tests must be
registered or discovered in the CMake project to run through CTest.
