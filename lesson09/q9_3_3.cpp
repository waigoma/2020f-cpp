#include <iostream>

using namespace std;

void aryins(int a[], int n, int idx, int x){
    int cp[n] = {};

    for(int i = 0; i < n; i++) cp[i] = a[i];

    for (int i = 0; i < n; i++){
        if(i >= idx){
            if(i == idx){
                a[i] = x;
                a[i + 1] = cp[i];
                i++;
                continue;
            }
            a[i] = cp[i - 1];
            continue;
        }
        a[i] = a[i];
    }
}

int main(){
    int list[] = {1, 3, 4, 7, 9, 11};
    int size = sizeof(list) / sizeof(list[0]);

    aryins(list, size, 2, 99);

    cout << "aryinsを呼び出した結果 = {";
    for (int i = 0; i < size; i++){
        if(size - 1 == i){
            cout << list[i];
            continue;
        }
        cout << list[i] << ", ";
    }
    cout << "}" << endl;
}