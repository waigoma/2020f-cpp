#include <stdio.h>
#include <string.h>

int strlen2(char* str){
    int count = 0;
    int i = 0;
    while(str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

void strncpy2(char* str1, char* str2, size_t n){
    for(int i = 0; i < n; i++){
        str1[i] = str2[i];
    }
}

void strncat2(char* s1, char* s2, size_t n){
    int i = 0;
    int k = 0;
    while(s1[i] != '\0') {
        i++;
    }
    for(int j = i; j < n; j++){
        s1[j] = s2[k];
        k++;
    }
}

int strncmp2(char* s1, char* s2, size_t n){
    for(int i = 0; i < n; i++){
        if (s1[i] == s2[i]) continue;
        return s1[i] > s2[i] ? 1 : -1;
    }
    return 0;
}

int main(){
    char name1[80] = "Hosei";
    char name2[80];
    char name3[80] = "University";

    fprintf(stdout, "strlen2(%s) = %ld\n", name1, strlen2(name1));
    strncpy2(name2, name1, 80);
    fprintf(stdout, "strlen2(%s) = %ld\n", name2, strlen2(name2));

    fprintf(stdout, "strncmp2(%s, %s, 80) = %d\n", name1, name2, strncmp2(name1, name2, 80));
    name2[4] = 'h';
    fprintf(stdout, "strncmp2(%s, %s, 80) = %d\n", name1, name2, strncmp2(name1, name2, 80));
    name2[4] = 'j';
    fprintf(stdout, "strncmp2(%s, %s, 80) = %d\n", name1, name2, strncmp2(name1, name2, 80));

    strncat2(name1, name3, 80 - strlen(name1) - 1);
    fprintf(stdout, "strlen(%s) = %ld\n", name1, strlen(name1));
}