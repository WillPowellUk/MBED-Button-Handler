#include "mbed.h"
#include "ButtonHandler.hpp"
#include "ButtonState.h"

// main() runs in its own thread in the OS
int main()
{
    ButtonHandler button(PC_13, true);

    // start button handler thread
    button.init();

    while (true)
    {
        Button::state state = button.checkNewPresses();

        switch(state) 
        {
            case Button::state::Short_Press:
                printf("Short Press!\n");
                break;
            case Button::state::Long_Press:
                printf("Long Press!\n");
            default:
                break;
        }

        ThisThread::sleep_for(500ms);
    } 
    
}

