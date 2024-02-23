#include<stdio.h>
#include<stdlib.h> // untuk urus srand
#include<time.h> // untunk urus time(NULL) dan rand()

int generateRandom(){
	int limit = 5; // max value yang dirandom
	return rand() % limit + 1; // + 1 itu supaya value akhirnya tidak 0, jadi minimalnya 1
	
	// tapi kalau misalkan kita mau minimalnya bukan 1
	// return min + rand() % (max - min + 1); ini rumusnya
}

int main(){
	// srand gunanya untuk 'mereset' rand kita 
	// berdasarkan waktu yang sedang berjalan, jadi 
	// setiap kali kita menjalankan program, maka randomnya akan
	// benar benar random
	srand(time(NULL));
	
	// coba srandnya dicomment, lalu jalankan
	// maka value hasil dari rand() nya akan selalu sama
	
	printf("%d", generateRandom());
}
