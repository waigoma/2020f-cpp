#include <iostream>

using namespace std;

int main(){
    double x, y;

    cout << "数字を2つ入力>>> " << endl;
    cin >> x >> y;
    
    cout << "合計は" << x + y << "です。\n";
    
    cout << "平均は" << (x + y) / 2 << "です。\n";
}
