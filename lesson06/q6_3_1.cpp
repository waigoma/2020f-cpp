#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    int ints[15] = {};
    int size = sizeof(ints) / sizeof(ints[0]);

    srand(time(NULL));

    for (int i=0; i < size; i++){
        int value = rand() % 11;
        ints[i] = value;
    }

    for (int i=0; i < size; i++){
        if(i < 10) cout << "ints[ " << i << "] : ";
        else cout << "ints[" << i << "] : ";
        for (int j=0; j < ints[i]; j++){
            cout << "*";
        }
        cout << endl;
    }
    
    
}