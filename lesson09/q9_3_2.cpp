#include <iostream>

using namespace std;

void aryrmv(int a[], int n, int idx){

    for (int i = 0; i < n; i++){
        if(n - 1 == i){
            a[i] = a[i];
            continue;
        }

        if(i >= idx){
            a[i] = a[i + 1];
            continue;
        }
        
        a[i] = a[i];
    }
}

int main(){
    int list[] = {1, 3, 4, 7, 9, 11};
    int size = sizeof(list) / sizeof(list[0]);

    aryrmv(list, size, 2);

    cout << "aryrmvを呼び出した結果 = {";
    for (int i = 0; i < size; i++){
        if(size - 1 == i){
            cout << list[i];
            continue;
        }
        cout << list[i] << ", ";
    }
    cout << "}" << endl;
}