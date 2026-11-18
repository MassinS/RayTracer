# RayTracer

This repository is the starting point for a student C++ ray tracer project.
For now, it contains a small Hello World program and a test setup.

## Build strategy

The project uses CMake as its cross-platform build system and requires a
C++17-capable compiler. CMake works with GCC and Clang on Linux/macOS, and with
MSVC on Windows.

For a consistent toolchain across computers, the repository also includes a
VS Code Dev Container based on Ubuntu 24.04. VS Code users with Docker and the
Dev Containers extension can open the project and choose **Reopen in
Container**. Zed users can build natively with CMake, or use the same container
through the Dev Container CLI:

```sh
devcontainer up --workspace-folder .
devcontainer exec --workspace-folder . cmake --preset unix-debug
devcontainer exec --workspace-folder . cmake --build --preset unix-debug
devcontainer exec --workspace-folder . ctest --preset unix-debug
devcontainer exec --workspace-folder . ./build/unix-debug/raytracer
```

The one-click container workflow is provided by VS Code; the CLI commands can
also be run from a terminal outside the editor.

## Requirements

- GNU Make for the short commands below
- CMake 3.21 or newer
- Ninja
- A C++17 compiler (GCC, Clang, or MSVC), unless using the dev container
- Git and an internet connection for the initial test-enabled configure, to
  download Catch2
- Docker, plus the VS Code Dev Containers extension or Dev Container CLI, to
  use the dev container

## Build, run, test, and clean

From the repository root, GNU Make provides short commands for the CMake
preset workflow. These commands use the Unix-oriented preset and are intended
for Unix-like systems or the dev container; on Windows, use the dev container:

```sh
make build
make run
make test
make clean
```

`make build` configures and compiles the project. `make run` builds, then runs
the program. `make test` builds, then runs the Catch2 and output tests through
CTest. `make clean` removes the generated `build/` directory.

It prints:

```text
Hello, World!
```

## Test-driven development

Tests use [Catch2](https://github.com/catchorg/Catch2) and integrate with
CMake's CTest runner. Tests are enabled by default. For a TDD cycle, add or
update a test in `tests/`, run `make test` to see it fail, implement the
behavior, then run `make test` again. Catch2 is fetched automatically by CMake
during the first build.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for dev-container setup, the TDD
workflow, and how to work with ADRs. Use the
[issue templates](.github/ISSUE_TEMPLATE/) and
[pull request template](.github/PULL_REQUEST_TEMPLATE.md) when proposing a
change.

Pull requests run the build and tests in the same dev container through
[`.github/workflows/ci.yml`](.github/workflows/ci.yml).
