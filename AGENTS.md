# Project instructions

## Build, run, test, and clean

Run these commands from the project root:

```sh
make build
make run
make test
make clean
```

## Architecture decisions

Architecture decisions are in `docs/adr/`. Read them before changing the
build, tools, or test setup. Never go against an accepted ADR. To change a
decision, write a new ADR with status `Proposed` and ask me. Never set an ADR
to `Accepted`.

See `CONTRIBUTING.md` for the contributor setup, TDD workflow, and ADR process.
Use `.github/ISSUE_TEMPLATE/` and `.github/PULL_REQUEST_TEMPLATE.md` for
contribution templates. Pull-request CI is defined in
`.github/workflows/ci.yml` and should use the repository's dev container.

New classes go in the folder of their concept under `src/`, and their tests
go in the matching folder under `tests/`.

## How we work

- Use TDD: write a failing test first, then add only enough code to make it pass.
- Derive expected values from the math, not from running the code. If a test
  fails, ask before changing its expected values.
- Work one small step at a time; do only what was asked.
- Keep the C++ simple; avoid advanced features unless requested.
- Run build and test commands in the dev container, not on the host.
