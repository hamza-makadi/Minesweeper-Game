#include "../include/button.h"
#include <stdlib.h>
#include <stdio.h>

// Function to load and resize an image
SDL_Surface* loadAndResizeImage(const char *file, int width, int height) {
    SDL_Surface *temp = IMG_Load(file);
    if (!temp) {
        printf("Failed to load image: %s\n", IMG_GetError());
        return NULL;
    }

    // Create a new surface for the resized image
    SDL_Surface *resizedImage = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height,
                                                      temp->format->BitsPerPixel,
                                                      temp->format->Rmask,
                                                      temp->format->Gmask,
                                                      temp->format->Bmask,
                                                      temp->format->Amask);

    SDL_SoftStretch(temp, NULL, resizedImage, NULL);
    SDL_FreeSurface(temp);

    return resizedImage;
}

// Function to create a button
Button createButton(const char *imageFile, int x, int y, int width, int height) {
    Button button;
    button.image = loadAndResizeImage(imageFile, width, height);
    button.position.x = x;
    button.position.y = y;
    button.width = width;
    button.height = height;
    button.onClick = NULL;
    return button;
}

// Function to render a button
void renderButton(Button *button, SDL_Surface *screen) {
    if (button->image) {
        SDL_BlitSurface(button->image, NULL, screen, &button->position);
    } else {
        printf("Button image not loaded.\n");
    }
}

// Function to handle button clicks
void handleButtonClick(Screen* screen, int mouseX, int mouseY) {
    int i;
    for (i = 0; i < screen->buttonCount; i++) {
        Button *button = &screen->buttons[i];
        if (mouseX > button->position.x && mouseX < button->position.x + button->width &&
            mouseY > button->position.y && mouseY < button->position.y + button->height) {
            if (button->onClick) {
                button->onClick();
            }
        }
    }
}

// Function to free button resources
void freeButtons(Button *buttons, int buttonCount) {
    int i;
    for (i = 0; i < buttonCount; i++) {
        if (buttons[i].image) {
            SDL_FreeSurface(buttons[i].image);
            buttons[i].image = NULL;
        }
    }
}
