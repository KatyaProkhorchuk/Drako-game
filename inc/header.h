#pragma once

#include "../resource/include/SDL2/SDL.h"
#include "../resource/include/SDL2/SDL_image.h"
#include "../resource/include/SDL2/SDL_ttf.h"
#include "../resource/include/SDL2/SDL_mixer.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

SDL_Rect* print_drako();
void logic (SDL_Window* window);
void drawText
(SDL_Surface* screen, char* string, int size, int x, int y, int fR, int fG, int fB, char* str);
bool Check(int x);
void Menu();
