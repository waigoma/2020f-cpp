#include <iostream>

using namespace std;

int main(){
    int value1, value2, value3;

    cout << "整数を3つ入力してください(a b c)>>> ";
    cin >> value1 >> value2 >> value3;
    
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
    
    cout << "中央値: " << value2  << endl;
}