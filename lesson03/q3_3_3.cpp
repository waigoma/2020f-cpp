#include <iostream>

using namespace std;

int main(){
    int value1, value2;

    cout << "比較したい整数2つを入力してください(a b)>>> ";
    cin >> value1 >> value2;

    if (value1 > value2){
        cout << "aの方が大きいです。" << endl;
    } else if (value1 < value2){
        cout << "bの方が大きいです。" << endl;
    } else if (value1 == value2){
        cout << "aとbは同じ値です。" << endl;
    }

}