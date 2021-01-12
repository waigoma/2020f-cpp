#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "整数を入力してください>>> ";
    cin >> value;
    
    if (value < 0) cout << "正でない値が入力されました。" << endl;
    
    if (value % 5 == 0 || value % 3 == 0){
        cout << "その値は5または3で割り切れます。" << endl;
    }else{
        cout << "その値は5でも3でも割り切れません。" << endl;
    }
}