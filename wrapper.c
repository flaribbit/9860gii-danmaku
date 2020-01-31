#include "wrapper.h"
SDL_Renderer *renderer;
SDL_Window *window;

void Window_Init(){
    window=SDL_CreateWindow("demo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

void ScreenClear(){
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
}

void ScreenRefresh(){
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/60);
}

void DrawPoint(int x, int y){
    SDL_Rect rect;
    rect.w=FACTOR;
    rect.h=FACTOR;
    rect.x=x*FACTOR;
    rect.y=y*FACTOR;
    SDL_RenderFillRect(renderer,&rect);
}

void DrawImage(unsigned char *image,int x, int y){
    int i,j;
    for(i=0;i<8;i++){
        unsigned char t=image[i];
        for(j=0;j<8;j++){
            if(t&0x80){
                DrawPoint(x+j,y+i);
            }
            t<<=1;
        }
    }
}

void DrawLine(){

}
