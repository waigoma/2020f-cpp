#include <iostream>

using namespace std;

int sum(int n){
    int sm = 0;

    cout << "sm = " << sm << endl;
    cout << "&sm = " << &sm << endl;

    cout << "sum() n = " << n << endl;
    cout << "sum() -> &n = " << &n << endl;

    if(n > 1) sm = sum(n - 1) + n;
    else sm = 1;

    cout << "sm = " << sm << endl;
    cout << "&sm = " << &sm << endl;

    return sm;
}

int main(){
    int n, total;
    
    cout << "正の整数を入力: ";
    cin >> n;

    total = sum(n);

    cout << "main() -> n = " << n << endl;
    cout << "main() -> &n = " << &n << endl;

    cout << "total = " << total << endl;
    cout << "&total = " << &total << endl;

    cout << "1から" << n << "までの合計: " << total << endl;
}

/*
正の整数を入力: 3

sm = 0
&sm = 0x61fedc
sum() n = 3
sum() -> &n = 0x61fef0

sm = 0
&sm = 0x61feac
sum() n = 2
sum() -> &n = 0x61fec0

sm = 0
&sm = 0x61fe7c
sum() n = 1
sum() -> &n = 0x61fe90

sm = 1
&sm = 0x61fe7c
sm = 3
&sm = 0x61feac
sm = 6
&sm = 0x61fedc

main() -> n = 3
main() -> &n = 0x61ff0c
total = 6
&total = 0x61ff08

1から3までの合計: 6


        sm    0x61fedc  0 -> 6
        n     0x61fef0  3
sum(3)
----------------------
        sm    0x61feac  0 -> 3
        n     0x61fec0  2
sum(2)
----------------------
        sm    0x61fe7c  0 -> 1
        n     0x61fe90  1
sum(1)
----------------------
main()  n     0x61ff0c  3
        total 0x61ff08  6
*/