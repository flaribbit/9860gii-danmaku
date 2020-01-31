#include "wrapper.h"
#include "game.h"
int WinMain(int argc, char *argv[])
{
    Window_Init();
    for(;frames;frames++){
        UpdateMessage();
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
