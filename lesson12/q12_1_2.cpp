#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream ofs("data99.txt");
    
    for(int i = 1; i <=9; i++){
        for(int j = 1; j <= 9; j++){
            ofs << i * j << " ";
        }
        ofs << endl;
    }
    ofs.close();
}