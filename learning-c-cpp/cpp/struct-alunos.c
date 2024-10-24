#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Menu {
    public:
        void static showMenu() {
            cout << "---------------------------- Menu ----------------------------" << endl;
            cout << "[ 1 ] --> Remove Students" << endl;
            cout << "[ 2 ] --> Show Students" << endl;
            cout << "[ 0 ] --> Exit" << endl;
            cout << "--------------------------------------------------------------" << endl;   
        }
};

typedef struct {
	float score;
	char name[40];
	} TAluno;

void awaitInput(void) {
    printf("\nPressione ENTER Para Continuar...");

    getchar();
    getchar();
}

#if defined(_WIN32) || defined(_WIN64)
    #define clear() system("cls")  // Para Windows
#else
    #define clear() system("clear") // Para Linux, macOS ou sistemas Unix
#endif

void insertStudents(TAluno *arrayStudents, TAluno alunoInfo, int i) {
    cout << "Enter " << i + 1 << "°" << "Student Name: " << endl;
    scanf("%39s", alunoInfo.name);
    strcpy(arrayStudents[i].name, alunoInfo.name);

    cout << "Enter " << i + 1 << "°" << "Student Score: " << endl;     
    scanf("%f", &alunoInfo.score);
    arrayStudents[i].score = alunoInfo.score;
}

void removeStudents(TAluno *arrayStudents, int numberStudentsToRemove, int &studentsNumber) {
    for (int i = numberStudentsToRemove - 1; i < studentsNumber - 1; i++) {
        arrayStudents[i] = arrayStudents[i + 1];
    }
    studentsNumber--;
}

void showStudents(TAluno *arrayStudantes, TAluno alunoInfo, int studentsNumber) {
    for (int i{}; i < studentsNumber; i++) {
        printf("Aluno %d:\n\n", i + 1);
        printf("Name: %s\n", arrayStudantes[i].name);
        printf("Score: %.1f", arrayStudantes[i].score);
        printf("\n\n");
    }
}

int main() {
    clear();
    int studentsNumber;
    TAluno alunoInfo;
    
    cout << "Enter Students Number: " << endl;
    scanf("%d", &studentsNumber);

    TAluno* arrayStudents = new TAluno[studentsNumber];

    for (int i{}; i < studentsNumber; i++) {
        insertStudents(arrayStudents, alunoInfo, i);
        clear();
    }

    int choice;

    while (true) {
        clear();
        Menu::showMenu();

        cout << "Enter your option: " << endl;
        cin >> choice;

        switch (choice) {   
            case 1: {
                int numberStudentToRemove;

                cout << "Enter Student Number To Remove [Ex: 1]: " << endl;
                scanf("%d", &numberStudentToRemove);

                removeStudents(arrayStudents, numberStudentToRemove, studentsNumber);
                break;
            }

            case 2: {
                clear();
                showStudents(arrayStudents, alunoInfo, studentsNumber);
                break;
            }

            case 0: {
                exit(0);
            }
        }
        awaitInput();
    }
}
