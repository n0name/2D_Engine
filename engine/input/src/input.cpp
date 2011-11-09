#include "input.h"


KeyboardHandler* KeyboardHandler::Handle;
Uint8 KeyboardHandler::keyState[400];
ThreadData_t KeyboardHandler::ThreadData;

KeyboardHandler::KeyboardHandler()
{
  //Empty
}

KeyboardHandler *KeyboardHandler::InitKeyboardHandler()
{
  if (!KeyboardHandler::Handle)
  {
    KeyboardHandler::Handle = new KeyboardHandler();
    KeyboardHandler::ThreadData.thread = SDL_CreateThread(KeyboardHandler::handleKeyboardEvent, &KeyboardHandler::ThreadData);
  }
  return KeyboardHandler::Handle;
}

void KeyboardHandler::DeinitKeyboardHandler()
{
	if (KeyboardHandler::Handle)
	{
		KeyboardHandler::ThreadData.flag = 0;
		SDL_WaitThread(KeyboardHandler::ThreadData.thread, NULL);
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
	ThreadData_t *private_data = (ThreadData_t *)data;


	while (private_data->flag)
	{
		while(SDL_PollEvent(&Event))
		{
			switch(Event.type)
			{
			case SDL_KEYUP:
			case SDL_KEYDOWN:
				if ( (0 < Event.key.keysym.sym) && (400 > Event.key.keysym.sym) )
					keyState[Event.key.keysym.sym] = Event.key.state;
				break;
			}

		}
	}
	return 0;
}

KeyboardHandler* KeyboardHandler::GetHandle()
{
	if (!Handle)
		return NULL;
	return Handle;
}
