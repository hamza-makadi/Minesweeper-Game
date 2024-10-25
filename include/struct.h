#ifndef STRUCT_H
#define STRUCT_H

#include <SDL.h>
#include <SDL_image.h>

// Global variables
extern int screenWidth;   // Declare as extern
extern int screenHeight;  // Declare as extern

// Button structure
typedef struct {
    SDL_Surface *image;
    SDL_Rect position;
    int width;
    int height;
    void (*onClick)();
} Button;

// Structure for different screens
typedef enum {
    SCREEN_MENU,
    SCREEN_GAME,
    SCREEN_SETTINGS,
    SCREEN_EXIT
} ScreenType;

extern ScreenType currentScreen;  // Declare as extern

// Structure for screen parameters
typedef struct Screen {
    Button* buttons;
    int buttonCount;
} Screen;

extern Screen screens[4];  // Declare as extern

#endif
