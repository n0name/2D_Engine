#include <stdio.h>

#include <math.h>
#include <graphics.h>
#include <input.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 8

void InitAll();
void DeinitAll();

int main(int argc, char *argv[])
{
	bool running = 1;

	InitAll();

    Graphics::AddObject(new GraphicsObject("pacman.jpg", 0, 0));

    while(running)
    {
    	if (KeyboardHandler::isPressed(SDLK_ESCAPE))
    	{
    		running = 0;
    	}
        Graphics::Update();
    }

    DeinitAll();

    return 0;
}


void InitAll()
{
	Graphics::InitGraphics(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	KeyboardHandler::InitKeyboardHandler();
}

void DeinitAll()
{
	KeyboardHandler::DeinitKeyboardHandler();
	Graphics::DeinitGraphics();
}
