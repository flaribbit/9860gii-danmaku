#include "wrapper.h"
#define DANMAKU_MAXLEN 200
int frames=1;
float CameraY=0;
float CameraVY=0;
typedef struct{
    unsigned char type;
    int timer;
    float x,y,vx,vy;
}_Danmaku;
_Danmaku Danmaku[DANMAKU_MAXLEN];
int DanmakuLength=0;

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

void Danmaku_Add(unsigned char type,float x,float y,float vx,float vy){
    if(DanmakuLength<DANMAKU_MAXLEN){
        _Danmaku *d=Danmaku+DanmakuLength;
        d->timer=0;
        d->type=type;
        d->x=x;
        d->y=y;
        d->vx=vx;
        d->vy=vy;
        DanmakuLength++;
    }
}

int Danmaku_Update00(_Danmaku* d){
    d->x+=d->vx;
    d->y+=d->vy;
    if(d->x>0&&d->x<128&&d->y+CameraY>0&&d->y+CameraY<64){
        return 1;
    }else{
        return 0;
    }
}
int Danmaku_Draw00(_Danmaku* d){
    DrawPoint((int)d->x,(int)(d->y+CameraY));
}

int Danmaku_Update01(_Danmaku* d){
    d->x+=d->vx;
    d->y+=d->vy;
    if(d->x>0&&d->x<128&&d->y+CameraY>0&&d->y+CameraY<64){
        return 1;
    }else{
        return 0;
    }
}
int Danmaku_Draw01(_Danmaku* d){
    int x=(int)d->x-1,y=(int)(d->y+CameraY)-1;
    DrawPoint(x+1,y);
    DrawPoint(x+2,y);
    DrawPoint(x,y+1);
    DrawPoint(x,y+2);
    DrawPoint(x+1,y+3);
    DrawPoint(x+2,y+3);
    DrawPoint(x+3,y+1);
    DrawPoint(x+3,y+2);
}

int Danmaku_Update02(_Danmaku* d){
    
}
int Danmaku_Draw02(_Danmaku* d){
    
}

int (*_DanmakuUpdateFunctionTable[10])(_Danmaku*)={
    Danmaku_Update00,
    Danmaku_Update01,
    Danmaku_Update02
};

int (*_DanmakuDrawFunctionTable[10])(_Danmaku*)={
    Danmaku_Draw00,
    Danmaku_Draw01,
    Danmaku_Draw02
};

void Danmaku_Update(){
    int i,j;
    for(i=j=0;i<DanmakuLength;i++){
        _Danmaku *d=Danmaku+i;
        if(_DanmakuUpdateFunctionTable[d->type](d)){
            Danmaku[j]=Danmaku[i];
            j++;
        };
    }
    DanmakuLength=j;
}

void Danmaku_Draw(){
    int i;
    for(i=0;i<DanmakuLength;i++){
        _Danmaku *d=Danmaku+i;
        _DanmakuDrawFunctionTable[d->type](d);
    }
}
