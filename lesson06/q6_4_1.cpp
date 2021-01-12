#include <iostream>

using namespace std;

int main(){
    int matrix1[4][4] = {0};
    int matrix2[4][4] = {0};
    int answer[4][4] = {};

    int value;

    for (int i=0; i < 4; i++){//4行3列
        for (int j = 0; j < 3; j++){
            cout << i+1 << "行" << j+1 << "列の整数を入力してください>>> ";
            cin >> value;
            matrix1[i][j] = value;
        }
    }

    for (int i=0; i < 3; i++){//3行4列
        for (int j = 0; j < 4; j++){
            cout << i+1 << "行" << j+1 << "列の整数を入力してください>>> ";
            cin >> value;
            matrix2[i][j] = value;
        }
    }

    cout << endl << "行列1" << endl;
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "行列2" << endl;
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "答え" << endl;
    for (int i=0; i < 4; i++){
        for (int j=0; j < 4; j++){
            for (int k=0; k < 4; k++){
                answer[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    
}