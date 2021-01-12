#include <iostream>

using namespace std;

int main(){
    int value1, value2;

    cout << "整数を2つ入力してください(a b)>>> ";
    cin >> value1 >> value2;
    
    if (value1 > value2){
        cout << "小さい方の値: " << value2  << endl;
        cout << "大きい方の値: " << value1  << endl;
    }else if (value2 > value1){
        cout << "小さい方の値: " << value1  << endl;
        cout << "大きい方の値: " << value2  << endl;
    }else if (value1 == value2){
        cout << "2つの値は同じです。" << value1  << endl;
    }
}