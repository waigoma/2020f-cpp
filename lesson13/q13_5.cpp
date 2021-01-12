#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// インドの天才数学者ラマヌジャンが発見した公式。
// まとめから引用
// http://w3e.kanazawa-it.ac.jp/e-scimath/contents/t16/textbook_t16_all.pdf

double calculatePi(int n){
    double count = 0;
    for (int i = 0; i < n; i++){
        count += (double)(1 / pow(16, i)) * ((4 / (8 * (double)i + 1)) - (2 / (8 * (double)i + 4)) - (1 / (8 * (double)i + 5)) - (1 / (8 * (double)i + 6)));
    }
    return count;
}

int main(){
    int n = 1000;
    double pi = calculatePi(n);
    printf("円周率(π) = %f\n", pi);
    printf("円周率(π) = %10.8f\n", pi);
    printf("円周率(π) = %16.14f\n", pi);
}