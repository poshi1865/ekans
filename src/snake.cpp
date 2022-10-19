#include "snake.h"
#include "game.h"
#include <SDL2/SDL_keycode.h>

Snake::Snake(int snake_headx, int snake_heady, int length, int width)
: m_length(length), m_width(width) {
    
    velocity = 5;
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
    for (int i = 0; i < m_length * SNAKE_NODE_HEIGHT; i += SNAKE_NODE_HEIGHT) {
        SDL_Rect temp;
        temp.x = head.x;
        temp.y = head.y + i;
        temp.w = m_width;
        temp.h = SNAKE_NODE_HEIGHT;
        snake_queue.push_back(temp);
    }
}

void Snake::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &head);
    for (SDL_Rect rect : snake_queue) {
        SDL_RenderFillRect(renderer, &rect);
    }
    //SDL_RenderPresent(renderer);
}

void Snake::update() {
    if (KEY_UP) {
        head.y -= velocity;
    }
    if (KEY_DOWN) {
        head.y += velocity;
    }
    if (KEY_LEFT) {
        head.x -= velocity;
    }
    if (KEY_RIGHT) {
        head.x += velocity;
    }

    if (KEY_LEFT || KEY_RIGHT || KEY_DOWN || KEY_UP) {
        //Make the rest of the snake body follow the head
        int prev_x = head.x;
        int prev_y = head.y; 
        for (SDL_Rect& rect : snake_queue) {
            int tempx = rect.x;
            int tempy = rect.y;

            rect.x = prev_x;
            rect.y = prev_y;

            prev_x = tempx;
            prev_y = tempy;
        }
    }
}

/* If a key is pressed, the head of the snake will get updated, and
 * the rest of the rects that make up the snake will take over the position
 * that the rect in front of them was occupying previously */
void Snake::handle_input(SDL_Event event) {
    if (event.key.keysym.sym == SDLK_UP) {
        KEY_UP = true;
        KEY_DOWN = false;
        KEY_LEFT = false;
        KEY_RIGHT = false;
    }
    if (event.key.keysym.sym == SDLK_DOWN) {
        KEY_DOWN = true;
        KEY_UP = false;
        KEY_LEFT = false;
        KEY_RIGHT = false;
    }
    if (event.key.keysym.sym == SDLK_LEFT) {
        KEY_LEFT = true;
        KEY_DOWN = false;
        KEY_RIGHT = false;
        KEY_UP = false;
    }
    if (event.key.keysym.sym == SDLK_RIGHT) {
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

