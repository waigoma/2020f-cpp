#include <iostream>
using namespace std;

int main(){
    double x = 10;
    double x1 = 20;

    float y = 30;
    float y1 = 40;

    short z = 50;
    short z1 = 60;

    cout << "double" << endl;
    cout << "xの格納アドレスは " << &x << endl;
    cout << "xのサイズは " << sizeof x << " Bytes" << endl;
    cout << "xの値は " << x << endl;
    cout << "x1の格納アドレスは " << &x1 << endl;
    cout << "x1のサイズは " << sizeof x1 << " Bytes" << endl;
    cout << "x1の値は " << x1 << endl << endl;

    cout << "float" << endl;
    cout << "yの格納アドレスは " << &y << endl;
    cout << "yのサイズは " << sizeof y << " Bytes" << endl;
    cout << "yの値は " << y << endl;
    cout << "y1の格納アドレスは " << &y1 << endl;
    cout << "y1のサイズは " << sizeof y1 << " Bytes" << endl;
    cout << "y1の値は " << y1 << endl << endl;

    cout << "short" << endl;
    cout << "zの格納アドレスは " << &z << endl;
    cout << "zのサイズは " << sizeof z << " Bytes" << endl;
    cout << "zの値は " << z << endl;
    cout << "z1の格納アドレスは " << &z1 << endl;
    cout << "z1のサイズは " << sizeof z1 << " Bytes" << endl;
    cout << "z1の値は " << z1 << endl;
}

/*
-------自分の環境の実行結果--------
double
xの格納アドレスは 0x61ff08
xのサイズは 8 Bytes
xの値は 10
x1の格納アドレスは 0x61ff00
x1のサイズは 8 Bytes
x1の値は 20

float
yの格納アドレスは 0x61fefc
yのサイズは 4 Bytes
yの値は 30
y1の格納アドレスは 0x61fef8
y1のサイズは 4 Bytes
y1の値は 40

short
zの格納アドレスは 0x61fef6
zのサイズは 2 Bytes
zの値は 50
z1の格納アドレスは 0x61fef4
z1のサイズは 2 Bytes
z1の値は 60
-----------------------------------
> 考察
    メモリは番地の大きい方から使っている。
    0xffffff -> 0xfffffe -> 0xfffffd
    1番地につき1Byte使用できる。そのため、doubleでは8Bytesなので8番地、floatでは4Bytesなので4番地、shortでは2Bytesなので2番地ずれている。
*/