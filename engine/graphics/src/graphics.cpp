#include "graphics.h"


Graphics* Graphics::Handle;
SDL_Surface* Graphics::screen;
SDL_Rect    Graphics::screenRect;
int Graphics::iWidth;
int Graphics::iHeigth;
int Graphics::iBpp;

double_linked<GraphicsObject *> Graphics::dlObjectList;
double_linked<GraphicsObject *> Graphics::dlSpriteList;

struct ThreadData_t Graphics::ThreadData;


Graphics *Graphics::InitGraphics(int width, int height, int bpp)
{
    if (!Graphics::Handle)
    {
        Graphics::Handle = new Graphics(width, height, bpp);
        Graphics::ThreadData.graphMutex = SDL_CreateMutex();
        SDL_LockMutex(Graphics::ThreadData.graphMutex);
        SDL_CreateThread(Graphics::GraphicsThread,  (void *)(&Graphics::ThreadData));
    }
    return Graphics::Handle;
}

Graphics::Graphics(int w, int h, int bp)
{

    Graphics::iWidth = w;
    Graphics::iHeigth = h;
    Graphics::iBpp =bp;
    SDL_Init(SDL_INIT_VIDEO);
    Graphics::screen = SDL_SetVideoMode(Graphics::iWidth, Graphics::iHeigth, Graphics::iBpp, SDL_DOUBLEBUF | SDL_ANYFORMAT);
    Graphics::screenRect.w = w;
    Graphics::screenRect.h = h;
    Graphics::screenRect.x = 0;
    Graphics::screenRect.y = 0;
}

Graphics::~Graphics()
{
    SDL_FreeSurface(Graphics::screen);
}
Graphics *Graphics::GetHandle()
{
    if (!Graphics::Handle)
        throw("Graphics are not initalized!");
    return Graphics::Handle;
}

SDL_Surface* Graphics::LoadImage(const char* image)
{
    SDL_Surface *tmp;
    tmp = IMG_Load(image);
    return SDL_DisplayFormat(tmp);
}


int Graphics::GraphicsThread(void *data)
{
    int flag = 1;
    GraphicsObject *curObject = Graphics::dlObjectList.get_head();
    struct ThreadData_t *privateData = (struct ThreadData_t *)data;


    while(flag)
    {
        SDL_LockMutex(privateData->graphMutex);

        while(1)
        {
           if (curObject)
           {
               curObject->blit_to_surface(Graphics::screen, Graphics::screenRect);
               curObject = Graphics::dlObjectList.get_next();
           }
           else
           {
               break;
           }
        }
        SDL_Flip(Graphics::screen);

        SDL_LockMutex(privateData->graphMutex);
    }
    return 0;
}


void Graphics::Update()
{
    SDL_UnlockMutex(Graphics::ThreadData.graphMutex);
}

void Graphics::AddObject(GraphicsObject *obj)
{
    dlObjectList.push_front(obj);
}

void Graphics::AddSprite(GraphicsObject *spr)
{
    dlSpriteList.push_front(spr);
}

