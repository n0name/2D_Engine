#include "graphicsobject.h"
#include "graphics.h"

GraphicsObject::GraphicsObject(const char *image, int w, int h)
{
    SDL_Rect r;
    this->pTexture = Graphics::LoadImage(image);

    if (w && h)
    {
        r.x = 0;
        r.y = 0;
        r.w = w;
        r.h = h;
    }else
    {
        r.x = 0;
        r.y = 0;
        r.w = this->pTexture->w;
        r.h = this->pTexture->h;
    }

    this->rect = r;
    this->Visible = true;
}

GraphicsObject::~GraphicsObject()
{
    SDL_FreeSurface(this->pTexture);
}

void GraphicsObject::blit_to_surface(SDL_Surface *surface, SDL_Rect r)
{
    SDL_BlitSurface(this->pTexture, &this->rect, surface, &r);
}
