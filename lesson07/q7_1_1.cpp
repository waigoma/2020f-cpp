#include <iostream>

using namespace std;

int sign_off(int n){
    int result;
    if (n < 0) result = -1;
    else if (n == 0) result = 0;
    else if (n > 0) result = 1;
    return result;
}

int main(){
    int input;
    cout << "整数を入力してください。>>> ";
    cin >> input;
    cout << "受け取った数値は" << input << "で、返り値は" << sign_off(input) << "である。" << endl;
}
