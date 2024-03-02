#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

int xPlayer = 5, yPlayer = 5;
int xEnemy[3], yEnemy[3];

int totalFood = 0;
int xFood[2], yFood[2];

int score = 0;

int height = 20, width = 30;

bool game = true;

char map[20][30] = {
	"#############################",
	"#                           #",
	"#                           #",
	"#          ###########      #",
	"#                           #",
	"#                           #",
	"#                   #########",
	"#                           #",
	"###############             #",
	"#                           #",
	"#       ######              #",
	"#                           #",
	"#             #######       #",
	"#                           #",
	"#                ############",
	"#                           #",
	"################            #",
	"#                           #",
	"#                           #",
	"#############################",
};

void randomEnemy(){
	for(int i = 0; i < 3; i++){
		xEnemy[i] = rand() % height + 1;
		yEnemy[i] = rand() % width + 1;
		
		if(map[yEnemy[i]][xEnemy[i]] == '#'){
			i--;
		}
	}
}

bool enemyChecker(int i, int j){
	for(int x = 0; x < 3; x++){
		if(i == yEnemy[x] && j == xEnemy[x]){
			return true;
		}
	}
	
	return false;
}

void randomFood(int i){
	xFood[i] = rand() % height + 1;
	yFood[i] = rand() % width + 1;
			
	if(map[yFood[i]][xFood[i]] != '#') {
		randomFood(i);
	} 
}

void eatFood(){
	for(int i = 0; i < 2; i++){
		if(yPlayer == xFood[i] && xPlayer == yFood[i]){
		
			randomFood(i);
			score = score + 100;
		}
	}
}

void dead(){
	for(int i = 0; i < 3; i++){
		if(yPlayer == yEnemy[i] && xPlayer == xEnemy[i]){
			game = false;
			printf("Game Ended \n");
			Sleep(2000);
			getch();
		}
	}
}

void moveEnemy(){
	for(int i = 0; i < 3; i++){
		int randomMove = rand() % 4;
		
		int oldX = xEnemy[i];
		int oldY = yEnemy[i];
		
		switch(randomMove){
			case 0:
				xEnemy[i]--;
				break;
			case 1:
				xEnemy[i]++;
				break;
			case 2:
				yEnemy[i]--;
				break;
			case 3:
				yEnemy[i]++;
				break;
		}
		
		if(map[yEnemy[i]][xEnemy[i]] == '#') {
			xEnemy[i] = oldX;
			yEnemy[i] = oldY;
			i--;
		} else {
			map[oldY][oldX] = ' ';
		}
	}
	
//	Sleep(100);
}

bool isFenced(int yPos, int xPos){
	if(map[yPos][xPos] == '#'){
		return true;
	}
	
	return false;
}

void movePlayer(){
	int c = getch();
	
	map[yPlayer][xPlayer] = ' ';
	
	switch(c){
		case 'a':
			!isFenced(yPlayer, xPlayer - 1) ? xPlayer-- : xPlayer;
			break;
		case 'd':
			!isFenced(yPlayer, xPlayer + 1) ? xPlayer++ : xPlayer;
			break;
		case 'w':
			!isFenced(yPlayer - 1, xPlayer) ? yPlayer-- : yPlayer;
			break;
		case 's':
			!isFenced(yPlayer + 1, xPlayer) ? yPlayer++ : xPlayer;
			break;
	}
	
}

bool foodChecker(int i, int j){
	for(int x = 0; x < 2; x++){
		if(xFood[x] == i && yFood[x] == j){
			return true;
		}
	}
	
	return false;
}

void printMap(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == yPlayer && j == xPlayer){
                map[i][j] = 'O';
            } else if(enemyChecker(i , j)) {
                map[i][j] = 'X';            
            } else if(foodChecker(i, j)){
            	map[i][j] = 'F';
			}
        }
    }
    
    system("cls");
    for(int i = 0; i < height; i++){
    	printf("%s\n", map[i]); 
	}
	
	printf("Score > %d\n", score);
}

int main(){	
	srand(time(NULL));
	randomEnemy();
	
	xFood[0] = rand() % height + 1;
	yFood[0] = rand() % width + 1;
	xFood[1] = rand() % height + 1;
	yFood[1] = rand() % width + 1;
	
	while(game){
		printMap();
		movePlayer();
		eatFood();
		moveEnemy();
		dead();
	}
		
	return 0;
}
