#include <iostream>

using namespace std;

int stringCompare(char* p0, char* p1){
    for (int i = 0; i < 80; i++){
        // cout << p0[i] << " " << p1[i] << endl;
        if(p0[i] == '\0' && p1[i] == '\0') break;
        if(p0[i] != p1[i]) return 0;
    }
    return 1;
}

int main(){
    char p0[80];
    char p1[80];

    cout << "文字列を入力(80字以内)>>> ";
    cin >> p0;

    cout << endl << "文字列を入力(80字以内)>>> ";
    cin >> p1;

    cout << "stringCompareからの戻り値 = " << stringCompare(p0, p1) << endl;
}