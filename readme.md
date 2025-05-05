# 🧱 Cub3D

Cub3D is a simple 3D raycasting engine inspired by *Wolfenstein 3D*, developed as part of the 42 curriculum. The goal is to render a pseudo-3D environment from a 2D map using raycasting, allowing the player to explore a maze and interact with enemies, keys, and doors.

---

## 📦 Features

- Raycasting-based 3D rendering
- Player movement and camera rotation
- Basic enemy AI (chases the player)
- Doors that open with keys
- Complex square labyrinth maps
- Mini-map (optional)
- Texture rendering for walls and objects

---

## ⚙️ Requirements

> ⚠️ **Important:** This project currently **only compiles and runs on Linux** due to the use of the MiniLibX graphical library.

### Dependencies (Linux)

You will need the following packages:

- `gcc` or `clang`
- `make`
- `libx11-dev`
- `libxext-dev`
- `libbsd-dev`
- `libxrandr-dev`
- `libpng-dev`
- `libmlx` (included or build manually)

### Ubuntu/Debian installation command:

```bash
sudo apt-get update
sudo apt-get install xorg libx11-dev libxext-dev zlib1g-dev libbsd-dev
```

## 🛠️ Compilation

To compile the project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/cub3d.git
   cd cub3d
   ```

2. Build the project using `make`:
   ```bash
   make
   ```

   This will generate an executable named `cub3D` in the root directory.

---

## ▶️ Running the Project

To run the project, you need to provide a valid map file as an argument. A map file is a `.cub` file that defines the layout of the maze, textures, and other settings.

### Example Command:

```bash
./cub3D map/1.cub
```

You will find 3 maps in the `map` directory, fell free to create your own maps using the provided template.

### Controls:
- **Z**: Move forward
- **S**: Move backward
- **Q**: Rotate left
- **D**: Rotate right
- **Left Arrow**: Turn left
- **Right Arrow**: Turn right
- **A**: Open the mini-map
- **Shift**: Run
- **Space**: Interact with objects (open doors, pick up keys)
- **M**: Use the mouse instead of keyboard for movement
- **ESC**: Exit the game

## Authors
- **Wawaann**
- **CedricM11**