# Contributing

## Set up the development environment

Use the repository's Ubuntu 24.04 dev container for a consistent toolchain.
In VS Code, open the repository and choose **Reopen in Container**. In Zed,
start the container from the repository root with:

```sh
devcontainer up --workspace-folder .
```

Run the project commands inside the container:

```sh
make build
make run
make test
make clean
```

## Test-driven development

For a change, add or update a test in `tests/` first and run `make test` to
observe the failing behavior. Implement the change, then run `make test` again.
Tests use Catch2 and run through CTest.

## Architecture decisions

Read the ADRs in `docs/adr/` before changing the build, tools, or test setup.
For a decision that needs to change, propose a new ADR with status `Proposed`
and ask the maintainers before proceeding. Do not mark an ADR as `Accepted`.

## Issues and pull requests

Use the issue forms in `.github/ISSUE_TEMPLATE/` to report a problem or suggest
a feature. Include a summary and relevant context in pull requests using
`.github/PULL_REQUEST_TEMPLATE.md`.
