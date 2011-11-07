#include <stdio.h>

#include <math.h>
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 8

int main(int argc, char *argv[])
{
	bool running = 1;

    Graphics::InitGraphics(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);

    Graphics::AddObject(new GraphicsObject("pacman.jpg", 0, 0));


    SDL_Event event;
    while(running)
    {
    	/// @TODO add keyboard handler
    	while(SDL_PollEvent(&event))
    	{
    		switch(event.type)
    		{
    		case SDL_KEYUP:
				if(SDLK_ESCAPE == event.key.keysym.sym)
				{
					running = 0;
				}
    			break;
    		case SDL_KEYDOWN:
    			break;
    		default:
    			break;
    		}
    	}

        Graphics::Update();
    }

    Graphics::DeinitGraphics();

    return 0;
}


