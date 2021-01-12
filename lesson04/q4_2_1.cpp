#include <iostream>

using namespace std;

int main(){
    int value1, value2, value3;

    cout << "整数を3つ入力してください(a b c)>>> ";
    cin >> value1 >> value2 >> value3;
    
    int min = value1 < value2 ? value1 : value2;
    min = min < value3 ? min : value3;

    cout << "最小値: "<< min  << endl;
}