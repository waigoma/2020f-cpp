#include <iostream>

using namespace std;

int main(){
    int value1, value2;

    cout << "整数を2つ入力してください(a b)>>> ";
    cin >> value1 >> value2;
    
    int max = value1 > value2 ? value1 : value2;
    int min = value1 < value2 ? value1 : value2;
    cout << "値の差: "<< max - min  << endl;
}