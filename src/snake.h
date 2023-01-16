#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>

#include "food.h"
#include "global.h"

typedef struct Segment {
    int x;
    int y;
} Segment;

typedef struct SegmentNode {
    Segment data;
    struct SegmentNode* next;
} SegmentNode;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct Snake {
    int length;
    Segment head;
    SegmentNode* body;
    Direction dir;
} Snake;

// Creates a new snake at the specified position
Snake create_snake(int x, int y);

// Destroys the snake and frees any allocated memory
void destroy_snake(Snake* snake);

// Moves the snake in the current direction
void update_snake(Snake* snake);

// Adds a segment to the end of the snake
void grow_snake(Snake* snake);

// Renders the snake on the specified renderer
void render_snake(SDL_Renderer* renderer, Snake snake);

// Returns 1 if the snake is colliding with the specified food, 0 otherwise
int check_collision(Snake snake, Food food);

// Returns 1 if the snake is colliding with the walls, 0 otherwise
int check_collision_with_walls(Snake snake, int screen_width, int screen_height);

// Returns 1 if the snake is colliding with its own body, 0 otherwise
int check_collision_with_body(Snake snake);

#endif
