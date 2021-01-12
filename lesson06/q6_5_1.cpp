#include <iostream>

using namespace std;

int main(){
    int a[3][2] = {};

    cout << "a = " << a;
    cout << ", &a = " << &a << endl;

    for (int i = 0; i < 3; i++){
        cout << "a[" << i << "] = " << a[i];
        cout << ", &a[" << i << "] = " << &a[i] << endl;

        for (int j = 0; j < 2; j++){
            cout << "a[" << i << "][" << j << "] = " << a[i][j];
            cout << ", &a[" << i << "][" << j << "] = " << &a[i][j] << endl;
        }
    }
    
}