# Picture to ASCII

This project converts images into ASCII art using a C program. It processes an input image and generates a text-based representation using characters of varying brightness to emulate the image's details.

---

## Features
- Converts images into dynamic ASCII art.
- Supports grayscale conversion using brightness mapping.
- Animated output with smooth transitions.
- Compatible with `.jpg`, `.png`, and other image formats supported by `stb_image.h`.

---

## Requirements

- **Operating System**: Windows
- **Compiler**: GCC (MinGW recommended)
- **Libraries**:
  - `stb_image.h` (Included in the project folder)

---

## Usage

1. **Prepare the Image**:
   Place the image file in the same directory as the program or note its path.

2. **Run the Program**:
   Execute the compiled program and provide the path to the image when prompted.
   ```
   Enter image path: example.jpg
   ```

3. **View ASCII Output**:
   The ASCII representation of the image will be displayed in the console.

---


## How It Works

1. The program uses the `stb_image.h` library to load image data.
2. The image is resized to fit a 120x60 grid for the console.
3. Each pixel's brightness is calculated and mapped to an ASCII character based on its intensity.
4. Color effects are applied using `SetConsoleTextAttribute` from the Windows API.
5. The output is animated by updating the console periodically.

---
