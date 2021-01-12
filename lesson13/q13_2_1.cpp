#include <stdio.h>
#include <stdlib.h>

int main(){
    float fList[3] = {0};

    printf("実数を入力>>> ");
    fscanf(stdin, "%f", &fList[0]);
    fflush(stdout);

    printf("実数を入力>>> ");
    fscanf(stdin, "%f", &fList[1]);
    fflush(stdout);

    printf("実数を入力>>> ");
    fscanf(stdin, "%f", &fList[2]);
    fflush(stdout);

    printf("input = %f, %f, %f\n", fList[0], fList[1], fList[2]);

    FILE *fp1 = fopen("data9", "w");
    fwrite(fList, sizeof(int), 3, fp1);
    fclose(fp1);
}