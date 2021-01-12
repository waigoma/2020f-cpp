#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "1-12の整数を入力してください>>> ";
    cin >> value;

    switch (value){
    case 12:
    case 1:
    case 2:
        cout << "冬" << endl;
        break;
    case 3:
    case 4:
    case 5:
        cout << "春" << endl;
        break;
    case 6:
    case 7:
    case 8:
        cout << "夏" << endl;
        break;
    case 9:
    case 10:
    case 11:
        cout << "秋" << endl;
        break;
    
    default:
        cout << "1-12以外の整数が入力されました。" << endl;
    }
}