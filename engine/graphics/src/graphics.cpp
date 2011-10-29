#include "graphics.h"


mGraphics *mGraphics::InitGraphics(int width, int height, int bpp)
{
    if (!mGraphics.Handle)
    {
        mGraphics.Handle = new mGraphics(width, height, bpp);
    }
    return mGraphics.Handle;
}

mGraphics::mGraphics(int w, int h, int bp)
{
    this->iWidth = w;
    this->iHeigth = h;
    this->iBpp =bp;
    SDL_Init(SDL_INIT_VIDEO);
    this->screen = SDL_SetVideoMode(this->iWidth, this->iHeigth, this->iBpp, SDL_DOUBLEBUF | SDL_ANYFORMAT);
}

mGraphics::~mGraphics()
{
    SDL_FreeSurface(this->screen);
}
mGraphics *mGraphics::GetHandle()
{
    return mGraphics.Handle;
}
