#include <stdio.h>
#include <string.h>

typedef struct s {
    char firstName[20];
    char lastName[20];
    short Id;
    char semester[3];
} Student;

int main(int argc, char **argv){
    char *dbName = "student.dat";
    Student myStudent;
    char *searchName = argv[1];

    FILE *data = fopen(dbName, "rb");

    while(1){
        fread(&myStudent, sizeof(Student), 1, data);
        if(feof(data)){
            break;
        }
        if(!strcmp(myStudent.firstName, searchName)){
            printf("Student info: \n");
            printf("Firstname: %s\n", myStudent.firstName);
            printf("Lastname: %s\n", myStudent.lastName);
            printf("Id: %i\n", myStudent.Id);
            printf("Semester: %s\n", myStudent.semester);
            break;
        }
    }
    fclose(data);
    return 0;
}