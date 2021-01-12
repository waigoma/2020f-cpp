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

    for (int i=10; i > 0; i--){
        for (int j=0; j < size; j++){
            if (ints[j] >= i) cout << " *";
            else cout << "  ";
        }
        cout << endl;
    }

    for (int i=0; i < size; i++){
        cout << "--";
    }

    cout << endl;

    for (int i=0; i < size; i++){
        cout << " " << i % 10;
    }
    
    
}