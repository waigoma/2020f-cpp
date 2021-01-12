#include <iostream>

using namespace std;

int main(){
    int input;

    cout << "正の整数を入力してください。>>> ";
    cin >> input;

    if (input < 0){
        cout << "正の整数を入力してください。" << endl;
        return 0;
    }

    int value = 0;

    cout << "0 ~ " << input << " までの和: ";
    for (int i=0; i <= input; i++){
        value += i;
    }
    cout << value << endl;
    
}