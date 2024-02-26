#include<stdio.h>
#include<windows.h>
#include<conio.h>


#define xMap 200
#define yMap 200

int xPlayer = 10, yPlayer = 10;
int xEnemies[] = {20, 14}, yEnemies[] = {5, 16};

char map[yMap][xMap + 1] = {
	"########################################",
	"#                                      #",
	"#   #####                       #####  #",
	"#                                      #",
	"#  #                                 # #",
	"#  #                                 # #",
	"#  #           ##########            # #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#  #                                 # #",
	"#  #                                 # #",
	"#  #           ##########            # #",
	"#                                      #",
	"#   #####                       #####  #",
	"#                                      #",
	"########################################",
};

void isInRange(int x, int y){
	int radius = 4;
	
	int xRadius = xPlayer - x;
	int yRadius = yPlayer - y;
	
	xRadius < 0 ? xRadius *= -1 : xRadius;
	yRadius < 0 ? yRadius *= -1 : yRadius;
	
	if(xRadius < radius && yRadius < radius){
		printf("is in range !!!\n");
	}
}

void move(){
	map[yPlayer][xPlayer] = ' ';
	
	switch(getch()){
		case 'w':
			yPlayer--;
			break;
		case 's':
			yPlayer++;
			break;
		case 'a':
			xPlayer--;
			break;
		case 'd':
			xPlayer++;
			break;
		default:
			move();
			break;
	}
}

int calculateSize(){
	int size = 0;

	while(map[size][0] != '\0'){
		size++;
	}
	
	return size;
}


void print(){
	map[yPlayer][xPlayer] = 'O';
	map[yEnemies[0]][xEnemies[0]] = '1';
	map[yEnemies[1]][xEnemies[1]] = '2';
	
	system("cls");
	
	int size = calculateSize();
	for(int i = 0; i < size; i++){
		printf("%s\n", map[i]);
	}
	
	isInRange(xEnemies[0], yEnemies[0]);
	isInRange(xEnemies[1], yEnemies[1]);
	
	move();
}

int main(){
	while(1){
		print();
	}
}
