#include <iostream>

using namespace std;

int main(){
    double value1, value2;

    cout << "実数を2つ入力してください(a b)>>> ";
    cin >> value1 >> value2;
    
    int max = value1 > value2 ? value1 : value2;
    cout << "大きい方の値: "<< max  << endl;
}