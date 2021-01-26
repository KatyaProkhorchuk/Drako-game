#include "../inc/header.h"

void logic (SDL_Window* window)
{
    SDL_Rect *drak = print_drako();  //int i = 0, j = 0;
    SDL_Rect TMP;
    SDL_Rect rect[4];
    for(int i = 0; i < 4; i++){
        rect[i].h  = 50;
        rect[i].w =  100;
        rect[i].x = rand() % SCREEN_WIDTH + SCREEN_WIDTH;
        rect[i].y = rand() % SCREEN_HEIGHT;
    }
    SDL_Rect Energy;
    Energy.h = 25;
    Energy.w = 25;
    Energy.x = rand() % SCREEN_WIDTH + 1920;
    Energy.y = rand() % SCREEN_HEIGHT;
    SDL_Rect Fire;
    bool FireT;

    SDL_Rect Coin;
    Coin.h =50;
    Coin.w = 100;
    Coin.x = SCREEN_WIDTH;
    Coin.y = rand() % SCREEN_HEIGHT;

    SDL_Rect Wall;
    Wall.h =  SCREEN_HEIGHT;
    Wall.w  = SCREEN_WIDTH;
    Wall.x = SCREEN_WIDTH + 150;
    Wall.y = 0;

    Fire.h = 40;
    Fire.w = 40;
    Fire.x = SCREEN_WIDTH;
    Fire.y = 0;
    FireT = false;
    bool running = true;
    SDL_Surface* screen_surface = NULL;

    //SDL_Surface *message = NULL;

    //SDL_RWops *drag = SDL_RWFromFile("/resource/texture/drag.gif", "rb");
    screen_surface = SDL_GetWindowSurface(window);
    SDL_Surface *image = IMG_Load("/resource/texture/sky.png");
    SDL_Surface *Energ = IMG_Load("/resource/texture/Energy.png");
    SDL_Surface *Castle = IMG_Load("/resource/texture/castle.png");
    SDL_Surface *Chest = IMG_Load("/resource/texture/Coin.png");
    SDL_Surface *Fireball[6];
    Mix_Music *GameM = Mix_LoadMUS("/resource/music/game.ogg");
    Mix_Chunk *CloudHit = Mix_LoadWAV("/resource/music/Wall&CloudsHit.ogg");
    Mix_Chunk *Death = Mix_LoadWAV("/resource/music/Death2.ogg");
    Mix_Chunk *Win  = Mix_LoadWAV("/resource/music/Won.ogg");
    Mix_PlayMusic(GameM, -1);
    Fireball[0] = IMG_Load("/resource/texture/fireball/0.png");
    Fireball[1] = IMG_Load("/resource/texture/fireball/1.png");
    Fireball[2] = IMG_Load("/resource/texture/fireball/2.png");
    Fireball[3] = IMG_Load("/resource/texture/fireball/3.png");
    Fireball[4] = IMG_Load("/resource/texture/fireball/4.png");
    Fireball[5] = IMG_Load("/resource/texture/fireball/5.png");
    SDL_Surface *dragon[10];
    dragon[0] = IMG_Load("/resource/texture/dragon/0.gif");
    dragon[1] = IMG_Load("/resource/texture/dragon/1.gif");
    dragon[2] = IMG_Load("/resource/texture/dragon/2.gif");
    dragon[3] = IMG_Load("/resource/texture/dragon/3.gif");
    dragon[4] = IMG_Load("/resource/texture/dragon/4.gif");
    dragon[5] = IMG_Load("/resource/texture/dragon/5.gif");
    dragon[6] = IMG_Load("/resource/texture/dragon/6.gif");
    dragon[7] = IMG_Load("/resource/texture/dragon/7.gif");
    dragon[8] = IMG_Load("/resource/texture/dragon/8.gif");
    dragon[9] = IMG_Load("/resource/texture/dragon/9.gif");
    SDL_Surface *clouds = IMG_Load("/resource/texture/cloud1.png");
    //SDL_FillRect(screen_surface, NULL, SDL_MapRGB( screen_surface->format, 123, 255, 100));
	SDL_BlitSurface( image, NULL, screen_surface, NULL );
    SDL_UpdateWindowSurface(window);
    SDL_Event event;
    int n = 0, Power = 20, time = rand()% 4000 + 4000,  k = 0,  t = 0, f = 0;
    char str[2];
    bool Is = false, pause = false;
    n = 4;
    while(running)
    {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            else if(drak->y + drak->h + 50 < SCREEN_HEIGHT && event.key.keysym.sym == SDLK_DOWN){
                drak->y += 15;
            }
            else if(drak->y + drak->h > 100 && event.key.keysym.sym == SDLK_UP){
                drak->y -= 15;
            }
            else if(event.key.keysym.sym == SDLK_SPACE && Power - 20 >= 0)
            {
                Fire.x = drak->x + drak->w;
                Fire.y = drak->y + drak->h / 2;
                FireT = true;
                Power -= 20; 
            }
            else if (event.key.keysym.sym == SDLK_ESCAPE && event.type == SDL_KEYDOWN)
            {
                if(pause == false)
                {
                    pause = true;
                }
                else 
                {
                    pause = false;
                }
            }
        }
        if(pause == false){
        if(rand()%101 < 5 && Is == false){
            Is = true;
        }
         if(SDL_HasIntersection(&Energy, drak))
        {
            if(Power < 20)
            Power += 4;
            Is = false;
            Energy.x = rand() % SCREEN_WIDTH + 1920;
        }
        //SDL_FillRect(screen_surface, NULL, SDL_MapRGB( screen_surface->format, 123, 255, 100));
        SDL_BlitSurface( image, NULL, screen_surface, NULL );
        //SDL_BlitSurface(image, NULL, screen_surface, NULL);
        for(int i = 0; i < n; i++){
            //SDL_FillRect(screen_surface, &(rect[i]), SDL_MapRGB( screen_surface->format, 255, 255, 255));
            SDL_BlitSurface(clouds,NULL, screen_surface, &rect[i]);
        }
        if(FireT == true)
        //SDL_FillRect(screen_surface, &Fire, SDL_MapRGB(screen_surface->format, 255, 0, 0));
        SDL_BlitSurface( Fireball[f], NULL, screen_surface, &Fire);
        if(f < 5)
        {
            f++;
        }
        else if(f == 5)
        {
            f = 0;
        }
        if(Is == true){
        //SDL_FillRect(screen_surface, &Energy, SDL_MapRGB( screen_surface->format, 230, 41, 255));
        SDL_BlitSurface( Energ, NULL, screen_surface, &Energy);
        }
        if(time <= 0){
        //SDL_FillRect(screen_surface, &(Coin), SDL_MapRGB( screen_surface->format, 255, 255, 0));
        SDL_BlitSurface(Chest, NULL, screen_surface, &Coin);
       // SDL_FillRect(screen_surface, &(Wall), SDL_MapRGB( screen_surface->format, 199, 199, 199));
        SDL_BlitSurface(Castle, NULL, screen_surface, &Wall);
        }
        //SDL_FillRect(screen_surface, drak, SDL_MapRGB( screen_surface->format, 255, 127, 0));
        TMP.x = drak->x;
        TMP.y = drak->y;
        TMP.h = drak->h;
        TMP.w = drak->w;
        SDL_BlitSurface(dragon[k], NULL, screen_surface, &TMP);
        drawText(screen_surface, "Power: ", 28, 20, 10, 83, 61, 0, "/resource/fonts/1.ttf");
        drawText(screen_surface, SDL_itoa (Power, str, 10), 28, 20 + 28 * 4, 10, 83, 61, 0, "/resource/fonts/1.ttf");
        drawText(screen_surface, " / 20", 28, 20 + 28 * 5, 10, 83, 61, 0, "/resource/fonts/1.ttf");
        SDL_UpdateWindowSurface(window);
        if(k < 9 && t == 3)
        {
            k++;
            t = 0;
        }
        else if(k == 9 && t == 3)
        {
            k = 0;
            t = 0;
        }
        t++;
        //SDL_Delay(10);
            if ( FireT == true)
            {
                Fire.x += 10;
            }

        if (Energy.x > 0)
        {
            Energy.x -= 8; 
        }
        else
        {
            Energy.y = rand() % SCREEN_HEIGHT;
            Energy.x = rand() % SCREEN_WIDTH + SCREEN_WIDTH;
        }
        if (time <= 0)
        {
            Coin.x -= 10;
            Wall.x -= 10;
        }
        for(int i = 0; i < n; i++){
            if (rect[i].x > 0)
            {
                rect[i].x -= 8; 
            }
            else
            {
                rect[i].y = rand() % SCREEN_HEIGHT - 50;
                rect[i].x = rand() % SCREEN_WIDTH + SCREEN_WIDTH;
            }
            
            if(SDL_HasIntersection(&rect[i], drak))
            {
                Mix_PlayChannel(-1, Death, 0);
                drawText(screen_surface, "YOU LOSE!", 52, SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 50, 255, 0, 0, "/resource/fonts/2.ttf");
                SDL_UpdateWindowSurface(window);
                SDL_Delay(1000);
                running = false;
            }
        }
        for(int i = 0; i < n; i++){
        if(SDL_HasIntersection(&rect[i], &Fire))
            {
                Mix_PlayChannel(-1, CloudHit, 0);
                rect[i].y = rand() % SCREEN_HEIGHT - 50;
                    rect[i].h = rand() % 100 + 50;
                    rect[i].w = rand() % 200 + 50;
                rect[i].x = rand() % SCREEN_WIDTH + SCREEN_WIDTH;
                Fire.x = 1980;
                Fire.y = 0;
                FireT = false;
            }
            else if (Fire.x + Fire.w > 1920 && FireT == true)
            {
                FireT = false;
                Fire.x = 1980;
                Fire.y = 0;
            }
        }
        if(SDL_HasIntersection(drak, &Coin))
        {
            Mix_PlayChannel(-1, Win, 0);
            drawText(screen_surface, "YOU WIN!", 52, SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 50, 0, 255, 0, "/resource/fonts/2.ttf");
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
            running  = false;
        }
        if(SDL_HasIntersection(drak, &Wall))
        {
            Mix_PlayChannel(-1, Death, 0);
            drawText(screen_surface, "YOU LOSE!", 52, SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 50, 255, 0, 0, "/resource/fonts/2.ttf");
            SDL_UpdateWindowSurface(window);
            SDL_Delay(1000);
            running  = false;
        }
        time--;
    }
    else if (pause == true)
    {
        drawText(screen_surface, "PAUSE!", 52, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50, 83, 61, 0, "/resource/fonts/2.ttf");
        SDL_UpdateWindowSurface(window);
    }
    
    }
    Mix_PauseMusic();
    SDL_FreeSurface(image);
    SDL_FreeSurface(Energ);
    SDL_FreeSurface(Castle);
    for(int i = 0; i < 6; i++)
    {
        SDL_FreeSurface(Fireball[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        SDL_FreeSurface(dragon[i]);
    }
    SDL_FreeSurface(clouds);
    Mix_FreeChunk(CloudHit);
    Mix_FreeChunk(Death);
    Mix_FreeChunk(Win);
    Mix_FreeMusic(GameM);

} 

