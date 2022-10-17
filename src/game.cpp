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

    snake = new Snake(100, 100, 10, 13);
}

void Game::run(void) {
    while (true) {
        update();
        handle_input();
        render();
        SDL_Delay(10);
    }
}

void Game::render(void) {
    //Clear screen
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    snake->render(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void Game::update(void) {
    snake->update();
}

void Game::handle_input(void) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                snake->handle_input(event);
                break;
            default:
                break;
        }
    }
}

Game::~Game(void) {
    delete snake;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


















