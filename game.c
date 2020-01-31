#include "wrapper.h"
int frames=1;
void UpdateMessage(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            frames=-1;
            break;
        case SDL_KEYDOWN:
            break;
        }
    }
}
