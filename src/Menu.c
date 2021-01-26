#include "../inc/header.h"

void Menu()
{
    SDL_Window *Menu = SDL_CreateWindow("Drako", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Surface* screen_surface = NULL;
    screen_surface = SDL_GetWindowSurface(Menu);
    SDL_Event event;
    SDL_Rect Mouse;
    Mouse.h = 1;
    Mouse.w = 1;
    SDL_Rect Start;
    Start.x = SCREEN_WIDTH / 2 - 150;
    Start.y = SCREEN_HEIGHT / 2 - 100;
    Start.h = 75;
    Start.w = 200;
    SDL_Rect Back;
    Back.x = SCREEN_WIDTH - 150;
    Back.y = SCREEN_HEIGHT - 150;
    Back.h = 75;
    Back.w = 200;
    SDL_Rect Tutorial;
    Tutorial.x = SCREEN_WIDTH / 2 - 50;
    Tutorial.y = SCREEN_HEIGHT / 2 + 25;
    Tutorial.h = 75;
    Tutorial.w = 200;
    SDL_Rect Exit;
    Exit.x = SCREEN_WIDTH / 2 + 50;
    Exit.y = SCREEN_HEIGHT / 2 + 150;
    Exit.h = 75;
    Exit.w = 200;
    SDL_Surface *image = IMG_Load("/resource/texture/MenuBack.jpg");
    SDL_Surface *StartB = IMG_Load("/resource/texture/Start.png");
    SDL_Surface *ExitB = IMG_Load("/resource/texture/Exit.png");
    SDL_Surface *HelpB = IMG_Load("/resource/texture/Help.png");
    SDL_Surface *BackB = IMG_Load("/resource/texture/BackB.png");
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    Mix_Music *menuM = Mix_LoadMUS("/resource/music/Menu.ogg");
    Mix_PlayMusic(menuM, -1);
    bool running = true, help = false;
    while(running)
    { 
        //Mix_VolumeMusic(MIX_MAX_VOLUME);
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            else if(event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = 0, y = 0;
                SDL_GetMouseState(&x, &y);
                Mouse.x = x;
                Mouse.y = y;
                if(SDL_HasIntersection(&Start, &Mouse)){
                    Mix_PauseMusic();
                    SDL_Window *window = SDL_CreateWindow("Drako", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
                    logic(window);
                    SDL_DestroyWindow(window);
                    Mix_PlayMusic(menuM, -1);
                }
                else if (SDL_HasIntersection(&Exit, &Mouse))
                {
                    running = false;
                }
                else if (SDL_HasIntersection(&Tutorial, &Mouse))
                {
                    help = true;
                }
            }
        }
        if(help == false){
            SDL_BlitSurface(image, NULL, screen_surface, NULL );
            drawText(screen_surface, "THE DRAKO", 100, 200, 100, 255, 227, 142, "/resource/fonts/3.ttf");
            SDL_BlitSurface(HelpB, NULL, screen_surface, &Tutorial);
            SDL_BlitSurface(ExitB, NULL, screen_surface, &Exit);
            SDL_BlitSurface(StartB, NULL, screen_surface, &Start);
            SDL_UpdateWindowSurface(Menu);
        }
        else 
        {
            SDL_BlitSurface(image, NULL, screen_surface, NULL );
            drawText(screen_surface, "DRAKO's RULES", 100, 200, 100, 255, 227, 142, "/resource/fonts/3.ttf");
            drawText(screen_surface, "1. Dodge clouds - press UP and DOWN", 30, 302, 302, 0, 0, 0, "/resource/fonts/1.ttf");
            drawText(screen_surface, "1. Dodge clouds - press UP and DOWN", 30, 300, 300, 255, 255, 255, "/resource/fonts/1.ttf");
            drawText(screen_surface, "2. Collect energy of fire", 30, 352, 352, 0, 0, 0, "/resource/fonts/1.ttf");
            drawText(screen_surface, "2. Collect energy of fire", 30, 350, 350, 255, 255, 255, "/resource/fonts/1.ttf");
            drawText(screen_surface, "3. You can destroy clouds with your fireballs - press SPACE", 30, 402, 402, 0, 0, 0, "/resource/fonts/1.ttf");
            drawText(screen_surface, "3. You can destroy clouds with your fireballs - press SPACE", 30, 400, 400, 255, 255, 255, "/resource/fonts/1.ttf");
            drawText(screen_surface, "4. Collect the chest at the end of your way", 30, 452, 452, 0, 0, 0, "/resource/fonts/1.ttf");
            drawText(screen_surface, "4. Collect the chest at the end of your way", 30, 450, 450, 255, 255, 255, "/resource/fonts/1.ttf");
            drawText(screen_surface, "5. You can pause game - press ESC", 30, 502, 502, 0, 0, 0, "/resource/fonts/1.ttf");
            drawText(screen_surface, "5. You can pause game - press ESC", 30, 500, 500, 255, 255, 255, "/resource/fonts/1.ttf");
            //SDL_FillRect(screen_surface, &Back, SDL_MapRGB(screen_surface->format, 255, 127, 0));
            SDL_BlitSurface(BackB, NULL, screen_surface, &Back);
            SDL_UpdateWindowSurface(Menu);
            while(SDL_PollEvent(&event))
            {
                if(event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN){
                    int x = 0, y = 0;
                    SDL_GetMouseState(&x, &y);
                    Mouse.x = x;
                    Mouse.y = y;
                    if(SDL_HasIntersection(&Back, &Mouse)){
                        help = false;
                    }
                }
            }
        }
    }
    SDL_FreeSurface(BackB);
    SDL_FreeSurface(StartB);
    SDL_FreeSurface(ExitB);
    SDL_FreeSurface(HelpB);
    SDL_FreeSurface(image);
    Mix_FreeMusic(menuM);
    SDL_DestroyWindow(Menu);
}
