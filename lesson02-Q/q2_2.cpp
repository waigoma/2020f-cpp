#include <iostream>
using namespace std;

int main(){
    int x = 10;

    double x1 = 20;

    short y = 30;

    float y1 = 40;

    char z = 'a';

    int z1 = 60;

    unsigned char a = 'b';

    cout << "int" << endl;
    cout << "xの格納アドレスは " << &x << endl;
    cout << "xのサイズは " << sizeof x << " Bytes" << endl;
    cout << "xの値は " << x << endl << endl;

    cout << "double" << endl;
    cout << "x1の格納アドレスは " << &x1 << endl;
    cout << "x1のサイズは " << sizeof x1 << " Bytes" << endl;
    cout << "x1の値は " << x1 << endl << endl;

    cout << "short" << endl;
    cout << "yの格納アドレスは " << &y << endl;
    cout << "yのサイズは " << sizeof y << " Bytes" << endl;
    cout << "yの値は " << y << endl << endl;

    cout << "float" << endl;
    cout << "y1の格納アドレスは " << &y1 << endl;
    cout << "y1のサイズは " << sizeof y1 << " Bytes" << endl;
    cout << "y1の値は " << y1 << endl << endl;

    cout << "char" << endl;
    cout << "zの格納アドレスは " << (void*)&z << endl;
    cout << "zのサイズは " << sizeof z << " Bytes" << endl;
    cout << "zの値は " << z << endl << endl;

    cout << "int" << endl;
    cout << "z1の格納アドレスは " << &z1 << endl;
    cout << "z1のサイズは " << sizeof z1 << " Bytes" << endl;
    cout << "z1の値は " << z1 << endl << endl;

    cout << "unsigned char" << endl;
    cout << "aの格納アドレスは " << (void*)&a << endl;
    cout << "aのサイズは " << sizeof a << " Bytes" << endl;
    cout << "aの値は " << a << endl;
}

/*
----------実行結果----------
int
xの格納アドレスは 0x61ff0c
xのサイズは 4 Bytes
xの値は 10

double
x1の格納アドレスは 0x61ff00
x1のサイズは 8 Bytes
x1の値は 20

short
yの格納アドレスは 0x61fefe
yのサイズは 2 Bytes
yの値は 30

float
y1の格納アドレスは 0x61fef8
y1のサイズは 4 Bytes
y1の値は 40

char
zの格納アドレスは 0x61fef7
zのサイズは 1 Bytes
zの値は a

int
z1の格納アドレスは 0x61fef0
z1のサイズは 4 Bytes
z1の値は 60

unsigned char
aの格納アドレスは 0x61feef
aのサイズは 1 Bytes
aの値は b
--------------------
> 考察
    格納アドレスは0xffffffのように上から順に選ばれている。
    そして、番地は格納アドレスの一番下のアドレスを出力している。
    int型が4Bytesなのにアドレスを4つ以上使っている?
*/