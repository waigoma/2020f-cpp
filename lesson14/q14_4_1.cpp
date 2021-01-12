#include <iostream>
#include <cmath>

using namespace std;

double quadrature(double start, double end, int num) {
    double sum = 0;
    double pitch = (end - start) / num;

    for(int i = 0; i < num; i++) {
        double x = pitch * i + start;
        double y = cos(x);
        sum += y * pitch;
    }

    return sum;
}

int main() {
    double z = quadrature(0, 1, 10000);
    cout << z;
}