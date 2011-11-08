#include "input.h"


KeyboardHandler* KeyboardHandler::Handle;
Uint8 KeyboardHandler::keyState[400];
SDL_Thread* KeyboardHandler::eventThread;

KeyboardHandler::KeyboardHandler()
{
  //Empty
}

KeyboardHandler *KeyboardHandler::InitKeyboardHandler()
{
  if (!KeyboardHandler::Handle)
  {
    KeyboardHandler::Handle = new KeyboardHandler();
    eventThread = SDL_CreateThread(KeyboardHandler::handleKeyboardEvent, NULL);
  }
  return KeyboardHandler::Handle;
}

void KeyboardHandler::DeinitKeyboardHandler()
{
	if (KeyboardHandler::Handle)
	{
		SDL_KillThread(eventThread);
		delete KeyboardHandler::Handle;
	}
}

bool KeyboardHandler::isPressed( Key keyCode)
{
  if( SDL_PRESSED == keyState[keyCode])
  {
      keyState[keyCode] = SDL_RELEASED;
      return true;
  }
  else
  {
        return false;
  }
}

bool KeyboardHandler::isReleased( Key keyCode)
{
  return ( SDL_RELEASED ==  keyState[keyCode] );
}


int KeyboardHandler::handleKeyboardEvent(void *data)
{
	SDL_Event Event;
	int flag = 1;
	while (flag)
	{
		while(SDL_PollEvent(&Event))
		{
			if ( (0 < Event.key.keysym.sym) && (400 > Event.key.keysym.sym) )
				keyState[Event.key.keysym.sym] = Event.key.state;
		}
	}
	return 0;
}
