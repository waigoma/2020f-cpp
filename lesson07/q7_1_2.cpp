#include <iostream>

using namespace std;

int min(int value1, int value2, int value3){
    int min = value1 < value2 ? value1 : value2;
    min = min < value3 ? min : value3;
    return min;
}

int main(){
    int input1, input2, input3;
    cout << "整数を3つ入力してください。>>> ";
    cin >> input1 >> input2 >> input3;
    cout << "受け取った数値の最小値は" << min(input1, input2, input3) << "である。" << endl;
}

