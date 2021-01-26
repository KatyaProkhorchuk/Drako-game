#include "../inc/header.h"

int main() {
    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC);
    TTF_Init();
    srand(time(NULL));
    Menu();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
