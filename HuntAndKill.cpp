#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize(int **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze(int **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                printf("# "); // Obstacle
            } else {
                printf(". "); // Jalan
            }
        }
        printf("\n");
    }
}

int hasUnvisitedNeighbors(int **maze, int x, int y, int width, int height) {
    if (x > 1 && maze[x-2][y] == 1) return 1;
    if (y > 1 && maze[x][y-2] == 1) return 1;
    if (x < height-2 && maze[x+2][y] == 1) return 1;
    if (y < width-2 && maze[x][y+2] == 1) return 1;
    return 0;
}

void huntAndKill(int **maze, int width, int height) {
    int x = 1, y = 1;

    maze[x][y] = 0;

    while (1) {
        while (hasUnvisitedNeighbors(maze, x, y, width, height)) {
            int dir = rand() % 4;
            
            switch (dir) {
                case 0: 
                    if (x > 1 && maze[x-2][y] == 1) {
                        maze[x-1][y] = 0;
                        maze[x-2][y] = 0;
                        x -= 2;
                    }
                    break;
                case 1: // Down
                    if (x < height-2 && maze[x+2][y] == 1) {
                        maze[x+1][y] = 0;
                        maze[x+2][y] = 0;
                        x += 2;
                    }
                    break;
                case 2: // Left
                    if (y > 1 && maze[x][y-2] == 1) {
                        maze[x][y-1] = 0;
                        maze[x][y-2] = 0;
                        y -= 2;
                    }
                    break;
                case 3: // Right
                    if (y < width-2 && maze[x][y+2] == 1) {
                        maze[x][y+1] = 0;
                        maze[x][y+2] = 0;
                        y += 2;
                    }
                    break;
            }
        }

        int found = 0;
        for (int i = 1; i < height && !found; i += 2) {
            for (int j = 1; j < width && !found; j += 2) {
                if (maze[i][j] == 1 && hasUnvisitedNeighbors(maze, i, j, width, height)) {
                    x = i;
                    y = j;
                    maze[x][y] = 0;
                    found = 1;
                }
            }
        }

        if (!found) break;
    }
}

int main() {
    int width = 60, height = 20;

    // Allocate memory for the maze
    int **maze = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        maze[i] = (int *)malloc(width * sizeof(int));
    }

    srand(time(NULL));

    initialize(maze, width, height);

    huntAndKill(maze, width, height);

    printMaze(maze, width, height);

    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
