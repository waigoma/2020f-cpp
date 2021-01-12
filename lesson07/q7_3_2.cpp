#include <iostream>

using namespace std;

void print_season(int);

int main(){
    int month;
    cout << "知りたい季節の月入力してください。>>> ";
    cin >> month;
    print_season(month);
}

void print_season(int month){
    if(month == 3 || month == 4 || month == 5) cout << month << "の月の季節は「春」である。" << endl;
    if(month == 6 || month == 7 || month == 8) cout << month << "の月の季節は「夏」である。" << endl;
    if(month == 9 || month == 10 || month == 11) cout << month << "の月の季節は「秋」である。" << endl;
    if(month == 12 || month == 1 || month == 2) cout << month << "の月の季節は「冬」である。" << endl;
}
