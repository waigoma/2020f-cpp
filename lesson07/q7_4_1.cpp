#include <iostream>

using namespace std;

void put_starn(int);
void put_nchar(char);

int main(){
    int n;
    cout << "左下直角の三角形を表示します。" << endl;
    cout << "段数は: ";
    cin >> n;
    for(int i=1; i <=n; i++){
        put_starn(i);
        cout << endl;
    }
}

void put_starn(int n){
    while(n-- > 0) put_nchar('*');
}

void put_nchar(char c){
    cout << c;
}
