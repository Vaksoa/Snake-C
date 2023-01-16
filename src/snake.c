#include <SDL2/SDL.h>

#include "snake.h"
#include "global.h"

SegmentNode* create_snake_node(Segment data, SegmentNode* next) {
    SegmentNode* node = (SegmentNode*) malloc(sizeof(SegmentNode));
    node->data = data;
    node->next = next;
    return node;
}

// Creates a new snake at the specified position
Snake create_snake(int x, int y) {
    Snake snake;
    snake.length = 1;
    snake.head.x = x;
    snake.head.y = y;
    snake.body = create_snake_node(snake.head, NULL);;
    snake.dir = RIGHT;
    return snake;
}

// Destroys the snake and frees any allocated memory
void destroy_snake(Snake* snake) {
    free(snake->body);
}

// Moves the snake in the current direction
void update_snake(Snake* snake) {
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

    SegmentNode* current = snake->body;
    while (current->next != NULL) {
        current->data = current->next->data;
        current = current->next;
    }
    current->data = snake->head;
}

// Adds a segment to the end of the snake
void grow_snake(Snake* snake) {
    snake->length++;
    snake->body = create_snake_node(snake->head, snake->body);
}

// Renders the snake on the specified renderer
void render_snake(SDL_Renderer* renderer, Snake snake) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rect = {snake.head.x, snake.head.y, BLOCK_SIZE, BLOCK_SIZE};
    SDL_RenderFillRect(renderer, &rect);
    SegmentNode* current = snake.body;
    while (current != NULL) {
        rect.x = current->data.x;
        rect.y = current->data.y;
        SDL_RenderFillRect(renderer, &rect);
        current = current->next;
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
//    SegmentNode* current = snake.body;
//    while (current != NULL) {
//        if (current->data.x == snake.head.x && current->data.y == snake.head.y) {
//                return 1;
//        }
//        current = current->next;
//    }
    return 0;
}