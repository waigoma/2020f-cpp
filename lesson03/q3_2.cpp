#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << setw(10) << right << "|";
    cout << setw(8) << right << "Japan";
    cout << setw(8) << right << "Others" << endl;

    cout << setfill('-');
    cout << setw(10) << right << "|";
    cout << setfill('-');
    cout << setw(16) << right << "-" << endl;

    cout << setfill(' ');
    cout << setw(10) << right << "Male|";
    cout << setw(8) << right << "50";
    cout << setw(8) << right << "40" << endl;

    cout << setw(10) << right << "Female|";
    cout << setw(8) << right << "35";
    cout << setw(8) << right << "55" << endl;
    
}