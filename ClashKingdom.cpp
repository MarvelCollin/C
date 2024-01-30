#include <windows.h>
#include <stdio.h>
#include <conio.h>

enum Menu {
    MAIN,
    MENU_2
};

void mainMenu(){
		printf("#######################################################################################################################\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                    ####################################                                             #\n");
		printf("#                                    #                                  #                                             #\n");
		printf("#                                    #               PLAY               #                                             #\n");
		printf("#                                    #                                  #                                             #\n");
		printf("#                                    ####################################                                             #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                    ############            ############                                             #\n");
		printf("#                                    # Guardian #            #          #                                             #\n");
		printf("#                                    #   List   #            # Tutorial #                                             #\n");
		printf("#                                    #          #            #          #                                             #\n");
		printf("#                                    ############            ############                                             #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                    ####################################                                             #\n");
		printf("#                                    #                                  #                                             #\n");
		printf("#                                    #               EXIT               #                                             #\n");
		printf("#                                    #                                  #                                             #\n");
		printf("#                                    ####################################                                             #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#                                                                                                                     #\n");
		printf("#######################################################################################################################\n");
		
		
}
	

int checkButtonClick(COORD mousePos, int xStart, int xEnd, int yStart, int yEnd) {
    if (mousePos.X >= xStart && mousePos.X <= xEnd && mousePos.Y >= yStart && mousePos.Y <= yEnd) {
        printf("X : %d Y : %d", mousePos.X, mousePos.Y);
        return 1; 
    }
    return 0; 
}

void clickChecker(enum Menu* currentMenu) {
    HANDLE inputMouse = GetStdHandle(STD_INPUT_HANDLE);

    DWORD num;
    INPUT_RECORD buffer[128];

    DWORD previousConsoleMode;

    GetConsoleMode(inputMouse, &previousConsoleMode);

    SetConsoleMode(inputMouse, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);

    while (1) {
        ReadConsoleInput(inputMouse, buffer, 128, &num);

		 if (num > 0 && buffer[0].EventType == MOUSE_EVENT && buffer[0].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
            // Get the coordinates of the mouse position
            COORD mousePos = buffer[0].Event.MouseEvent.dwMousePosition;

            // Print a message that the mouse left button is clicked along with its coordinates
            printf("Mouse left button clicked at X: %d, Y: %d\n", mousePos.X, mousePos.Y);
            return;

            // Add your additional code here based on the left mouse button click event
        }

//                	  checkButtonClick(mousePos, 10, 20, 5, 10);
//                    if (*currentMenu == MAIN) {
//                        if (checkButtonClick(mousePos, 10, 20, 5, 10, "Button area 1", *currentMenu)) {
//                            *currentMenu = MENU_2;
//                        } else if (checkButtonClick(mousePos, 30, 40, 5, 10, "Button area 2", *currentMenu)) {
//	
//                        }
//                    } else if (*currentMenu == MENU_2) {
//                        if (checkButtonClick(mousePos, 10, 20, 5, 10, "Button area 1", *currentMenu)) {
//
//                        } else if (checkButtonClick(mousePos, 30, 40, 5, 10, "Button area 2", *currentMenu)) {
//
//                        } else if (checkButtonClick(mousePos, 25, 35, 15, 20, "Button area 3", *currentMenu)) {
//
//                        }
//                    }
    }

    SetConsoleMode(inputMouse, previousConsoleMode);
}

int main() {
    enum Menu currentMenu = MAIN; 
    while(1){
    		system("cls");
			mainMenu();
    		clickChecker(&currentMenu);
    		Sleep(1000);
	}


}

