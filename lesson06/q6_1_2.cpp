#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    int ints[6] = {};
    int size = sizeof(ints) / sizeof(ints[0]);

    srand(time(NULL));

    for (int i=0; i < size; i++){
        int value = rand() % 10 + 1;
        ints[i] = value;
    }

    for (int i=0; i < size; i++){
        cout << "ints[" << i << "] = " << ints[i] << endl;
    }
    
    
}