#include <iostream>

using namespace std;

int main(){
    int input;
    bool plusMode = true;

    cout << "正の整数を入力してください。>>> ";
    cin >> input;

    if (input < 0){
        cout << "正の整数を入力してください。" << endl;
        return 0;
    }

    int i = 0;

    while (i < input){
        if (plusMode){
            cout << "+";
            plusMode = false;
        }else{
            cout << "-";
            plusMode = true;
        }
        i++;
    }

}