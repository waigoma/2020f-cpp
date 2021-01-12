#include <stdio.h>
#include <stdlib.h>

int main(){
    float fList[3] = {0};
    FILE *fp1 = fopen("data9", "r");

    fread(fList, sizeof(int), 3, fp1);
    fclose(fp1);

    float *ip = fList;

    for(int i = 0; i < 3; i++){
        fprintf(stdout, "%f ", *ip++);
    }
}