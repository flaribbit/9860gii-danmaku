#include "wrapper.h"
#include "game.h"
#include "res.h"
int WinMain(int argc, char *argv[])
{
    Window_Init();
    for(;frames;frames++){
        int i;
        ScreenClear();
        for(i=0;i<64;i++){
            DrawPoint(2*i,i);
            DrawPoint(2*i+1,i);
        }
        for(i=0;i<5;i++){
            DrawImage(res[i],64,10*i);
        }
        UpdateMessage();
        ScreenRefresh();
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
