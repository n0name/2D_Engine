#include <stdio.h>

#include <math.h>
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 8

int main()
{
    Graphics::InitGraphics(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);

    Graphics::AddObject(new GraphicsObject("test.jpg", 0, 0));

    while(1)
    {
        Graphics::Update();
    }

    return 0;
}


