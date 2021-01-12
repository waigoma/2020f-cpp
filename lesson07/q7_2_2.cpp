#include <iostream>

using namespace std;

int sump(int);

int main(){
    int input;
    cout << "整数を入力してください。>>> ";
    cin >> input;
    cout << "1 ~ " << input << "までのすべての整数の和は" << sump(input) << "である。" << endl;
}

int sump(int range){
    int result = 0;

    for (int i=1; i <= range; i++){
        result += i;
    }
    
    return result;
}
