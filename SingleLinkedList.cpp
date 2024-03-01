#include<stdio.h>
#include<stdlib.h>

struct Mahasiswa{
	int umur;
	struct Mahasiswa *next;
}*head = NULL, *tail = NULL;

//struct Mahasiswa *head = NULL;
//struct Mahasiswa *tail = NULL;

struct Mahasiswa *buatMahasiswa(int umur){
	// buat buletan
	struct Mahasiswa *mahasiswaBaru = (struct Mahasiswa*)malloc(sizeof(Mahasiswa));
	
	//strcpy(mahasiswaBaru->str, str);
	mahasiswaBaru->umur = umur;
	mahasiswaBaru->next = NULL;
}

void pushHead(int umur){
	struct Mahasiswa *mahasiswaBaru = buatMahasiswa(umur);
	
	// pertama kali insert
	if(head == NULL || tail == NULL){ // !head , head = NULL
		head = tail = mahasiswaBaru;
	} else {
		mahasiswaBaru->next = head;
		head = mahasiswaBaru;
	}
}

void pushTail(int umur){
	struct Mahasiswa *mahasiswaBaru = buatMahasiswa(umur);
	
	if(head == NULL || tail == NULL){ // !head , head = NULL
		head = tail = mahasiswaBaru;
	} else {
		tail->next = mahasiswaBaru;
		tail = mahasiswaBaru;
	}
}

void pushMid(int umur){
	struct Mahasiswa *mahasiswaBaru = buatMahasiswa(umur);
	
	if(head == NULL || tail == NULL){ // !head , head = NULL
		head = tail = mahasiswaBaru;
	} else if(umur < head->umur){
		pushHead(umur);
	} else if(umur > tail->umur){
		pushTail(umur);
	} else {
		struct Mahasiswa *mahasiswaSekarang = head;
		
		while(mahasiswaSekarang->next != NULL && umur > mahasiswaSekarang->next->umur){
			mahasiswaSekarang = mahasiswaSekarang->next;
		}
		
		mahasiswaBaru->next = mahasiswaSekarang->next;
		mahasiswaSekarang->next = mahasiswaBaru;
	}
	
}

void printAll(){
	struct Mahasiswa *mahasiswaSekarang = head;
	
	while(mahasiswaSekarang != NULL){
		printf("%d -> ", mahasiswaSekarang->umur);
		
		// mahasiswa = mahasiswa selanjutnya
		mahasiswaSekarang = mahasiswaSekarang->next;
	}
	printf("\n");
}

int main(){
//	pushHead(10);
//	pushHead(3);
//	pushHead(5);
//	printAll();
//
//	pushTail(3);
//	pushTail(5);
//	pushTail(7);

	pushMid(10);
	pushMid(3);
	pushMid(15);
	pushMid(7);
	pushMid(2);
	printAll();
	
	
	return 0;
}
