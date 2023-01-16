#ifndef FOOD_H
#define FOOD_H

#include "global.h"

typedef struct Food {
    int x;
    int y;
} Food;

// Creates a new food at a random position
Food create_food();

// Renders the food on the specified renderer
void render_food(SDL_Renderer* renderer, Food food);

#endif
