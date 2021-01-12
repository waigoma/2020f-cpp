#include <iostream>

using namespace std;

void myFill(int* p, int n, int v){
    for(int i = 0; i < n; i++) *p++ = v;
}

int main(){
    int list[5];
    myFill(list, 5, 99);

    cout << "myFillを呼び出した結果 = {";
    for (int i = 0; i < 5; i++){
        if(5 - 1 == i){
            cout << list[i];
            continue;
        }
        cout << list[i] << ", ";
    }
    cout << "}" << endl;
}