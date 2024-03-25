#include <stdio.h>

#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

int main(){
	printf(GREEN "ASDSA\n" RESET); 
	printf("%sASDAS%s\n", GREEN, RESET);
	printf("\x1b[32mASDSA\x1b[0m\n");
	return 0;
}
