#include <iostream>

using namespace std;

int main(){
    int size = 0;
    cout << "配列のサイズを入力>>> ";
    cin >> size;

    double* list = new double[size];

    delete[] list;
}