#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL/SDL.h>
#include <SDL/SDL_keyboard.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_image.h>

#include "graphicsobject.h"
#include "dlist.h"

struct ThreadData_t {
        SDL_mutex *graphMutex;
};

class Graphics{

public:
    // Public Methods:
    static Graphics *InitGraphics(int width, int height, int bpp);
    static Graphics *GetHandle();
    ~Graphics();
    static SDL_Surface* LoadImage(const char* image);
    static void Update();
    static void AddObject(GraphicsObject *obj);
    static void AddSprite(GraphicsObject *spr);

private:
    // Private Methods:
    Graphics(int w, int h, int bp);
    static int GraphicsThread(void *data);

    // Private Variables:
    static Graphics *Handle;
    static SDL_Surface *screen;
    static SDL_Rect    screenRect;
    static int iWidth;
    static int iHeigth;
    static int iBpp;
    static double_linked<GraphicsObject *> dlObjectList;
    static double_linked<GraphicsObject *> dlSpriteList;

    static struct ThreadData_t ThreadData;


};







#endif /// GRAPHICS_H
