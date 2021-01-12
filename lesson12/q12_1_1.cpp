#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream ifs("data2.txt");
    string str;
    int x, y;

    ifs >> str;
    ifs >> x >> y;

    cout << str << ", " << x << ", " << y << endl;

    ifs.close();
}