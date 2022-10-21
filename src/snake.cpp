#include "snake.h"
#include "game.h"
#include <SDL2/SDL_keycode.h>

Snake::Snake(int snake_headx, int snake_heady, int length)
: m_length(length) {
    
    velocity = SNAKE_NODE_HEIGHT;
    KEY_LEFT = false;
    KEY_LEFT = false;
    KEY_LEFT = false;
    KEY_LEFT = false;
    //Init head
    head.x = snake_headx;
    head.y = snake_heady;
    head.w = SNAKE_NODE_WIDTH;
    head.h = SNAKE_NODE_HEIGHT;

    snake_queue.push_back(head);

    //Init rest of snake
    for (int i = SNAKE_NODE_HEIGHT; i < m_length * SNAKE_NODE_HEIGHT; i += SNAKE_NODE_HEIGHT) {
        SDL_Rect temp;
        temp.x = head.x;
        temp.y = head.y + i;
        temp.w = SNAKE_NODE_WIDTH;
        temp.h = SNAKE_NODE_HEIGHT;
        snake_queue.push_back(temp);
    }
}

void Snake::render(SDL_Renderer* renderer) {
    int r = 255;
    int g = 255;
    int b = 255;
    
    //head is white in color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (SDL_Rect rect : snake_queue) {
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, r=(r+30)%255, g=(g+70)%255, b=(b+90)%255, 255);
    }
}

//TODO: FIX SNAKE NODES OVERLAPPING WHEN SNAKE STARTS TO RUN
void Snake::update() {
    int prev_x = head.x;
    int prev_y = head.y;
    int y_offset = 0;
    int x_offset = 0;

    if (KEY_UP && !KEY_DOWN) {
        head.y -= velocity;
        prev_x = head.x;
        y_offset = SNAKE_NODE_HEIGHT - velocity;
        prev_y = head.y + y_offset;
    }
    if (KEY_DOWN && !KEY_UP) {
        head.y += velocity;
        prev_x = head.x;
        y_offset = velocity - SNAKE_NODE_HEIGHT;
        prev_y = head.y + y_offset;
    }
    if (KEY_LEFT && !KEY_RIGHT) {
        head.x -= velocity;
        x_offset = SNAKE_NODE_HEIGHT - velocity;
        prev_x = head.x + x_offset;
        prev_y = head.y;
    }
    if (KEY_RIGHT && !KEY_LEFT) {
        head.x += velocity;
        x_offset = velocity - SNAKE_NODE_HEIGHT;
        prev_x = head.x + x_offset;
        prev_y = head.y;
    }

    if (KEY_LEFT || KEY_RIGHT || KEY_DOWN || KEY_UP) {
        //Make the rest of the snake body follow the head
        for (SDL_Rect& rect : snake_queue) {
            int tempx = rect.x;
            int tempy = rect.y;

            rect.x = prev_x;
            rect.y = prev_y;

            prev_x = tempx + x_offset;
            prev_y = tempy + y_offset;
        }
    }
}

/* If a key is pressed, the head of the snake will get updated, and
 * the rest of the rects that make up the snake will take over the position
 * that the rect in front of them was occupying previously */
void Snake::handle_input(SDL_Event event) {
    if (event.key.keysym.sym == SDLK_UP && !KEY_DOWN) {
        KEY_UP = true;
        KEY_DOWN = false;
        KEY_LEFT = false;
        KEY_RIGHT = false;
    }
    if (event.key.keysym.sym == SDLK_DOWN && !KEY_UP) {
        KEY_DOWN = true;
        KEY_UP = false;
        KEY_LEFT = false;
        KEY_RIGHT = false;
    }
    if (event.key.keysym.sym == SDLK_LEFT && !KEY_RIGHT) {
        KEY_LEFT = true;
        KEY_DOWN = false;
        KEY_RIGHT = false;
        KEY_UP = false;
    }
    if (event.key.keysym.sym == SDLK_RIGHT && !KEY_LEFT) {
        KEY_RIGHT = true;
        KEY_DOWN = false;
        KEY_LEFT = false;
        KEY_UP = false;
    }
    if (event.key.keysym.sym == SDLK_s) {
        KEY_RIGHT = false;
        KEY_DOWN = false;
        KEY_LEFT = false;
        KEY_UP = false;
    }
}

