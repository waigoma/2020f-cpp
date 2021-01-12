#include <iostream>

using namespace std;

int main(){
    int input;
    int count = 0;

    cout << "正の整数を入力してください。>>> ";
    cin >> input;

    if (input < 0){
        cout << "正の整数を入力してください。" << endl;
        return 0;
    }

    int i = 0;
    int value = input;

    while (value > 0){
        value /= 10;
        count++;
        i++;
    }

    cout << input << "の桁数: " << count << endl;
    
}