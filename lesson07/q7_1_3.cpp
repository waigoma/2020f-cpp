#include <iostream>

using namespace std;

int med(int value1, int value2, int value3){
    int t;
    
    if (value2 < value1){
        t = value2;
        value2 = value1;
        value1 = t;
    }
    if (value3 < value1){
        t = value1;
        value1 = value3;
        value3 = value2;
        value2 = t;
    }else if(value3 < value2){
        t = value2;
        value2 = value3;
        value3 = t;
    }

    return value2;
}

int main(){
    int input1, input2, input3;
    cout << "整数を3つ入力してください。>>> ";
    cin >> input1 >> input2 >> input3;
    cout << "受け取った数値の中央値は" << med(input1, input2, input3) << "である。" << endl;
}

