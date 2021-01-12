#include <iostream>

using namespace std;

void mySwap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;

    cout << "*x = " << *x << ", x = " << x << endl;
    cout << "*y = " << *y << ", y = " << y << endl;
}

void mySort(int* x, int* y, int* z){
    if(*x > *y) mySwap(x, y);
    if(*y > *z) mySwap(y, z);
    if(*x > *y) mySwap(x, y);
}

int main(){
    int a, b, c;

    cout << "変数a: ";
    cin >> a;

    cout << "変数b: ";
    cin >> b;

    cout << "変数c: ";
    cin >> c;

    cout << "a = " << a << ", &a = " << &a << endl;
    cout << "b = " << b << ", &b = " << &b << endl;
    cout << "c = " << c << ", &c = " << &c << endl;

    mySort(&a, &b, &c);

    cout << "変数a, b, cを昇順に並べ替えました。" << endl;

    cout << "a = " << a << ", &a = " << &a << endl;
    cout << "b = " << b << ", &b = " << &b << endl;
    cout << "c = " << c << ", &c = " << &c << endl;
}