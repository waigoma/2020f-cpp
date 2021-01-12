#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    srand(time(NULL));

    int value = rand() % 7;

    switch (value){
    case 0:
        cout << "大吉" << endl;
        break;
    case 1:
        cout << "吉" << endl;
        break;
    case 2:
        cout << "中吉" << endl;
        break;
    case 3:
        cout << "小吉" << endl;
        break;
    case 4:
        cout << "末吉" << endl;
        break;
    case 5:
        cout << "凶" << endl;
        break;
    case 6:
        cout << "大凶" << endl;
        break;
    }
}