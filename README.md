_This project has been created as part of the 42 curriculum by kinamura, stakada._

# miniRT

## Description

**miniRT** is a ray tracing engine written in C that renders 3D scenes using the MiniLibX graphics library. It implements ray tracing algorithms to generate computer-generated images with geometric objects, lighting, and shadows.

### Features

- Ray tracing with spheres, planes, and cylinders
- Ambient and diffuse lighting with hard shadows
- Configurable camera with field of view control
- Scene description parser for `.rt` files
- RGB color system and smooth window management

---

## Instructions

### Prerequisites

- **Operating System**: macOS or Linux
- **Compiler**: `gcc` or `clang` with C99 standard support
- **Make**: GNU Make
- **Libraries**: MiniLibX (included in repository)
- **X11** (Linux only): Required for MiniLibX on Linux systems

### Compilation

```bash
# Compile the project
cd miniRT
make

# The executable will be created at bin/miniRT
```

Available Make targets:

- `make` or `make all`: Compile the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Recompile the entire project

### Execution

Run the program with a scene file:

```bash
./bin/miniRT scenes/valid/<filename>.rt
```

### Scene File Format

Scene files (`.rt` extension) define the 3D environment. Each element is defined on a separate line with specific parameters:

**Ambient Lighting** (required, one only):

```
A <ratio> <R,G,B>
```

- `ratio`: Ambient lighting ratio [0.0, 1.0]
- `R,G,B`: Color values [0-255]

**Camera** (required, one only):

```
C <x,y,z> <nx,ny,nz> <fov>
```

- `x,y,z`: Camera position coordinates
- `nx,ny,nz`: Normalized orientation vector [-1.0, 1.0]
- `fov`: Field of view [0, 180]

**Light** (required, one only):

```
L <x,y,z> <brightness> <R,G,B>
```

- `x,y,z`: Light position coordinates
- `brightness`: Light brightness ratio [0.0, 1.0]
- `R,G,B`: Color values [0-255] (bonus feature)

**Sphere**:

```
sp <x,y,z> <diameter> <R,G,B>
```

**Plane**:

```
pl <x,y,z> <nx,ny,nz> <R,G,B>
```

**Cylinder**:

```
cy <x,y,z> <nx,ny,nz> <diameter> <height> <R,G,B>
```

### Controls

- **ESC**: Close window and exit program
- **Close button (×)**: Close window and exit program

---

## Resources

### Ray Tracing Theory

- **[Ray Tracing in One Weekend](https://raytracing.github.io/)** by Peter Shirley - Comprehensive introduction to ray tracing concepts

### Implementation References

- **[42 Docs](https://harm-smits.github.io/42docs/)** - Community-maintained documentation for MiniLibX
- **[MiniLibX](https://github.com/42Paris/minilibx-linux)** - MiniLibX resources

### AI Usage

- **Understanding Complex Concepts**: Clarifying ray tracing mathematics, vector operations, and lighting algorithms through explanations and examples
- **Debugging Assistance**: Identifying potential edge cases, suggesting debugging approaches for intersection calculations
- **Documentation**: Drafting initial code comments and README structure
- **Code Review**: Getting suggestions for potential improvements and optimizations

**Important Note**: All AI-generated content was reviewed, tested, and discussed with peers.

---

## Project Structure

```
miniRT/
├── bin/                    # Compiled executable
├── includes/               # Header files
│   ├── miniRT.h           # Main header
│   ├── config.h           # Configuration constants
│   ├── ctx.h              # Context structures
│   ├── errors.h           # Error handling
│   ├── parsing.h          # Parser functions
│   └── render.h           # Rendering functions
├── libft/                  # Custom C library
├── objs/                   # Object files
├── scenes/                 # Scene description files
│   ├── valid/             # Valid test scenes
│   └── error/             # Invalid scenes for testing
├── srcs/                   # Source files
│   ├── parsing/           # Scene file parsing
│   ├── render/            # Ray tracing engine
│   ├── transform/         # Coordinate transformations
│   └── utils/             # Helper functions
├── Makefile               # Build configuration
└── README.md              # This file
```

---

## License

This is a student project created as part of the 42 school curriculum. Feel free to reference it for learning purposes, but please do not copy it directly for your own 42 projects.

---

## Acknowledgments

- 42 Tokyo for providing the curriculum and learning environment
- The MiniLibX library developers
- The ray tracing community for extensive documentation and resources
