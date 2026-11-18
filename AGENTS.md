# Project instructions

## Build, run, and test

From the project root (configure once, then rebuild as needed):

```sh
cmake --preset unix-debug
cmake --build --preset unix-debug
```

Run the program:

```sh
./build/unix-debug/raytracer
```

On Windows, run `.\build\unix-debug\raytracer.exe`.

Run tests:

```sh
ctest --preset unix-debug
```

## Architecture decisions

Architecture decisions are in `docs/adr/`. Read them before changing the
build, tools, or test setup. Never go against an accepted ADR. To change a
decision, write a new ADR with status `Proposed` and ask me. Never set an ADR
to `Accepted`.
