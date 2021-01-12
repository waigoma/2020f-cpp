#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int random(int, int);
int random2(int, int);

int main(){
    int a, b;
    cout << "2つの整数を入力してください。>>> ";
    cin >> a >> b;
    cout << "入力された範囲(" << a << "以上" << b << "未満)のランダム値: " << random(a, b) << endl;
}

int random(int a, int b){
    if(b <= a) return a;
    return random2(a, b);
}

int random2(int a, int b){
    srand(time(NULL));
    if(a == 1) return rand() % (b - 1) + a;
    return rand() % (b - a) + a;
}