#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[80];
    char id[8];
    float gpa;
};

void input(Student* student){
    printf("名前を入力>>> ");
    fscanf(stdin, "%79s", &student->name);
    fflush(stdout);

    printf("idを入力>>> ");
    fscanf(stdin, "%7s", &student->id);
    fflush(stdout);

    printf("gpaを入力>>> ");
    fscanf(stdin, "%f", &student->gpa);
    fflush(stdout);
}

void output(Student* student){
    printf("名前: %s, ID: %s, GPA: %f\n", student->name, student->id, student->gpa);
}


int main(){
    Student students[2];
    FILE *fp1 = fopen("data10", "w");

    for(int i = 0; i < 2; i++){
        input(&students[i]);
    }

    fwrite(students, sizeof(Student), 2, fp1);
    fclose(fp1);

    Student copyOfArray[2];
    FILE *fp2 = fopen("data10", "r");
    fread(copyOfArray, sizeof(Student), 2, fp2);
    fclose(fp2);
    
    for(int i = 0; i < 2; i++){
        output(&copyOfArray[i]);
    }
}