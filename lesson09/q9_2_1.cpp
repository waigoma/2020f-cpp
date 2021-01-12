#include <iostream>

using namespace std;

void mySwap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;

    cout << "*x = " << *x << ", x = " << x << endl;
    cout << "*y = " << *y << ", y = " << y << endl;
}

int main(){
    int a, b;

    cout << "変数a: ";
    cin >> a;

    cout << "変数b: ";
    cin >> b;

    cout << "a = " << a << ", &a = " << &a << endl;
    cout << "b = " << b << ", &b = " << &b << endl;

    mySwap(&a, &b);

    cout << "変数aとbの値を変更しました。" << endl;

    cout << "a = " << a << ", &a = " << &a << endl;
    cout << "b = " << b << ", &b = " << &b << endl;
}