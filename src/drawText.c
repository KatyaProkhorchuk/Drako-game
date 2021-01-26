#include "../inc/header.h"

void drawText
(SDL_Surface* screen, char* string,
int size, int x, int y,
int fR, int fG, int fB,  char * str)
{

TTF_Font* font = TTF_OpenFont(str, size);

SDL_Color foregroundColor = { fR, fG, fB, 0};
//SDL_Color backgroundColor = { bR, bG, bB, 1};

SDL_Surface* textSurface = TTF_RenderText_Solid (font, string, foregroundColor);

SDL_Rect textLocation;
textLocation.x = x;
textLocation.y = y;

SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

SDL_FreeSurface(textSurface);

TTF_CloseFont(font);
}
