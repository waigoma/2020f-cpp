#include <climits>
#include <iostream>
using namespace std;
int main(){
    short s = SHRT_MAX;
    cout << "short max " << s << "" << endl;
    s = SHRT_MIN;
    cout << "short min " << s << endl << endl;

    int i = INT_MAX;
    cout << "int max " << i << endl;
    i = INT_MIN;
    cout << "int min " << i << "" << endl << endl;

    long l = LONG_MAX;
    cout << "long max " << l << endl;
    l = LONG_MIN;
    cout << "long min " << l << "" << endl;
}