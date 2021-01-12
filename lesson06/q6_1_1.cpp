#include <iostream>

using namespace std;

int main(){
    double doubles[5] = {5.6, 4.7, 3.8, 2.9, 1.0};
    int i = 0;

    for(double d : doubles){
        cout << "d[" << i << "] = " << d << endl;
        i++;
    }
}