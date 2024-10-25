#ifndef SDLHANDLER_H
#define SDLHANDLER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "struct.h"

// Function to initialize SDL and set up the window
void initialize_sdl(SDL_Surface **window);

// Function to initialize SDL font using the SDL_ttf library
void init_font(TTF_Font **font, const char *fontPath, int font_size);

// Function to handle user input and events
void handle_events(SDL_Surface **window, Screen *menuScreen) ;

#endif

