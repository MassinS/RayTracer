# 0004: Add Makefile Shortcuts

## Context

The CMake preset commands for configuring, building, running, and testing are
verbose to type repeatedly. Alternatives are to keep entering the full
commands or add editor-specific aliases. The project already uses CMake and
CTest for its build and tests.

## Decision

Add Makefile targets `build`, `run`, `test`, and `clean` as short commands.
They wrap the existing CMake preset workflow; `run` and `test` build first.

## Status

Proposed

## Consequences

The shortcuts require GNU Make in addition to the existing CMake toolchain.
The Makefile is another place to maintain the workflow, and its commands use
the `unix-debug` preset.
