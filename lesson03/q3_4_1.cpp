#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "整数を入力してください>>> ";
    cin >> value;

    if (value < 0) cout << "正でない値が入力されました。" << endl;
    
    if (value % 5 == 0){
        cout << "その値は5で割り切れます。" << endl;
    } else{
        cout << "その値は5で割り切れません。" << endl;
    }

}