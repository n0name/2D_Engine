#include <stdio.h>

#include <math.h>

#include <SDL/SDL.h>
#include <SDL/SDL_keyboard.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_image.h>


#include "types.h"
#include "soldier.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 8

SDL_Surface *screen;
SDL_Surface *mouse_cursor;
int main()
{

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_DOUBLEBUF | SDL_ANYFORMAT);
    if (!screen)
    {
        ERROR("Failed to set Video Mode")
    }
    SDL_ShowCursor(SDL_ENABLE);

    mouse_cursor  = Load_Image("mouse.gif");
    SDL_Rect mouse_rect;
    mouse_rect.w = mouse_cursor->w;
    mouse_rect.h = mouse_cursor->h;

    Soldier s1;

    SDL_Event event;

    bool Run = true;

    s1.set_pos(20,20);

    while (Run)
    {
        SDL_GetMouseState((int *)&mouse_rect.x, (int *)&mouse_rect.y);
        while (SDL_PollEvent( &event))
        {
            if ( event.key.keysym.sym == SDLK_ESCAPE )
                Run = false;
            if ( ( event.button.type = SDL_MOUSEBUTTONUP ) && ( event.button.button == SDL_BUTTON_LEFT ) )
            {
                s1.set_target(mouse_rect.x, mouse_rect.y);
                s1.moving = true;
            }

        }

        clear_to_color(screen, 0x00);

        SDL_BlitSurface( mouse_cursor, NULL, screen, &mouse_rect);
        s1.move();
        s1.draw(screen);
        SDL_Flip( screen);
    }
    SDL_Quit();
    return 0;
}


