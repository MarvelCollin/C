#include <windows.h>
#include <stdio.h>

int main() {
    // Get the handle for mouse input
    HANDLE inputMouse = GetStdHandle(STD_INPUT_HANDLE);

    // Variables to store the number of events and an array to store input records (including mouse events)
    DWORD num;
    INPUT_RECORD buffer[128]; // Buffer to store input records, where each record can be a mouse event, keyboard event, etc.

    // Variable to store the console mode before modification
    DWORD previousConsoleMode;

    // Get the current console mode
    GetConsoleMode(inputMouse, &previousConsoleMode);

    // Enable extended flags and mouse input in the console mode
    // ENABLE_EXTENDED_FLAGS: Enables extended flags for input, allowing additional input modes
    // ENABLE_MOUSE_INPUT: Enables mouse input in the console
    SetConsoleMode(inputMouse, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    while (1) {
        // Read input from the mouse into the buffer
        ReadConsoleInput(inputMouse, buffer, 128, &num);

        // Iterate through each event in the b-uffer
        for (DWORD i = 0; i < num; i++) {
            // Check if the event is a mouse event
            if (buffer[i].EventType == MOUSE_EVENT) {
                // Check if the left button is pressed
                if (buffer[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                    // Get the coordinates of the mouse position
                    COORD mousePos = buffer[i].Event.MouseEvent.dwMousePosition;

                    // Print a message that the mouse left button is clicked along with its coordinates
                    printf("Mouse left button clicked at X: %d, Y: %d\n", mousePos.X, mousePos.Y);

                    // Add your additional code here based on the left mouse button click event
                }
            }
        }
    }

    // Restore the console mode to the previous state
    SetConsoleMode(inputMouse, previousConsoleMode);

    return 0;
}
