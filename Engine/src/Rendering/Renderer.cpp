#include <SDL2/SDL.h>
#include <iostream>
#include "Rendering/Renderer.h"

namespace Engine {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool initializeSDL() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
            return false;
        }
        std::cout << "SDL initialized successfully." << std::endl;
        return true;
    }

    void createWindow() {
        window = SDL_CreateWindow(
                "SDL Window",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                800,
                600,
                SDL_WINDOW_SHOWN
        );

        if (!window) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            return;
        } else {
            std::cout << "SDL window created successfully." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            return;
        } else {
            std::cout << "SDL renderer created successfully." << std::endl;
        }

        // Pump events to ensure the window is visible
        //SDL_PumpEvents();

        // Set background color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);


        // Set up your rectangle's initial position outside the loop
        SDL_Rect rect;
        rect.x = 100;
        rect.y = 100;
        rect.w = 200;
        rect.h = 150;

        bool running = true;
        SDL_Event event;

        while (running) {
            // 1. Event Polling & Input Handling
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
                if (event.type == SDL_KEYDOWN) {
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            rect.y -= 10;
                            break;
                        case SDLK_DOWN:
                            rect.y += 10;
                            break;
                        case SDLK_LEFT:
                            rect.x -= 10;
                            break;
                        case SDLK_RIGHT:
                            rect.x += 10;
                            break;
                        default:
                            // Handle other keys if necessary
                            break;
                    }
                }
            }

            // 2. Update game logic (if any beyond key presses)
            // Already done above by changing rect.x when key pressed.

            // 3. Render
            // Clear the screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Draw the rectangle
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);

            // Present the renderer to the window
            SDL_RenderPresent(renderer);
        }
    }

    void cleanupSDL() {
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
        SDL_Quit();
        std::cout << "SDL cleaned up successfully." << std::endl;
    }
}
