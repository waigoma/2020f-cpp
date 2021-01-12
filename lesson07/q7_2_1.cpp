#include <iostream>

using namespace std;

double circle_area(double);

int main(){
    double input;
    cout << "実数を入力してください。>>> ";
    cin >> input;
    cout << "半径" << input << "の円の面積は" << circle_area(input) << "である。" << endl;
}

double circle_area(double radius){
    return radius * radius * 3.14;
}
