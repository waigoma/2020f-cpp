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

    int count = 0;

    for (int i=0; i < input; i++){
        if (count > 4){
            cout << endl;
            count = 0;
        }
        cout << "*";
        count++;
    }
    
}