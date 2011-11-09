#include <stdio.h>

#include <math.h>
#include <graphics.h>
#include <input.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 8

int InitAll();
void DeinitAll();

int main(int argc, char *argv[])
{
	bool running = 1;

	if(InitAll())
	{
		return -1;
	}

    Graphics::AddObject(new GraphicsObject("pacman.jpg", 0, 0));

    while(running)
    {
    	if(KeyboardHandler::isPressed(SDLK_ESCAPE))
    	{
    		running = 0;
    	}
        Graphics::Update();
    }


    DeinitAll();

    return 0;
}


int InitAll()
{
	printf("\n== Init Graphics... ==");
	Graphics::InitGraphics(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	if (!Graphics::GetHandle())
	{
		printf("\nCould not init Graphics");
		return 1;
	}

	printf("\n== Init KeyboardHandler... ==");
	KeyboardHandler::InitKeyboardHandler();
	if(!KeyboardHandler::GetHandle())
	{
		printf("\nCould not init KeyHandler");
		return 1;
	}
	printf("\n== Init Complete ==");
	return 0;
}

void DeinitAll()
{
	printf("\nDEINIT");
	KeyboardHandler::DeinitKeyboardHandler();
	Graphics::DeinitGraphics();
}
