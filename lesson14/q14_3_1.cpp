#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool determination(int n){
    if (n == 1 || n == 0 || n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i+=2){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int input = 0;
    cout << "素数かどうかを判定したい整数を入力 >>> ";
    cin >> input;

    if (determination(input)) cout << input << "は素数である。" << endl;
    else cout << input << "は素数ではない。" << endl;
}