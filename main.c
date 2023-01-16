#include <stdio.h>
#include <SDL2/SDL.h>
#include "./src/snake.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create the window and renderer
    SDL_Window* window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Create the snake and food
    Snake snake = create_snake(WIDTH / 2, HEIGHT / 2);
    Food food = create_food();

    // Game loop
    int running = 1;
    while (running) {
        // Handle input
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            } else if (event.type == SDL_KEYDOWN) {
                if(snake.length > 2){
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            if (snake.dir != DOWN)
                                snake.dir = UP;
                            break;
                        case SDLK_DOWN:
                            if (snake.dir != UP)
                                snake.dir = DOWN;
                            break;
                        case SDLK_LEFT:
                            if (snake.dir != RIGHT)
                                snake.dir = LEFT;
                            break;
                        case SDLK_RIGHT:
                            if (snake.dir != LEFT)
                                snake.dir = RIGHT;
                            break;
                    }
                } else {
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            snake.dir = UP;
                            break;
                        case SDLK_DOWN:
                            snake.dir = DOWN;
                            break;
                        case SDLK_LEFT:
                            snake.dir = LEFT;
                            break;
                        case SDLK_RIGHT:
                            snake.dir = RIGHT;
                            break;
                    }
                }
            }
        }

        // Update the snake's position
        update_snake(&snake);

        // Check for collisions
        if (check_collision(snake, food)) {
            food = create_food();
            grow_snake(&snake);
            snake.body[snake.length - 1] = snake.head;
        }

        if (check_collision_with_walls(snake, WIDTH, HEIGHT) || check_collision_with_body(snake)) {
            printf("Game Over\n");
            running = 0;
        }

        // Render the snake and food
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_snake(renderer, snake);
        render_food(renderer, food);

        SDL_RenderPresent(renderer);

        // Wait for a bit before updating again
        SDL_Delay(100);
    }

    // Clean up
    destroy_snake(&snake);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}