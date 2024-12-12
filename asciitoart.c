#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define WIDTH 120
#define HEIGHT 60
const char *ascii_chars = "@$#WMB%8&*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'. ";

void set_color(int brightness) {
    int colors[] = {FOREGROUND_BLUE, FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                    FOREGROUND_GREEN | FOREGROUND_INTENSITY, FOREGROUND_RED | FOREGROUND_INTENSITY};
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[brightness / 51]);
}

void convert_to_ascii(const char *path, int offset) {
    int w, h, c;
    unsigned char *img = stbi_load(path, &w, &h, &c, 1);
    if (!img) return;

    system("cls");
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int px = ((x + offset) * w) / WIDTH, py = (y * h) / HEIGHT;
            unsigned char b = img[py * w + px];
            set_color(b);
            printf("%c", ascii_chars[(int)(pow((double)b / 255, 0.8) * (strlen(ascii_chars) - 1))]);
        }
        printf("\n");
    }
    stbi_image_free(img);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {
    char path[100];
    printf("Enter image path: ");
    scanf("%s", path);

    for (int i = 0; i < 50; ++i) {
        convert_to_ascii(path, i * 2 % WIDTH);
        Sleep(100);
    }
    return 0;
}