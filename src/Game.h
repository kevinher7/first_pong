#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>

class Game
{
public:
    Game() : m_isRunning{false}, m_gameWindow{nullptr} {};
    Game(const Game &) noexcept : m_isRunning{false}, m_gameWindow{nullptr} {}
    Game &operator=(const Game &) noexcept = delete;
    Game(Game &&) noexcept : m_isRunning{false}, m_gameWindow{nullptr} {}
    Game &operator=(Game &&) = delete;
    ~Game(){};

    void initGame(const char *windowTitle, int windowWidth, int windowHeight);
    void setWindowIcon(const char *iconPath);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(); // podria hacerse bool running() const;

    inline static SDL_Renderer *gameRenderer{nullptr};
    static SDL_Event event;

private:
    bool m_isRunning;
    SDL_Window *m_gameWindow;
};

#endif
