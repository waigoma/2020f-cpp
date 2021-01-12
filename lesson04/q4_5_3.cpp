#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "整数を入力してください>>> ";
    cin >> value;
    
    if (value < 0){ 
        cout << "正でない値が入力されました。" << endl;
        return 0;
    }
    
    if (value >= 90){
        cout << "S" << endl;
    }else if(value >= 87 && value <= 89){
        cout << "A+" << endl;
    }else if(value >= 83 && value <= 86){
        cout << "A" << endl;
    }else if(value >= 80 && value <= 82){
        cout << "A-" << endl;
    }else if(value >= 77 && value <= 79){
        cout << "B+" << endl;
    }else if(value >= 73 && value <= 76){
        cout << "B" << endl;
    }else if(value >= 70 && value <= 72){
        cout << "B-" << endl;
    }else if(value >= 67 && value <= 69){
        cout << "C+" << endl;
    }else if(value >= 63 && value <= 66){
        cout << "C" << endl;
    }else if(value >= 60 && value <= 62){
        cout << "C-" << endl;
    }else if(value <= 59){
        cout << "D" << endl;
    }
}