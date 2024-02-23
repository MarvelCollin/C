#include<stdio.h>

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

void initialize(){
	map[yPlayer][xPlayer] = 'O';
	map[yEnemies[0]][xEnemies[0]] = '1';
	map[yEnemies[1]][xEnemies[1]] = '2';
}

int calculateSize(){
	int size = 0;
	initialize();
	while(map[size][0] != '\0'){
		size++;
	}
	
	return size;
}


void print(){
	int size = calculateSize();
	for(int i = 0; i < size; i++){
		printf("%s\n", map[i]);
	}
}

int main(){
	print();
}
