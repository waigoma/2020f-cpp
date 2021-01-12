#include <iostream>
using namespace std;

int main(){
    const int x = 10;
    const int x1 = 20;

    int y = 30;

    cout << "const int1" << endl;
    cout << "xの格納アドレスは " << &x << endl;
    cout << "xのサイズは " << sizeof x << " Bytes" << endl;
    cout << "xの値は " << x << endl << endl;

    cout << "const int2" << endl;
    cout << "x1の格納アドレスは " << &x1 << endl;
    cout << "x1のサイズは " << sizeof x1 << " Bytes" << endl;
    cout << "x1の値は " << x1 << endl << endl;

    cout << "int" << endl;
    cout << "yの格納アドレスは " << &y << endl;
    cout << "yのサイズは " << sizeof y << " Bytes" << endl;
    cout << "yの値は " << y << endl;
}
/*
---------実行結果----------
const int1
xの格納アドレスは 0x61ff0c
xのサイズは 4 Bytes
xの値は 10

const int2
x1の格納アドレスは 0x61ff08
x1のサイズは 4 Bytes
x1の値は 20

int
yの格納アドレスは 0x61ff04
yのサイズは 4 Bytes
yの値は 30
-------------------------
> 考察
    constを付けてもintと変わらない。ただ単に後で数値を変更できないだけ。
    定数となる。
*/