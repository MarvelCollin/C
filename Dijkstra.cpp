#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
 
struct Position {
	int x,y;
};

struct Map {
	Position currPos;
	char value;
	bool isVisited;
	Map *before;
};

Map sMap[10][15];

char MapMaze[10][16] = {
	"###############",
	"#E###         #",
	"#   #         #",
	"###      ######",
	"##        #####",
	"#    ##########",
	"###           #",
	"#######   #####",
	"#            S#",
	"###############",
};

Position startPos, endPos;

void buildMap(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 15; j++){
			char currChar = MapMaze[i][j];
			// declare currPos untuk bantu set startPos & ebdOis
			Position currPos;
			currPos.x = j;
			currPos.y = i;
			
			if(currChar == 'S'){
				startPos = currPos;
			}
			
			if(currChar == 'E'){
				endPos = currPos;
			}
			
			// inisialisasi
			sMap[i][j].currPos = currPos;
			sMap[i][j].before = NULL;
			sMap[i][j].isVisited = false;
			sMap[i][j].value = currChar;
		}
	}
}

void printMap(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 15; j++){
			printf("%c", sMap[i][j].value);
		}
		printf("\n");
	}
}

// gerakan atas kanan bawah kiri
int moveY[4] = {-1,0,1,0};
int moveX[4] = {0,1,0,-1};

void solve(){
	// simpan map bagian mana yang mau dicek
	vector<Map*> listMap;
	// push_back itu seperti push tail, ini lagi push startPos
	listMap.push_back(&sMap[startPos.y][startPos.x]);
	Map *currMap;
	
	while(!listMap.empty()){
		// ambil listMap yang pertama
		currMap = listMap[0];
		
		// lalu hapus
		// erase -> hapus, begin yang pertama (index 0)
		listMap.erase(listMap.begin());
		
		// lalu set visited ke true
		currMap->isVisited = true;
		
		// check apakah sudah smpe target
		if(currMap->value == 'E') break;
		
		
		for(int i = 0; i < 4; i++){
			// coba cek sesuai pola
			Map *newMap = &sMap[currMap->currPos.y + moveY[i]][currMap->currPos.x + moveX[i]];
			
			
			// check apakah udah di list apa belum
			bool alreadyInList = false;
			
			for(int j = 0; j < listMap.size(); j++){
				if(listMap[j] == newMap){
					alreadyInList = true;
					break;
				}
			}
			
			// kalau misalkan tidak memenuhi brrti continue ke next loop
			if(newMap->isVisited || newMap->value == '#' || alreadyInList){
				continue;
			}
			
			
			// kalau misalkan memenuhi
			listMap.push_back(newMap);
			// kasi tracebacknya
			newMap->before = currMap;
		}
	}
	
	while(currMap){
		if(currMap->value != 'S' && currMap->value != 'E') currMap->value = '*';
		// gunakan tracebacknya 
		currMap = currMap->before;
	}
	
	printMap();
}

int main(){
	buildMap();
	solve();
		
	return 0;
}
