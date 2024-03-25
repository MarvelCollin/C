#include <stdio.h>
#include <conio.h> // support getch();

int main() {
	// input password *
    int len = 100, i = 0;
    char ch, password[len];

    while (1) {  
        ch = getch();

        if (ch == '\r' || ch == '\n') { // untuk ngecek enter 
            break;
        }
		// D -> kekiri
		// C -> kenanan
        password[i++] = ch;
        printf("\033[1D*\033[1C");  
    }

    password[i] = '\0';
    printf("\n");

    printf("Entered password: %s\n", password);
	
	// inputan email & password
//	char email[100];
//	char password[100];

	// \033[2A utk naik
	// \033[1D utk kekiri
	// \033[0C utk kekanan
	
//	printf("email    >\n");
//	printf("password >\n");
//	printf("\033[2A"); // naik 2
//	printf("\033[11C"); // kekanan 8
//	scanf("%s", email);
//	printf("\033[11C"); // kekanan 8
//	scanf("%s", password);
	
//	printf("%s %s", email, password);


	// baca keyboard
//	char c;
//	
//	c = getch(); // baca key yang kita tekan di keyboard tanpa enter
//	
//	if(c == 'a'){
//		printf("user menekan a");
//	} else {
//		printf("user tidak menekan a");
//	}
    return 0;
}
