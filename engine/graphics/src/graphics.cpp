#include "graphics.h"


Graphics *Graphics::InitGraphics(int width, int height, int bpp)
{
    if (!Graphics.Handle)
    {
        Graphics.Handle = new Graphics(width, height, bpp);
    }
    return Graphics.Handle;
}

Graphics::Graphics(int w, int h, int bp)
{
    Graphics.iWidth = w;
    Graphics.iHeigth = h;
    Graphics.iBpp =bp;
    SDL_Init(SDL_INIT_VIDEO);
    Graphics.screen = SDL_SetVideoMode(this->iWidth, this->iHeigth, this->iBpp, SDL_DOUBLEBUF | SDL_ANYFORMAT);
}

Graphics::~Graphics()
{
    SDL_FreeSurface(Graphics.screen);
}
Graphics *Graphics::GetHandle()
{
    if (!Graphics.Handle)
        throw("Graphics are not initalized!");
    return Graphics.Handle;
}

SDL_Surface* Graphics::LoadImage(const char* image)
{
    SDL_Surface *tmp;
    tmp = IMG_Load(image);
    return SDL_DisplayFormat(tmp);
}


void Graphics::GraphicsThread(void *data)
{
    int flag = 1;
    GraphicsObject *curObject;
    while(flag)
    {
        while(1)
        {
           curObject = dlObjectList.get_next();
           if (curObject)
           {
               curObject->blit_to_surface(Graphics.screen, Graphics.);
           }
           else
           {
               break;
           }
        }
        SDL_Flip(Graphics.screen);
    }
}
