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
