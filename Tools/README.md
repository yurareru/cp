# gpp

Compile, run and test competitive programming solutions with `g++`.

`~/.local/bin/gpp` is a symlink to this file. To install:

```bash
ln -sf "$PWD/Tools/gpp" ~/.local/bin/gpp
```

Compiles with `g++ -std=c++20 -O2 -Wall -Wextra -Wshadow -Wduplicated-cond -Wlogical-op`.

## Usage

```
gpp file.cpp [options] [input]
gpp -c [dir]
```

| Command | What it does |
| --- | --- |
| `gpp 67A.cpp` | Build if the source changed, then test against the samples (or just run if there are none) |
| `gpp 67A.cpp -t` | Test against all samples |
| `gpp 67A.cpp -T 5` | Time limit per test in seconds (default 2) |
| `gpp 67A.cpp -r` | Run interactively |
| `gpp 67A.cpp -r input.txt` | Run with input from a file |
| `gpp 67A.cpp -r "3 4"` | Run with a literal string as input |
| `gpp 67A.cpp -b` | Force a rebuild |
| `gpp 67A.cpp -a` | Add a sample: paste input, Ctrl-D, paste expected output, Ctrl-D |
| `gpp 67A.cpp -a 3` | Add 3 samples in a row |
| `gpp 67A.cpp -l` | List samples |
| `gpp -c [dir]` | Delete `exe`, `.got`, `.err` and old `.build/` folders under `dir` (default `.`), keeping samples |

Options can be combined, e.g. `gpp 67A.cpp -bt` rebuilds then tests.

## Samples

Each problem gets a folder next to its source:

```
67A.cpp
.gpp/67A/
    exe          compiled binary            (gitignored)
    1.in  1.ans  sample 1 (1.out also works as expected output)
    2.in  2.ans  sample 2 ...
    1.got        your output from the last test run (gitignored)
    1.err        stderr, kept only if non-empty    (gitignored)
```

Add samples with `-a`, or create the `N.in` / `N.ans` files yourself. Ctrl-C or an empty input cancels the sample being typed without saving anything; samples already finished in the same `-a n` run are kept.

## Test output

```
Test 1: AC (0.01s)
Test 2: WA (0.01s)
--- input ---
1
abc
--- expected ---
xyz
--- got ---
abc

1/2 passed
```

Verdicts are `AC`, `WA`, `TLE`, `RE (exit N)`, and `??` when a sample has no expected output (your output is shown). Failed tests print the input, the expected output, your output and stderr. Comparison ignores trailing whitespace on each line and trailing blank lines. The exit code is non-zero if any test fails.
