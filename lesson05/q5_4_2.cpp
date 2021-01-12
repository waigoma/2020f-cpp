#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int input;

    cout << "正の整数を入力してください。>>> ";
    cin >> input;

    for (int i=0; i < input; i++){
        cout << setw(i + 1);
        for (int i1=0; i1 <= input * 2 - 2 - i * 2; i1++){
            cout << i + 1;
        }
        cout << endl;
    }
    
}