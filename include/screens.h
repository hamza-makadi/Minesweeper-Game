#ifndef SCREENS_H
#define SCREENS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "struct.h"

// Function to initialize main menu screen
void initMenuScreen(Screen *menuScreen);

// Function to render main menu screen
void renderMenuScreen(Screen *menuScreen, SDL_Surface *screen, TTF_Font *font);

#endif

