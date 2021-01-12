#include <iostream>

using namespace std;

int main(){
    const int size = 5;
    int a[size] = {};
    int b[size] = {};
    

    for (int i=0; i < size; i++){
        int value;
        cout << "整数を入力してください>>> ";
        cin >> value;
        a[i] = value;
    }

    for (int i=size - 1; i >= 0; i--){
        b[i] = a[size - 1 - i];
        cout << i << endl;
    }

    for (int i=0; i < size; i++){
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    for (int i=0; i < size; i++){
        cout << "b[" << i << "] = " << b[i] << endl;
    }
    
}