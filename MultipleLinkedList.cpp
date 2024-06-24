#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data {
	char city[30];
	int total;
	bool print;
	struct Data *atas, *bawah, *kanan, *kiri;
}*root;

struct Data *createData(char city[], int total){
	struct Data *newData = (Data*)malloc(sizeof(Data));
	
	*newData = {{0}, total, false, NULL, NULL, NULL, NULL};
	strcpy(newData->city, city);
	
	return newData;
}

void pushKanan(struct Data* root, char city[], int total){
	if(root->kanan){
		printf("sudah ada kota di kanan");
		return;	
	}
	
	Data *newData = createData(city, total);
	
	newData->kiri = root;
	root->kanan = newData;
}

void pushKiri(struct Data* root, char city[], int total){
	if(root->kiri){
		printf("sudah ada kota di kanan");
		return;	
	}
	
	Data *newData = createData(city, total);
	
	newData->kanan = root;
	root->kiri = newData;
}

void pushAtas(struct Data* root, char city[], int total){
	if(root->atas){
		printf("sudah ada kota di kanan");
		return;	
	}
	
	Data *newData = createData(city, total);
	
	newData->bawah = root;
	root->atas = newData;
}

void pushBawah(struct Data* root, char city[], int total){
	if(root->bawah){
		printf("sudah ada kota di kanan");
		return;	
	}
	
	Data *newData = createData(city, total);
	
	newData->atas = root;
	root->bawah = newData;
}

void joinKiriKanan(Data* cityKiri, Data* cityKanan){
	cityKiri->kanan = cityKanan;
	cityKanan->kiri = cityKiri;
}

void joinAtasBawah(Data* cityAtas, Data* cityBawah){
	cityAtas->bawah = cityBawah;
	cityBawah->atas = cityAtas;
}

void viewAll(struct Data* root, int level, int maxLevel){
	if(level == 0){
		printf("city : ");
	} else if(!root){
		printf("-\n");
		return;
	}
	
	printf("%s (%d jt)\n", root->city, root->total);
	if(root->print || level > maxLevel){
		return;
	}
	
	root->print = true;
	
	
	for(int i = 0; i <= level; i++) printf("   ");
	printf("atas: ");
	viewAll(root->atas, level + 1, maxLevel);

	for(int i = 0; i <= level; i++) printf("   ");
	printf("bawah: ");
	viewAll(root->bawah, level + 1, maxLevel);

	for(int i = 0; i <= level; i++) printf("   ");
	printf("kanan: ");
	viewAll(root->kanan, level + 1, maxLevel);

	for(int i = 0; i <= level; i++) printf("   ");
	printf("kiri: ");
	viewAll(root->kiri, level + 1, maxLevel);
}

void netral(Data *root){
	if(!root->print || !root){
		return;
	}
	
	root->print = false;
	netral(root->atas);
	netral(root->kanan);
	netral(root->kiri);
	netral(root->bawah);
}

int main(){
	root = createData("central city", 10);
	
	pushKiri(root, "kiri central", 12);
	pushKanan(root, "kanan central", 15);
	pushBawah(root, "bawah central", 12);
	pushAtas(root, "atas central", 11);
	
	pushKiri(root->atas, "kiri kiri central", 13);
	joinKiriKanan(root->atas->kiri, root->atas);
	
	viewAll(root, 0, 2);
	return 0;
}
