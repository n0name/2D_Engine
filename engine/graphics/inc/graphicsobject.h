#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class graphicsObject
{
public:
    graphicsObject(const char* image, int w, int h);
    ~graphicsObject();

private:
    SDL_Surface *pTexture;
    SDL_Rect rect;
    static SDL_Surface* Load_Image(const char* image);

};

#endif // GRAPHICSOBJECT_H
