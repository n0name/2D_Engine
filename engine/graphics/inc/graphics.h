#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL/SDL.h>
#include <SDL/SDL_keyboard.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_image.h>

#include "graphicsobject.h"
#include "dlist.h"

class Graphics{

public:
    // Public Methods:
    Graphics *InitGraphics(int width, int height, int bpp);
    Graphics *GetHandle();
    ~Graphics();
    static SDL_Surface* LoadImage(const char* image);

private:
    // Private Methods:
    Graphics(int w, int h, int bp);
    void GraphicsThread(void *data);

    // Private Variables:
    static Graphics *Handle;
    static SDL_Surface *screen;
    static int iWidth;
    static int iHeigth;
    static int iBpp;
    double_linked<GraphicsObject> dlObjectList;


}







#endif /// GRAPHICS_H
