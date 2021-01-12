#include <iostream>
#include <string>

using namespace std;

int main(){
    int value1, value2;

    cout << "整数を2つ入力してください(a b)>>> ";
    cin >> value1 >> value2;
    
    int max = value1 > value2 ? value1 : value2;
    int min = value1 < value2 ? value1 : value2;

    string str = max - min > 10 ? "それらの差は11以上です。" : "それらの差は10以下です。" ;

    cout << str << endl;
}