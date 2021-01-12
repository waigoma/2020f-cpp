#include <iostream>

using namespace std;

int main(){
    int b[2][3][4] = {};

    cout << "b = " << b;
    cout << ", &b = " << &b << endl;

    for (int i = 0; i < 2; i++){
        cout << "b[" << i << "] = " << b[i];
        cout << ", &b[" << i << "] = " << &b[i] << endl;

        for (int j = 0; j < 3; j++){
            cout << "b[" << i << "][" << j << "] = " << b[i][j];
            cout << ", &b[" << i << "][" << j << "] = " << &b[i][j] << endl;

            for (int k = 0; k < 4; k++){
                cout << "b[" << i << "][" << j << "][" << k << "] = " << b[i][j][k];
                cout << ", &b[" << i << "][" << j << "][" << k << "] = " << &b[i][j][k] << endl;
            }
        }
    }
    
}