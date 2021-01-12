#include <stdio.h>
#include <stdlib.h>


double calculatePi(int n){
    double count = 0;
    int val = 1;
    for (int i = 0; i < n; i++){
        count += (double)val / (2 * i + 1);
        val *= -1;
    }
    return count;
}

int main(){
    int n = 1000;
    double pi = calculatePi(n);
    printf("円周率(π/4) = %f\n", pi);
    printf("円周率(π/4) = %10.8f\n", pi);
    printf("円周率(π/4) = %16.14f\n", pi);
}