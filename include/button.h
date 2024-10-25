#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_image.h>
#include "struct.h"

// Function to create a button
Button createButton(const char *imageFile, int x, int y, int width, int height);

// Function to render a button
void renderButton(Button *button, SDL_Surface *screen);

// Function to handle button clicks
void handleButtonClick(Screen* screen, int mouseX, int mouseY);

// Function to free button resources
void freeButtons(Button *buttons, int buttonCount); // Added buttonCount to know how many buttons to free

#endif // BUTTON_H
