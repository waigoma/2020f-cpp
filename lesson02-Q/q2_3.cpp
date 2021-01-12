#include <iostream>
using namespace std;

int main(){
    const int x = 10;

    const long x1 = 20;

    const short y = 30;

    const char y1 = 'a';

    const float z = 50;

    const double z1 = 60;

    cout << "int" << endl;
    cout << "xの格納アドレスは " << &x << endl;
    cout << "xのサイズは " << sizeof x << " Bytes" << endl;
    cout << "xの値は " << x << endl << endl;

    cout << "long" << endl;
    cout << "x1の格納アドレスは " << &x1 << endl;
    cout << "x1のサイズは " << sizeof x1 << " Bytes" << endl;
    cout << "x1の値は " << x1 << endl << endl;

    cout << "short" << endl;
    cout << "yの格納アドレスは " << &y << endl;
    cout << "yのサイズは " << sizeof y << " Bytes" << endl;
    cout << "yの値は " << y << endl << endl;

    cout << "char" << endl;
    cout << "y1の格納アドレスは " << (void*)&y1 << endl;
    cout << "y1のサイズは " << sizeof y1 << " Bytes" << endl;
    cout << "y1の値は " << y1 << endl << endl;

    cout << "float" << endl;
    cout << "zの格納アドレスは " << &z << endl;
    cout << "zのサイズは " << sizeof z << " Bytes" << endl;
    cout << "zの値は " << z << endl << endl;

    cout << "double" << endl;
    cout << "z1の格納アドレスは " << &z1 << endl;
    cout << "z1のサイズは " << sizeof z1 << " Bytes" << endl;
    cout << "z1の値は " << z1 << endl;
}
/*
----------実行結果----------
int
xの格納アドレスは 0x61ff0c
xのサイズは 4 Bytes
xの値は 10

long
x1の格納アドレスは 0x61ff08
x1のサイズは 4 Bytes
x1の値は 20

short
yの格納アドレスは 0x61ff06
yのサイズは 2 Bytes
yの値は 30

char
y1の格納アドレスは 0x61ff05
y1のサイズは 1 Bytes
y1の値は a

float
zの格納アドレスは 0x61ff00
zのサイズは 4 Bytes
zの値は 50

double
z1の格納アドレスは 0x61fef8
z1のサイズは 8 Bytes
z1の値は 60
---------------------------
> 考察
    constを付けてもサイズは変更されない。
*/