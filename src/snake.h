#include "commons.h"
#include <deque>

class Snake : public SDL_Rect {
private:
    int m_x;
    int m_y;
    int m_length;
    int m_width;
    
    std::deque<SDL_Rect> sq;

public:
    Snake(int x, int y, int length, int width);
    void render(SDL_Renderer* renderer);
    void update();
    void handle_input();
};
