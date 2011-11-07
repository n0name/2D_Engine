#include "graphics.h"

Graphics* Graphics::Handle;
SDL_Surface* Graphics::screen;
SDL_Rect    Graphics::screenRect;
int Graphics::iWidth;
int Graphics::iHeigth;
int Graphics::iBpp;

GraphicsObject *Graphics::dlObjectList[100];
GraphicsObject *Graphics::dlSpriteList[100];

struct ThreadData_t Graphics::ThreadData;


Graphics *Graphics::InitGraphics(int width, int height, int bpp)
{
    if (!Graphics::Handle)
    {
        Graphics::Handle = new Graphics(width, height, bpp);
        Graphics::ThreadData.graphMutex = SDL_CreateMutex();
        SDL_LockMutex(Graphics::ThreadData.graphMutex);
        Graphics::ThreadData.thread = SDL_CreateThread(Graphics::GraphicsThread,  (void *)(&Graphics::ThreadData));
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

void Graphics::DeinitGraphics()
{
	if (Graphics::Handle)
		SDL_KillThread(Graphics::ThreadData.thread);
		SDL_FreeSurface(Graphics::screen);
		for (int i = 0; Graphics::dlObjectList[i]; i++ )
		{
			free(Graphics::dlObjectList[i]);
		}
		for (int i = 0; Graphics::dlSpriteList[i]; i++ )
		{
			free(Graphics::dlSpriteList[i]);
		}
		delete Graphics::Handle;
		SDL_Quit();
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
    int curObjectIndex = 0;
    struct ThreadData_t *privateData = (struct ThreadData_t *)data;


    while(flag)
    {
        SDL_LockMutex(privateData->graphMutex);

        while(dlObjectList[curObjectIndex])
        {
        	dlObjectList[curObjectIndex]->blit_to_surface(Graphics::screen, Graphics::screenRect);
        	curObjectIndex++;
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
    int i = 0;
    while(dlObjectList[i++]);
    dlObjectList[i-1] = obj;
    i++;
}

void Graphics::AddSprite(GraphicsObject *spr)
{
	int i = 0;
	while(dlSpriteList[i++]);
	dlSpriteList[i-1] = spr;
	i++;
}



