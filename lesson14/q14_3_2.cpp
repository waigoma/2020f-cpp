#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int input = 0;
    cout << "2から表示させたい素数リストの終わりを整数で入力 >>> ";
    cin >> input;

    bool primalNum[input - 1] = {};
    for (int i = 0; i < input - 1; i++) primalNum[i] = true;

    for (int i = 0; i <= sqrt(input) - 1; i++){
        if (!primalNum[i]) continue;
        for (int j = i + 1; j < input - 1; j++){
            if ((j + 2) % (i + 2) == 0) primalNum[j] = false;
        }
    }

    cout << "2から" << input << "までの素数リスト: ";
    for (int i = 0; i < input - 1; i++){
        if (primalNum[i]) cout << i + 2 << " ";
    }
}