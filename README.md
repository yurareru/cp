# How to Use the `gpp` Script for g++ Compilation

This PowerShell script simplifies building and running C++ programs using `g++`.

---

## Usage

### Build Only

Compile the source file into an executable.

```powershell
gpp file.cpp b
```

### Run Only

Run the existing executable. If the executable doesn't exist, it will first build it.

```powershell
gpp file.cpp r
```
### Run with Input from a file

Runs the existing executables and feeds it input from a specified file.

If the executable does not exist, it will first build it.

```powershell
gpp file.cpp ri input.txt
```

### Build & Run

Compile the source file and then run the resulting executable.

```powrshell
gpp file.cpp br
```

### Build, Run, and Provide input from a file

Compile, run, and redirect input from a specified file.

```cpp
gpp file.cpp bri input.txt
```
