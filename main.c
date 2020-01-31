#include <math.h>
#include "game.h"
#include "res.h"
int WinMain(int argc, char *argv[])
{
    Window_Init();
    for(;frames;frames++){
        int i;
        ScreenClear();
        if(frames%2==0){
            float angle=frames/2/31.*_2PI;
            Danmaku_Add(0,64,32,cosf(angle),sinf(angle));
            Danmaku_Add(0,64,32,cosf(1.57+angle),sinf(1.57+angle));
            Danmaku_Add(0,64,32,cosf(3.14+angle),sinf(3.14+angle));
            Danmaku_Add(0,64,32,cosf(4.71+angle),sinf(4.71+angle));

            Danmaku_Add(1,80,40,0.8*cosf(-angle),0.6*sinf(-angle));
            Danmaku_Add(1,80,40,0.8*cosf(3.14-angle),0.6*sinf(3.14-angle));
        }
        UpdateMessage();
        Danmaku_Update();
        Danmaku_Draw();
        ScreenRefresh();
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
