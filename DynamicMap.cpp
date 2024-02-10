#include <stdio.h>

#define ROWS 30
#define COLS 130

int calculateHeight(char layout[ROWS][COLS + 1]) {
    int height = 0;
    while (layout[height][0] != '\0') {
        height++;
    }
    return height;
}

int calculateWidth(char layout[ROWS][COLS + 1]) {
    int width = 0;
    for (int i = 0; layout[0][i] != '\0'; i++) {
        width++;
    }
    return width;
}

int main() {
    char layout[ROWS][COLS + 1] = {
    	"#####################################################",
		"#                                                   #",
		"#       #                                           #",
		"#       #                                           #",
		"#       #                                           #",
		"#       #                                           #",
		"#       #                                           #",
		"#                                         #         #",
		"#                                         #         #",
		"#                                         #         @",
		"#                       #                 #         #",
		"#                       #                 #         #",
		"#                      #                            #",
		"#                      #                            #",
		"#                      #                            #",
		"#                      #                            #",
		"#                                                   #",
		"#                                                   #",
		"#                                                   #",
		"#                                                   #",
		"#                                                   #",
		"#####################################################",
    };


    int height = calculateHeight(layout);
    int width = calculateWidth(layout);

    // print
    for (int i = 0; i < height; i++) {
        printf("%s\n", layout[i]);
    }
    
    printf("Height of the map: %d\n", height);
    printf("Width of the map: %d\n", width);
	
	while(1){
		
	}
    return 0;
}
