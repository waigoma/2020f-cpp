#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    srand(time(NULL));

    int value = rand() % 3;

    switch (value){
    case 0:
        cout << "グー" << endl;
        break;
    case 1:
        cout << "チョキ" << endl;
        break;
    case 2:
        cout << "パー" << endl;
        break;
    }
}