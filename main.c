#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "include/struct.h"
#include "include/button.h"
#include "include/screens.h"
#include "include/sdl_handler.h"


// Global variables definition
int screenWidth = 800;
int screenHeight = 600;

ScreenType currentScreen = SCREEN_MENU;
Screen screens[4];

int GameState = 1;// 1 is running 0 is off

int main(int argc, char* argv[]) {

    // Initialize SDL window
    SDL_Surface *window = NULL;
    initialize_sdl(&window);

    // Initialize font to display text
    TTF_Font *font;
    init_font(&font, "assets/fonts/M 8pt.ttf", 24);

    // Initialize All the screens
    Screen menuScreen;
    initMenuScreen(&menuScreen);

    while (GameState) {
        // handle user events ( keyboard and mouse events )
         handle_events(&window, &menuScreen);

        // Clear window
        SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));

        // Display the current screen
        switch(currentScreen) {
            case SCREEN_MENU:
                renderMenuScreen(&menuScreen, window, font);
                break;
            case SCREEN_GAME:
                break;
            case SCREEN_GAME_SETTINGS:
                break;
            case SCREEN_SETTINGS:
                break;
        }

        // Update the window
        SDL_Flip(window);
    }
    // Clean all used resources to prevent memory licks
    freeButtons(menuScreen.buttons, menuScreen.buttonCount);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

