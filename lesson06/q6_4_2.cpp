#include <iostream>

using namespace std;

int main(){
    int points[6][2] = {};

    int jpSum = 0;
    double jpAverage = 0;

    int mathSum = 0;
    double mathAverage = 0;

    int stuSum[6] = {};
    double stuAverage[6] = {};

    int value;

    for (int i=0; i < 6; i++){
        for (int j=0; j < 2; j++){
            if(j == 0) cout << i+1 << "人目の国語の点数(整数)を入力してください>>> ";
            if(j == 1) cout << i+1 << "人目の数学の点数(整数)を入力してください>>> ";
            cin >> value;
            points[i][j] = value;
        }
    }
    
    for (int i=0; i < 6; i++){
        jpSum += points[i][0];
        mathSum += points[i][1];
    }
    jpAverage = jpSum / 6.0;
    mathAverage = mathSum / 6.0;

    cout << "国語の合計点: " << jpSum << endl;
    cout << "国語の平均点: " << jpAverage << endl;
    cout << "数学の合計点: " << mathSum << endl;
    cout << "数学の平均点: " << mathAverage << endl;

    value = 0;

    for (int i=0; i < 6; i++){
        for (int j=0; j < 2; j++){
            value += points[i][j];
        }
        stuSum[i] = value;
        value = 0;
    }

    for (int i=0; i < 6; i++){
        stuAverage[i] = stuSum[i] / 2.0;
        cout << "学生" << i+1 << "人目の合計点: " << stuSum[i] << endl;
        cout << "学生" << i+1 << "人目の平均点: " << stuAverage[i] << endl;
    }
}