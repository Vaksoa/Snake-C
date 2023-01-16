#include <SDL2/SDL.h>

#include "snake.h"
#include "global.h"

// Creates a new snake at the specified position
Snake create_snake(int x, int y) {
    Snake snake;
    snake.length = 2;
    snake.head.x = x;
    snake.head.y = y;
    snake.body = NULL;
    snake.dir = RIGHT;
    snake.hasMoved = false;
    return snake;
}


// Destroys the snake and frees any allocated memory
void destroy_snake(Snake* snake) {
    free(snake->body);
}

// Moves the snake in the current direction
void update_snake(Snake* snake) {
    // Move the body segments forward
    if (snake->body != NULL) {
        for (int i = snake->length - 1; i > 0; i--) {
            snake->body[i] = snake->body[i-1];
        }
    }
    // Move the head in the current direction
    switch (snake->dir) {
        case UP:
            snake->head.y -= BLOCK_SIZE;
            break;
        case DOWN:
            snake->head.y += BLOCK_SIZE;
            break;
        case LEFT:
            snake->head.x -= BLOCK_SIZE;
            break;
        case RIGHT:
            snake->head.x += BLOCK_SIZE;
            break;
    }
    // Add the new head to the body
    if (snake->body != NULL)
        snake->body[0] = snake->head;
    snake->hasMoved = true;
}

// Adds a segment to the end of the snake
void grow_snake(Snake* snake) {
    if(snake->body == NULL){
        snake->body = malloc(sizeof(Segment));
    }else{
        snake->body = realloc(snake->body, sizeof(Segment) * (snake->length + 1));
    }
    snake->length++;
}

// Renders the snake on the specified renderer
void render_snake(SDL_Renderer* renderer, Snake snake) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rect = {snake.head.x, snake.head.y, BLOCK_SIZE, BLOCK_SIZE};
    SDL_RenderFillRect(renderer, &rect);
    if (snake.body != NULL) {
        for (int i = 0; i < snake.length - 1; i++) {
            rect.x = snake.body[i].x;
            rect.y = snake.body[i].y;
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

// Returns 1 if the snake is colliding with the specified food, 0 otherwise
int check_collision(Snake snake, Food food) {
    return (snake.head.x == food.x && snake.head.y == food.y);
}

// Returns 1 if the snake is colliding with the walls, 0 otherwise
int check_collision_with_walls(Snake snake, int screen_width, int screen_height) {
    return snake.head.x < 0 || snake.head.x + BLOCK_SIZE > screen_width || snake.head.y < 0 || snake.head.y + BLOCK_SIZE > screen_height;
}

// Returns 1 if the snake is colliding with its own body, 0 otherwise
int check_collision_with_body(Snake snake) {
//    if(snake.body != NULL){
//        for (int i = 0; i < snake.length - 1; i++) {
//            if (snake.head.x == snake.body[i].x && snake.head.y == snake.body[i].y) {
//                return 1;
//            }
//        }
//    }
    return 0;
}