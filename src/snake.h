#include "commons.h"

class Snake : public SDL_Rect {
private:
    float m_x;
    float m_y;
    float m_length;

public:
    void render(SDL_Renderer* renderer);
    void update();
    void handle_input();

};
