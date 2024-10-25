#include "../include/button.h"

void startGame() {
    currentScreen = SCREEN_GAME;
}

void openSettings() {
    currentScreen = SCREEN_SETTINGS;
}

void exitGame() {
    GameState = 0;
}

// Function to initialize the main menu screen
void initMenuScreen(Screen *menuScreen) {
    menuScreen->buttonCount = 3;
    menuScreen->buttons = malloc(menuScreen->buttonCount * sizeof(Button));

    // Create buttons
    menuScreen->buttons[0] = createButton("assets/buttons/default-button.png", "Play", .5, .3, 300, 75); // Play button
    menuScreen->buttons[1] = createButton("assets/buttons/default-button.png", "Option", .5, .5, 300, 75); // Settings button
    menuScreen->buttons[2] = createButton("assets/buttons/default-button.png", "Exit", .5, .7, 300, 75); // Exit button

    // Set up onClick actions for each button
    menuScreen->buttons[0].onClick = startGame;
    menuScreen->buttons[1].onClick = openSettings;
    menuScreen->buttons[2].onClick = exitGame;
}

// Function to render the main menu screen
void renderMenuScreen(Screen *menuScreen, SDL_Surface *screen, TTF_Font *font) {
    // Clear the screen
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    int i;
    for (i = 0; i < menuScreen->buttonCount; i++) {
        renderButton(screen, &(menuScreen->buttons[i]), font);
    }
}



