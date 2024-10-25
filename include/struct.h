#ifndef STRUCT_H
#define STRUCT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

// Global variables
extern int screenWidth;
extern int screenHeight;
extern int GameState;

// Button structure
typedef struct {
    SDL_Surface *image;
    SDL_Rect position;
    int width;
    int height;
    const char *text;
    void (*onClick)();
} Button;

// Structure for different screens
typedef enum {
    SCREEN_MENU,
    SCREEN_GAME_SETTINGS,
    SCREEN_GAME,
    SCREEN_SETTINGS
} ScreenType;

extern ScreenType currentScreen;

// Structure for screen parameters
typedef struct Screen {
    Button* buttons;
    int buttonCount;
} Screen;

extern Screen screens[4];

#endif
