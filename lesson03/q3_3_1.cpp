#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "整数を入力してください>>> ";
    cin >> value;

    if (value < 0) value *= -1;
    
    cout << "整数値: "<< value  << endl;
    cout << "絶対値: " << value << endl;
}