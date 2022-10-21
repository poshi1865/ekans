#ifndef _SNAKE_H
#define _SNAKE_H

#include "commons.h"
#include <deque>

class Snake : public SDL_Rect {
private:
    SDL_Rect head;
    int m_length;
    int m_width;

    int velocity;
    
    std::deque<SDL_Rect> snake_queue;

    //KEY PRESSES
    bool KEY_UP;
    bool KEY_DOWN;
    bool KEY_LEFT;
    bool KEY_RIGHT;

public:
    Snake(int headx, int heady, int length);
    void render(SDL_Renderer* renderer);
    void update();
    void handle_input(SDL_Event event);
};

#endif
