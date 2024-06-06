#include <stdio.h>
#include <windows.h> // utk bisa pake system("cls")
#include <stdbool.h> // supaya bisa pake boolean
#include <stdlib.h> // juga bisa untuk system("cls")
#include <string.h> // manipulation string

bool validEmail(char email[]);
void login();

void menu(){
	int choice = 0;
	
	// Recursion Menu
	
	printf("1. menu\n");
	printf("2. display\n");
	printf("3. insert\n");
	printf("4. exit\n");
	scanf("%d", &choice); getchar();
	system("cls"); // untuk clear cmd
	
	switch(choice){
		case 1: 
			login();
			break;
		case 2: 
			printf("display");
			break;
		case 3: 
			printf("insert");
			break;
		case 4:
			break;
		default:
			printf("Please choose between 1-4\n");
			menu();
			break;
	}

	// do while menu
	
//	do {
//		printf("1. menu\n");
//		printf("2. display\n");
//		printf("3. insert\n");
//		printf("4. exit\n");
//		scanf("%d", &choice); getchar();
//		system("cls"); // untuk clear cmd
//		
////		if(choice < 1 || choice > 4) print error
//	} while (choice < 1 || choice > 4);
//	
//		switch(choice){
//			case 1: 
//				printf("menu");
//				break;
//			case 2: 
//				printf("display");
//				break;
//			case 3: 
//				printf("insert");
//				break;
//			case 4:
//				break;
//			default:
//				printf("Please choose between 1-4\n");
//				break;
//		}
}

void login(){
	char email[100];
	
//	scanf("%[^#]", str); // ^ baca sampai, \n -> enter
//	printf("%s", str);
	
	scanf("%[^\n]", email);
	
	if(validEmail(email)){
		printf("Berhasil");
	} else {
		printf("Tidak berhasil");
	}
}

bool validEmail(char email[]){
	int len = strlen(email); // cek berapa size si string
	
	// cek apakah character pertama adalah angka
	if(!(email[0] >= '0' && email[0] <= '9')){
		return false;
	}
	
	// cek apakah 0
	if(len == 1 && email[0] == '0'){
		menu();
		return false;
	}
	
	// cek length 
	if(len < 1 || len > 8){
		return false;
	}	
	
	int hashtag = 0; // utk tau total symbol hashtag
	
	// cek alphanumeric & #
	for(int i = 0; i < len; i++){
		if(!(email[i] >= 'A' && email[i] <= 'Z') && !(email[i] >= 'a' && email[i] <= 'z') 
		&& !(email[i] >= '0' && email[i] <= '9') && email[i] != '#') { 
		// disini aku pakai negasi dimana negate kondisi
			
			printf("ada symbol selain #\n");
			return false;
		}
		
		if(email[i] == '#'){
			hashtag++;
		}
	}
	
	// cek #
	if(hashtag > 1){
		return false;
	}
	
	// diakhir -242
	
//	char last[] = "-242";
//	int j = 0;
//	for(int i = 3; i >= 0; i--){
//		if(email[len - 1 - j] != last[i]){
//			return false;
//		}
//		j++;
//		
//		printf("%c %c\n", email[len - j] , last[i]);
//	}
	
	// cek apakah diakhiri -242
	if(strcmp(email + len - 4, "-242") != 0){
		return false;
	}
	
	return true;
}

int main(){
	menu();



	// kalau ternyata string kita kosong
	
//	char str[100];
//	
//	scanf("%[^\n]", str); 
//	str[0] = '\0';
//	
//	printf("%s",str);
//	
//	if(strlen(str) == 0){
//		printf("null");
//	}
	
	return 0;
}
