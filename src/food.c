#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#include "food.h"
#include "global.h"

// Creates a new food at a random position
Food create_food() {
    srand(time(NULL));
    Food food;
    food.x = (rand() % (800 / BLOCK_SIZE)) * BLOCK_SIZE;
    food.y = (rand() % (600 / BLOCK_SIZE)) * BLOCK_SIZE;
    return food;
}

// Renders the food on the specified renderer
void render_food(SDL_Renderer* renderer, Food food) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = {food.x, food.y, BLOCK_SIZE, BLOCK_SIZE};
    SDL_RenderFillRect(renderer, &rect);
}