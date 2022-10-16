#ifndef _GAME_H
#define _GAME_H

#include "commons.h"
#include "constants.h"

class Game {
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    void render(void);
    void update(void);
    void handle_input(void);

public:

    Game(void);
    ~Game(void);

    /* used to run the game, will contain the game loop*/
    void run(void);

};

#endif
