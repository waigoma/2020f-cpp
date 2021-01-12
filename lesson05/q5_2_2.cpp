#include <iostream>

using namespace std;

int main(){
    int input1, input2, count;

    cout << "2つ整数を入力してください。>>> ";
    cin >> input1 >> input2;

    if (input1 > input2){
        int tmp = input2;
        input2 = input1;
        input1 = tmp;
    }else if(input1 == input2){
        cout << "同じ値が入力されました。" << endl;
    }

    count = input2 - input1;
    int i = 0;

    while (count >= i){
        if (count > i){
            cout << input1 << ", ";
        }else{
            cout << input1;
        }
        input1++;
        i++;
    }
   
}