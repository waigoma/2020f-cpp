#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    srand(time(NULL));

    int value = rand() % 9 + 1;

    cout << "1以上9以下のランダムの値は: " << value << endl;
    value = -1 * rand() % 9 - 1;
    cout << "-9以上-1以下のランダムの値は: " << value << endl;
    value = rand() % 89 + 10;
    cout << "10以上99以下のランダムの値は: " << value << endl;
}