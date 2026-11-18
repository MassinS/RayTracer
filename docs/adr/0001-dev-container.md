# 0001: Use a Dev Container

## Context

Developers need a consistent and reproducible environment across different
machines to avoid differences in compilers, dependencies, and system
configuration and to simplify onboarding. Alternatives include installing and
maintaining the toolchain separately on each host. The repository defines an
Ubuntu 24.04 Dev Container.

## Decision

Provide the Dev Container as the shared development environment. Support VS
Code's Dev Containers workflow and document the Dev Container CLI for Zed.

## Status

Proposed

## Consequences

Contributors need Docker to use the container. The shared environment is
Ubuntu-based; VS Code provides the one-click workflow, while Zed users use the
Dev Container CLI or build natively.
