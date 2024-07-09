#include "Game.h"
#include "TextureManager.h"
#include "GameObjects/GameObjects.h"
#include "GameObjects/KeyboardComponent.h"
#include "Collision.h"

#include <iostream>

SDL_Event Game::event;

Paddle player1{};
Paddle player2{};
Ball ball{};

KeyboardComponent keyboardComponentP1{player1, SDLK_w, SDLK_s};
KeyboardComponent keyboardComponentP2{player2, SDLK_UP, SDLK_DOWN};

void Game::initGame(const char *windowTitle, int windowWidth, int windowHeight)
{
    SDL_WindowFlags flags{0};

    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        m_gameWindow = SDL_CreateWindow(windowTitle, windowWidth, windowHeight, flags);
        if (!m_gameWindow)
        {
            std::cerr << "Could not create window\n"
                      << SDL_GetError() << "\n";
        }

        gameRenderer = SDL_CreateRenderer(m_gameWindow, NULL);
        if (!gameRenderer)
        {
            std::cerr << "Could not create renderer\n"
                      << SDL_GetError() << "\n";
        }
        SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 1);

        m_isRunning = true;

        setWindowIcon("assets/paddle.png");

        player1.init("./assets/paddle.png", 1, windowWidth, windowHeight);
        player2.init("./assets/paddle.png", 2, windowWidth, windowHeight);
        ball.init("./assets/paddle.png", windowWidth, windowHeight);
    }
    else
    {
        std::cerr << "Failed to initialized\n"
                  << SDL_GetError() << "\n";
        m_isRunning = false;
    }
}

void Game::setWindowIcon(const char *iconPath)
{
    SDL_Surface *tmpSurface{IMG_Load(iconPath)};
    SDL_SetWindowIcon(m_gameWindow, tmpSurface);
    SDL_DestroySurface(tmpSurface);
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_EVENT_QUIT:
        m_isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    keyboardComponentP1.update();
    keyboardComponentP2.update();
    player1.update();
    player2.update();
    ball.update();

    if (Collision::AABB(player1.destRect, ball.destRect))
    {
        ball.handleBounce(player1.destRect, player1.paddleVelocity);
    }

    if (Collision::AABB(player2.destRect, ball.destRect))
    {
        ball.handleBounce(player2.destRect, player2.paddleVelocity);
    }

    if (Collision::windowTBCollision(ball.destRect))
    {
        ball.handleWallBounce();
    }

    if (Collision::goalCollision(ball.destRect))
    {
        end(Collision::goalCollision(ball.destRect));
    }
};

void Game::render()
{
    SDL_RenderClear(gameRenderer);
    player1.draw();
    player2.draw();
    ball.draw();
    SDL_RenderPresent(gameRenderer);
};

void Game::end(int loserPlayer)
{
    SDL_Texture *gameOverTex = TextureManager::LoadTexture("./assets/GameOver.png");

    SDL_Texture *winnerPlayerTex{nullptr};
    if (loserPlayer == 1)
    {
        winnerPlayerTex = TextureManager::LoadTexture("./assets/player2_winscreen.png");
    }
    else
    {
        winnerPlayerTex = TextureManager::LoadTexture("./assets/player1_winscreen.png");
    }

    SDL_RenderClear(gameRenderer);
    player1.draw();
    player2.draw();
    TextureManager::Draw(gameOverTex, {0.0f, 0.0f, 350.0f, 100.0f}, {360.0f - 350.0f / 2, 240.0f - 100.0f / 2 - 25, 350.0f, 100.0f});
    TextureManager::Draw(winnerPlayerTex, {0.0f, 0.0f, 350.0f, 50.0f}, {360.0f - 350.0f / 2, 240.0f - 50.0f / 2 + 25, 350.0f, 50.0f});
    SDL_RenderPresent(gameRenderer);

    bool quit = 0;
    while (!quit)
    {
        if (SDL_WaitEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                quit = true;
            }
        }
    }

    m_isRunning = 0;
}

void Game::clean()
{
    SDL_DestroyWindow(m_gameWindow);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
};

bool Game::running()
{
    return m_isRunning;
}
