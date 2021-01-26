#include "../inc/header.h"

SDL_Rect* print_drako()
{
    SDL_Rect *rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
        rect->h  = 70;
        rect->w =  200;
        rect->x = 100;
        rect->y = SCREEN_HEIGHT/2 - 40;
    return rect;
}
