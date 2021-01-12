#include <iostream>

using namespace std;

void maxline(int a[][5], int m[], int n){
    for(int i = 0; i < n; i++){
        int num, max = 0;
        for(int j = 0; j < 5; j++){
            num = a[i][j];
            if(num > max) max = num;
        }
        m[i] = max;
    }
}

int main(){
    int lists[][5] = {{1, 2, 5, 4, 8}, {6, 7, 4, 2, 3}, {3, 0, 5, 9, 1}};
    int maxList[] = {};
    int size = sizeof(lists) / sizeof(lists[0]);

    maxline(lists, maxList, size);

    cout << "maxlineを呼び出した結果 = {";
    for (int i = 0; i < size; i++){
        if(size - 1 == i){
            cout << maxList[i];
            continue;
        }
        cout << maxList[i] << ", ";
    }
    cout << "}" << endl;

}