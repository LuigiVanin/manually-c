
# Manually C 🛠️

This project is a hands-on guide to building a C codebase using **only the Clang compiler**. No Makefiles, no CMake (except for Raylib initially), no build systems – just raw Clang commands. It's designed to deepen your understanding of the C compilation and linking process.

We'll build a simple application that utilizes:
* A custom dynamic library (`liblib.so`) for a generic list.
* The Raylib library as an external static library.

The commands to build and run the project are detailed in [run.sh](./run.sh) and [build.sh](./lib/build.sh).


##  Prerequisites

Before you begin, ensure you have the following installed:
* **Clang** (C compiler)
* **CMake** (only for the initial Raylib build)
* **Git** (for cloning the repository)

---

## 1. Cloning the Repository (with Submodules)

This project uses Raylib as a submodule.

**To clone the repository and initialize submodules:**
```bash
git clone --recurse-submodules <your-repo-url>
cd manually-c
```

If you've already cloned the repository without `--recurse-submodules`, initialize them with:
```bash
git submodule update --init --recursive
```

<br />

## 2. Building Raylib (Static Library) 🧱

Raylib is included as a submodule in `extern/raylib/`. We'll build it as a static library.

**Steps:**
1.  Navigate to the Raylib build directory:
    ```bash
    cd extern/raylib/build
    ```
2.  Configure CMake to build a static library:
    ```bash
    cmake -DBUILD_SHARED_LIBS=OFF ..
    ```
3.  Compile Raylib:
    ```bash
    make
    ```

This process generates:
* Static library: `extern/raylib/build/raylib/libraylib.a`
* Header files: Located in `extern/raylib/build/raylib/include/`

Clang will link against `libraylib.a` and use the headers from the `include` directory in the final compilation step.

<br />

## 3. Compiling Your Dynamic Library (`liblib.so`) 📚

The project includes a custom dynamic library defined in `lib/lib.h` and implemented in `lib/lib.c`.

**To build the dynamic library:**
```bash
./lib/build.sh
```

This script executes the following Clang command:
```bash
# Command executed by ./lib/build.sh
clang -fPIC -shared -o lib/liblib.so lib/lib.c
```
This creates `liblib.so` in the `lib/` directory. The main build script (`run.sh`) will later move this to `build/_deps/`.

<br />

## 4. Building the Main Executable 🚀

The `run.sh` script automates the entire build process. It will:
1.  Build the dynamic library (`liblib.so`) if it doesn't exist.
2.  Compile and link `main.c` and `util.c` into the `manually-c` executable.
3.  Link against:
    * Your dynamic library (`liblib.so`).
    * The static Raylib library (`libraylib.a`).

**To build everything:**
```bash
./run.sh
```

The core Clang command used by `run.sh` to build the executable is:
```bash
clang -g -Wall -Wextra -std=c23 -o ./build/manually-c \
    main.c util.c \
    -I./extern/raylib/build/raylib/include \
    -L./extern/raylib/build/raylib \
    -lraylib -lm -lpthread -ldl -lX11 \
    -L./build/_deps \
    -llib
```
* `-I`: Specifies include directories (for Raylib headers).
* `-L`: Specifies library search directories (for Raylib and your `liblib.so`).
* `-l`: Links specific libraries (Raylib and your `lib`).

<br />

## 5. Running the Final Executable ▶️

After a successful build, run the executable. You'll need to tell the dynamic linker where to find `liblib.so`:

```bash
LD_LIBRARY_PATH=./build/_deps ./build/manually-c
```

> [!NOTE]
> `LD_LIBRARY_PATH` is an environment variable that directs the dynamic linker to search `build/_deps/` for shared libraries (like `liblib.so`) before checking standard system paths.

<br />

## 6. Project File Structure 📂

```
.
├── extern/
│   └── raylib/           # Raylib submodule
├── lib/
│   ├── lib.c             # Source for your dynamic library
│   ├── lib.h             # Header for your dynamic library
│   └── build.sh          # Script to build liblib.so
├── build/                # Output directory for the final executable and libraries
│   ├── _deps/            # Contains liblib.so after build
│   └── manually-c        # The final executable
├── main.c                # Main application source code
├── util.c                # Utility functions for the main application
├── util.h                # Header for utility functions
├── run.sh                # Main script to build and run the project
└── README.md             # This file
```

<br />

## 7. Important Notes 📝

* The build scripts (`run.sh`, `lib/build.sh`) are designed for a **Linux-like environment**.
* While the goal is manual Clang usage, **CMake and Make are temporarily used for the initial Raylib build** due to its own build system.
* For any issues specifically related to Raylib, please consult the [official Raylib documentation](https://github.com/raysan5/raylib).
* Pre-compiled output files (`.so` and the main binary) are included in the `build/` directory for reference. You can inspect them or delete them and rebuild from scratch.