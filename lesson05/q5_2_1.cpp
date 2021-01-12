#include <iostream>
#include <string>

using namespace std;

int main(){
    string retry;
    int input;
    do{
        cout << "整数を入力してください。>>> ";
        cin >> input;

        if (input > 0){
            cout << "入力された整数は正である。" << endl;
        }else if(input < 0){
            cout << "入力された整数は負である。" << endl;
        }else{
            cout << "入力された整数は0である。" << endl;
        }

        cout << "繰り返しますか?(y/n)>>> ";
        cin >> retry;
        
    } while (retry == "Y" || retry == "y");
    
    
}