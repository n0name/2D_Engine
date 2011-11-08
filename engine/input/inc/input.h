#ifndef INPUT_H
#define INPUT_H

#include <SDL/SDL.h>
typedef SDLKey Key;

class KeyboardHandler {
public:
//Public Methods
    static KeyboardHandler* InitKeyboardHandler();
    static void DeinitKeyboardHandler();
    
    static bool isPressed( Key keyCode);

    static bool isReleased( Key keyCode);

private:
// Private Methods
    void handleKeyboardEvent(SDL_Event Event) {
              if ( 0 < Event.key.keysym.sym && 400 > Event.key.keysym.sym)
                  keyState[Event.key.keysym.sym] = Event.key.state;
    }
// Private Variables
    KeyboardHandler();
    static KeyboardHandler* handle;
    static Uint8 keyState[400];
};




#endif //INPUT_H