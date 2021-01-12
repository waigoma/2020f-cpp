#include <iostream>

using namespace std;

int main(){
    double x, y;

    cout << "数字を入力(底辺 高さ)>>> " << endl;
    cin >> x >> y;
    
    cout << "面積は" << (x * y) / 2 << "です。\n";
}