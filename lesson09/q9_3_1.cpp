#include <iostream>

using namespace std;

int sum_of(int a[], int n){
    int result = 0;

    for (int i = 0; i < n; i++){
        result += a[i];
    }

    return result;
}

int main(){
    int list[] = {1, 2, 3, 4, 5};

    cout << "sum_ofを呼び出した結果 = " << sum_of(list, sizeof(list) / sizeof(list[0])) << endl;
}