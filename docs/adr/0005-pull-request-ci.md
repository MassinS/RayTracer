# 0005: Run Pull Request CI in the Dev Container

## Context

Every pull request should build the project and run its tests in the same
Ubuntu 24.04 dev container used for development. Alternatives include running
CI on a host-installed toolchain or using another CI provider. The repository
is hosted on GitHub and has `make build` and `make test` targets.

## Decision

Propose GitHub Actions for pull-request CI, using the Dev Containers CI action
to run `make build` and `make test` in the repository's dev container.

## Status

Proposed

## Consequences

This adds GitHub Actions and the Dev Containers CI action as dependencies for
CI. The workflow and action version will need maintenance, and the CI job
depends on the container building successfully.
