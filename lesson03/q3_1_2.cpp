#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    srand(time(NULL));

    int inputValue;

    cout << "整数を入力>>> ";
    cin >> inputValue;

    int value = rand() % 10 - 5 + inputValue;

    cout << "整数値: " << inputValue << endl;
    cout << "この値の±5の乱数: " << value << endl;
}