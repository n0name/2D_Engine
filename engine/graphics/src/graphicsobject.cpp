#include "graphicsobject.h"

graphicsObject::graphicsObject(char *image, int w, int h)
{
    SDL_Rect r;
    this->pTexture = graphicsObject::Load_Image(image);

    r.x = 0;
    r.y = 0;
    r.w = w;
    r.h = h;

    this->rect = r;
}

graphicsObject::~graphicsObject()
{
    SDL_FreeSurface(this->pTexture);
}
