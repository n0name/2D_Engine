#ifndef INPUT_H
#define INPUT_H

#include <SDL/SDL.h>
#include "types.h"

typedef SDLKey Key;


class KeyboardHandler {
public:
//Public Methods
    static KeyboardHandler* InitKeyboardHandler();
    static void DeinitKeyboardHandler();

    static bool isPressed( Key keyCode);

    static bool isReleased( Key keyCode);
    static KeyboardHandler* GetHandle();

private:
// Private Methods
    static int handleKeyboardEvent(void * data);

// Private Variables
    KeyboardHandler();
    static KeyboardHandler* Handle;
    static Uint8 keyState[400];
    static ThreadData_t ThreadData;

};

#endif //INPUT_H
