#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL/SDL.h>
#include <SDL/SDL_keyboard.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_image.h>

class mGraphics{

public:
    // Public Methods:
    mGraphics *InitGraphics(int width, int height, int bpp);
    mGraphics *GetHandle();
    ~mGraphics();

private:
    // Private Methods:
    mGraphics(int w, int h, int bp);
    void GraphicsThread(void *data);

    // Private Variables:
    static mGraphics *Handle;
    SDL_Surface *screen;
    int iWidth;
    int iHeigth;
    int iBpp;
}







#endif /// GRAPHICS_H
