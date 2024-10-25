#include "../include/button.h"

// Function to initialize SDL and set up the window
void initialize_sdl(SDL_Surface **window) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        GameState = 0;
    }

    /************************************

    I was trying to debug my code using the printf function but nothing was showing up in the console
    so i did a quick search and i found the solution on this form
    https://forums.codeblocks.org/index.php?topic=4887.0

    *************************************/

    freopen("CON", "w", stdout); // redirects stdout
    freopen("CON", "w", stderr); // redirects stderr

    /************************************/

    *window = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE);
    if (!(*window)) {
        fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        GameState = 0;
    }

    SDL_WM_SetCaption("Minesweeper-1.0", NULL);

}

// Function to initialize sdl font using the SDL_ttf library
void init_font(TTF_Font **font, const char *fontPath, int font_size){
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        GameState = 0;
    }

    *font = TTF_OpenFont(fontPath, font_size);
    if (!(*font)) {
        printf("Failed to load font: %s\n", TTF_GetError());
        GameState = 0;
    }
}

// Function to handle user input and events
void handle_events(SDL_Surface **window, Screen *menuScreen){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            GameState = 0;
        }else if (event.type == SDL_VIDEORESIZE) {
            // Handle window resizing
            screenWidth = event.resize.w;
            screenHeight = event.resize.h;
            *window = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE);
            if (!(*window)) {
                fprintf(stderr, "Unable to resize window: %s\n", SDL_GetError());
            }
        }else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            handleButtonClick(&(*menuScreen), mouseX, mouseY);
        }
    }
}

