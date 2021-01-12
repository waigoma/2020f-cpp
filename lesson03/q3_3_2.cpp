#include <iostream>

using namespace std;

int main(){
    int n;

    cout << "整数を入力してください>>> ";
    cin >> n;

    if (n > 0){
        cout << "正の数です。" << endl;
    } else if (n < 0){
        cout << "負の数です。" << endl;
    } else if (n == 0){
        cout << "0です。" << endl;
    }

}

/*
Ex3_7のelse節は、nが0より大きいでもなく、nが0よりも小さいでもない数値、つまり0しか来ない。
なので、else if(n == 0)にしても結果は変わらない。
*/