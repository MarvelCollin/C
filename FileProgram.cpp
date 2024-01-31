#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 3000

//Buatlah file dengan nama student.txt didalam 1 folder yang sama.
//copy text dibawah dan pastekan kedalam file txtnya

//John-22-3.90
//Jane-23-3.85
//Bob-24-3.80
//Alice-25-3.95
//Charlie-21-3.70
//David-22-3.60
//Emma-23-3.75
//Frank-20-3.80
//Grace-24-3.90
//Henry-22-3.85
//Ivy-23-3.95
//Jack-21-3.70
//Katie-22-3.60
//Leo-23-3.75
//Mia-20-3.80
//Noah-24-3.90
//Olivia-22-3.85
//Peter-23-3.95
//Quinn-21-3.70
//Rachel-22-3.60
//Sam-23-3.75
//Tina-20-3.80
//Ulysses-24-3.90
//Vera-22-3.85
//Will-23-3.95
//Xander-21-3.70
//Yara-22-3.60
//Zane-23-3.75
//Adam-20-3.80


struct Student {
    char name[MAX_LENGTH];
    int age;
    float GPA;
};

// function untuk print students
void printStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %.2f\n\n", student->GPA);
}

// function untuk write (override) banyak student
void writeStudentsToFile(FILE *file, const char *mode) {
    struct Student student;
    int numStudents;

    printf("Enter the number of students to insert: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; ++i) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter student name: ");
        scanf("%s", student.name);

        printf("Enter student age: ");
        scanf("%d", &student.age);

        printf("Enter student GPA: ");
        scanf("%f", &student.GPA);

		// write data yang sudah diinput ke dalam file
        fprintf(file, "%s-%d-%.2f\n", student.name, student.age, student.GPA);
    }
}

int main() {
    FILE *file;
    char filename[] = "student.txt"; // nama file
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. View student data\n");
        printf("2. Write (overwrite) student data\n");
        printf("3. Append student data\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // View student data
                file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error opening file: %s\n", filename);
                    return 1; // Return with an error code
                }

                printf("\nViewing student data:\n");
                struct Student student;
				
		// read per line    
                while (fscanf(file, "%[^-]-%d-%f\n", student.name, &student.age, &student.GPA) == 3) {
                    printStudent(&student);
                }

                fclose(file);
                break;

            case 2: // Write (override) student data
                file = fopen(filename, "w");
                
                if (file == NULL) {
                    printf("Error opening file: %s\n", filename);
                    return 1; 
                }

                printf("\nWriting (overwriting) student data:\n");
                writeStudentsToFile(file, "w");

                fclose(file);
                break;

            case 3: // Append student data
                file = fopen(filename, "a");
                if (file == NULL) {
                    printf("Error opening file: %s\n", filename);
                    return 1; 
                }

                printf("\nAppending student data:\n");
                writeStudentsToFile(file, "a");

                fclose(file);
                break;

            case 0: // Exit
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0; 
}
