#include "Rendering/Renderer.h"

int main() {
    if (!Engine::initializeSDL()) {
        return -1;
    }

    Engine::createWindow();
    Engine::cleanupSDL();

    return 0;
}
