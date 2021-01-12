#include <iostream>

using namespace std;

int search_idx(int* a, int* idx, int n, int key){
    int count = 0;
    for(int i = 0; i < n; i++) {
        if (*a++ == key) {
            *idx++ = i;
            count++;
        }
    }
    return count;
}

int main(){
    int list1[7] = {1, 7, 5, 7, 2, 4, 7};
    int idx[] = {};

    int key;
    cout << "keyを入力>>> ";
    cin >> key;

    int size = search_idx(list1, idx, 7, key);

    cout << "search_idxからの戻り値 = " << size << endl;
    
    cout << "search_idxを呼び出した結果 = {";
    for (int i = 0; i < size; i++){
        if(size - 1 == i){
            cout << idx[i];
            continue;
        }
        cout << idx[i] << ", ";
    }
    cout << "}" << endl;
}