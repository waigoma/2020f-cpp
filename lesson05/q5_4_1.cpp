#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int input;

    cout << "正の整数を入力してください。>>> ";
    cin >> input;

    for (int i=0; i < input; i++){
        cout << setw(input - i);
        for (int i1=0; i1 <= 2 * i; i1++){
            cout << "*";
        }
        cout << endl;
    }
    
}