#include "snake.h"

Snake::Snake(int x, int y, int length, int width)
: m_x(x), m_y(y), m_length(length), m_width(width) {
    for (int i = 0; i < m_length * 10; i += 10) {
        SDL_Rect temp;
        temp.x = m_x;
        temp.y = m_y + i;
        temp.w = m_width;
        temp.h = 10;
        sq.push_back(temp);
    }
}

void Snake::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (SDL_Rect rect : sq) {
        SDL_RenderFillRect(renderer, &rect);
    }
    //SDL_Rect r;r.x=m_x;r.y=m_y;r.w =m_width;r.h=m_length;
    //SDL_RenderFillRect(renderer, &r);
    //SDL_RenderFillRect(renderer, this);
    
}

void Snake::update() {
}

void Snake::handle_input() {
}

