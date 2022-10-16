#include "game.h"

Game::Game(void) {

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize SDL2" << std::endl;
        exit(1);
    }

    this->m_window = SDL_CreateWindow("ekans", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    if (!m_window) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer) {
        std::cout << "Failed to create renderer context: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Game::run(void) {
    while (true) {
        update();
        handle_input();
        render();
    }
}

void Game::render(void) {
    //Clear screen
    SDL_SetRenderDrawColor(m_renderer, 95, 128, 255, 255);
    SDL_RenderClear(m_renderer);

    //SDL_SetRenderDrawColor(m_renderer, 128, 255, 255, 255);
    //SDL_Rect r;
    //r.x = 100;
    //r.y = 100;
    //r.w = 50;
    //r.h = 50;

    //SDL_RenderDrawRect(m_renderer, &r);

    SDL_RenderPresent(m_renderer);
}

void Game::update(void) {
}

void Game::handle_input(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            default:
                break;
        }
    }
}

Game::~Game() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


















