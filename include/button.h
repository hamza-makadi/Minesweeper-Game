#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "struct.h"

// Function to create a button
Button createButton(const char *imageFile, const char *text, float xPercent, float yPercent, int width, int height);

// Function to render a button
void renderButton(SDL_Surface *screen, Button *button, TTF_Font *font);

// Function to handle button clicks
void handleButtonClick(Screen* screen, int mouseX, int mouseY);

// Function to free button resources
void freeButtons(Button *buttons, int buttonCount);

#endif
