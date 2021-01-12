#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "整数を入力してください>>> ";
    cin >> value;
    
    if (value < 0) cout << "正でない値が入力されました。" << endl;
    
    if (value % 8 == 0 && value % 3 == 0){
        cout << "その値は3と8の両方で割り切れます。" << endl;
    }else{
        cout << "その値は3か8のどちらかで割り切れません。" << endl;
    }
}