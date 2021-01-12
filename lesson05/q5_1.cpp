#include <iostream>

using namespace std;

int main(){
    int x = 10;

    cout << "外側の変数xの値: " << x << endl;
    cout << "外側の変数xのアドレス: " << &x << endl << endl;
    {
        cout << "外側の変数xの値: " << x << endl;
        cout << "外側の変数xのアドレス: " << &x << endl;

        int x = 20;
        cout << "外側の変数xの値: " << x << endl;
        cout << "外側の変数xのアドレス: " << &x << endl << endl;
    }

    {
        int y = 30;
        cout << "外側の変数xの値: " << x << endl;
        cout << "外側の変数xのアドレス: " << &x << endl;
        cout << "外側の変数yの値: " << y << endl;
        cout << "外側の変数yのアドレス: " << &y << endl;
    }
}