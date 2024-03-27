#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

int posPlayer = 10;
int xTarget, yTarget;
int init = 0, shooting = 0, lastLayer = 6, bullets = 7, spawnLayer, score = 0;

void draw();
void findLastLayer();

void clr(){
	system("cls");
}

char map[20][21] = { 
	"####################",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"#                  #",
	"####################",
};

char random(){
	char str[] = "12345";
	
	return str[rand() % 5]; 
}

void blowUp(int startY, int startX){
	for (int i = -1; i <= 2; i++) {
	    for (int j = -2; j <= 2; j++) {
	        if (map[startY + i][startX + j] == '5') {
	            map[startY + i][startX + j] = '4';
	            score += 3;
	        } else if (map[startY + i][startX + j] == '4') {
	            map[startY + i][startX + j] = '3';
	            score += 3;
	        } else if (map[startY + i][startX + j] == '3') {
	            map[startY + i][startX + j] = '2';
	            score += 3;
	        } else if (map[startY + i][startX + j] == '2') {
	            score += 3;
	            map[startY + i][startX + j] = '1';
	        } else if (map[startY + i][startX + j] == '1') {
	            map[startY + i][startX + j] = ' ';
	            score += 10;
	        } else {
	        	
			}
	    }
	}

}

void checkSpawnLayer(){
	spawnLayer = 0;
	bool isNum = false;
	
	for(int i = 1; i < 17; i++){
		for(int j = 1; j < 19; j++){
			if(map[i][j] != '.' || map[i][j] != '^' || map[i][j] != ' '){
				isNum = true;
			} 
		}
		if(isNum) spawnLayer++;
	}
}

void shoots(){
	shooting = 1;
	
	findLastLayer();
	
	for(int i = 17; i > lastLayer; i--){
		map[i][posPlayer] = 'A';		
//		Sleep(2);
		map[i + 1][posPlayer] = '.';
		draw();
	}
	
	shooting = 0;
	bullets--;
	// hapus 
	for(int i = 18; i > lastLayer; i--){
		map[i][posPlayer] = ' ';		
	}
	
	xTarget = posPlayer;
	yTarget = lastLayer;
	
	blowUp(yTarget, xTarget);
}

void move(){
	int c = getch();
	
	switch(c){
		case 'a':
			posPlayer--;
			break;
		case 'A':
			posPlayer--;
			break;
		case 'd':
			posPlayer++;
			break;
		case 'D':
			posPlayer++;
			break;
		case ' ':
			shoots();
			break;
		default:
			move();
			break;
	}
	
	findLastLayer();
	if(posPlayer == 0) posPlayer++;
	if(posPlayer == 19) posPlayer--;
}

void findLastLayer(){
	lastLayer = 14;
	while(map[lastLayer][posPlayer] == ' ' || map[lastLayer][posPlayer] == '.'
	|| map[lastLayer][posPlayer] == 'A'){
		lastLayer--;
	}
}

void addLayer(){
	for(int i = lastLayer; i > 0; i--){
		for(int j = 1; j < 19; j++){
			if(i != 1){
				map[i + 1][j] = map[i][j];
			} else {
				map[i][j] = random();
			}
		}
	}
	
	lastLayer++;
}

void draw(){
	clr();
	
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(j == posPlayer && i == 18) {
				printf("A");
			} else if(i > 0 && i < 7 && j > 0 && j < 19 && init == 0){
				map[i][j] = random();
				printf("%c", random());
			} else if(j == posPlayer && i == 17){
				printf("^");
			} else if(j == posPlayer && i > lastLayer && i < 17 && shooting == 0){
				shooting == 0 ? printf(".") : printf("%c", map[i][j]);
			} else {
				printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
	
	
	
	findLastLayer();
	checkSpawnLayer();
	printf("\n\nCURRENT TARGET -> %c\n", map[lastLayer][posPlayer]);
	printf("bullets before add layer ->%d\n", bullets);
	printf("target layer -> %d\n", lastLayer);
	printf("last layer -> %d\n", spawnLayer); // maaav karna bad variable name WKKW
	printf("SCORE -> %d", score);
	
	if(bullets == 0){
		addLayer();
		bullets = 7;
	}
	init = 1;
}

void play(){
	draw();
	
	map[19][posPlayer] == ' ';
	move();
	play();
}

void menu(){
	int choice;
	
	do {
		clr();
		printf("1. Play Game\n");
		printf("2. How to play\n");
		printf("3. Exit\n");	
		printf("Choose > ");
		scanf("%d", &choice);
	} while(choice < 0 || choice > 3);
	
	switch(choice){
		case 1:
			score = 0;
			play();
			break;
		case 2:
			break;
		case 3:
			break;
	}
}

int main(){
	init = 0;
	menu();
	return 0;
}
