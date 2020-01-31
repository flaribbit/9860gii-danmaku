#include <stdio.h>
#include "SDL2/SDL.h"
extern SDL_Renderer *renderer;
extern SDL_Window *window;
#define FACTOR 4
#define WIDTH (FACTOR*128)
#define HEIGHT (FACTOR*64)
void Window_Init();
void DrawPoint();
void DrawImage();
void DrawLine();
