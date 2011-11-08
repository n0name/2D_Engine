#include "input.h"

KeyboardHandler* KeyboardHandler::handle;
Uint8 KeyboardHandler::keyState[400];


KeyboardHandler::KeyboardHandler()
{
  //Epmty
}

KeyboardHandler *KeyboardHandler::InitKeyboardHandler()
{
  if (!KeyboardHandler::handle)
  {
    KeyboardHandler::handle = new KeyboardHandler();
  }
  return KeyboardHandler::handle;
}

void KeyboardHandler::DeinitKeyboardHandler()
{

}

bool KeyboardHandler::isPressed( Key keyCode)
{
  if( SDL_PRESSED == keyState[keyCode])
  {
      keyState[keyCode] = SDL_RELEASED;
      return true;
  }
  else
        return false;
}

bool KeyboardHandler::isReleased( Key keyCode)
{
  return ( SDL_RELEASED ==  keyState[keyCode] );
}

