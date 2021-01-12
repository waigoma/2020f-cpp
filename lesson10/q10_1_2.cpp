#include <iostream>

using namespace std;

void ary_cpy(int* b, int* a, int n){
    for(int i = 0; i < n; i++) *a++ = *b++;
}

int main(){
    int list1[5] = {1, 2, 3, 4, 5};
    int list2[5];
    ary_cpy(list1, list2, 5);

    cout << "ary_cpyを呼び出した結果 = {";
    for (int i = 0; i < 5; i++){
        if(5 - 1 == i){
            cout << list2[i];
            continue;
        }
        cout << list2[i] << ", ";
    }
    cout << "}" << endl;
}