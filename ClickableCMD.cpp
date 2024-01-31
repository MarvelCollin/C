#include <stdio.h>
#include <windows.h>

int main() {
    // Get a handle to the standard input, which is used for reading mouse input
    HANDLE inputMouse = GetStdHandle(STD_INPUT_HANDLE);

    // Variables to store the number of input records and an array to store input records
    DWORD num;
    INPUT_RECORD buffer[128];

    // Variable to store the previous console mode
    DWORD previousConsoleMode;

    // Variable to check if the left mouse button is clicked
    // you'll use this if faced with previous-menu (change menu)
    int buttonClicked = 0;

    // Loop until the left mouse button is clicked
    while (!buttonClicked) {
        // Get the current console mode and store it in previousConsoleMode
        GetConsoleMode(inputMouse, &previousConsoleMode);

        // Set the console mode to enable extended flags and mouse input
        SetConsoleMode(inputMouse, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

        // Reset the buttonClicked flag to 0
        buttonClicked = 0;

        // Read console input into the buffer, specifying a maximum of 128 records
        ReadConsoleInput(inputMouse, buffer, 128, &num);

        // Iterate through the input records
        for (DWORD i = 0; i < num; i++) {
            // Check if the input record is a mouse event with the left button pressed
            if (buffer[i].EventType == MOUSE_EVENT && buffer[i].Event.MouseEvent.dwEventFlags == 0 &&
                buffer[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                
                // Get the mouse position from the event
                COORD mousePos = buffer[i].Event.MouseEvent.dwMousePosition;

                // Restore the previous console mode
                SetConsoleMode(inputMouse, previousConsoleMode);

                // Print the message indicating that the left mouse button is clicked
                printf("Mouse left button clicked at X: %d, Y: %d\n", mousePos.X, mousePos.Y);

                // Set the buttonClicked flag to 1 to exit the loop
                buttonClicked = 1;
            }
        }
    }

    // Restore the previous console mode before exiting the program
    SetConsoleMode(inputMouse, previousConsoleMode);
}
