#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class GraphicsObject
{
public:
    GraphicsObject(const char* image, int w, int h);
    ~GraphicsObject();
    void blit_to_surface(SDL_Surface *surface, SDL_Rect r);
    bool Visible;

private:
    SDL_Surface *pTexture;
    SDL_Rect rect;


};

#endif // GRAPHICSOBJECT_H
