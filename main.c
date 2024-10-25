#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "include/struct.h"

// Global variables definition
int screenWidth = 800;
int screenHeight = 600;
ScreenType currentScreen = SCREEN_MENU;
Screen screens[4];

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    /************************************
    I was trying to debug my code using the printf function but nothing was showing up on the screen
    so i did a quick search and i found the solution on this form
    https://forums.codeblocks.org/index.php?topic=4887.0
    *************************************/
    freopen("CON", "w", stdout); // redirects stdout
    freopen("CON", "w", stderr); // redirects stderr
    /************************************/

    SDL_Surface *screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE);
    if (!screen) {
        fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_WM_SetCaption("Minesweeper-1.0", NULL);
    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }else if (event.type == SDL_VIDEORESIZE) {
                // Handle window resizing
                screenWidth = event.resize.w;
                screenHeight = event.resize.h;
                screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE);
                if (!screen) {
                    fprintf(stderr, "Unable to resize window: %s\n", SDL_GetError());
                }
            }
        }

        // Clear screen with a color (e.g., black)
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        SDL_Flip(screen);  // Update the screen
    }

    SDL_Quit();
    return 0;
}

