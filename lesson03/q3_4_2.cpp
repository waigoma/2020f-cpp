#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "整数を入力してください>>> ";
    cin >> value;

    if (value < 0) cout << "正でない値が入力されました。" << endl;

    int remainder = value % 3;
    
    if (remainder == 0){
        cout << "その値は3で割り切れます。" << endl;
    } else{
        cout << "その値の剰余は"<< remainder << "です。" << endl;
    }

}