#include <iostream>
#include <string>

using namespace std;

struct receipt{
    string name;
    int price;
    int quantity;
    int total;
};

void inputGoods(struct receipt* rp, int n){
    while(n-- > 0){
        string name;
        int price, quantity;

        cout << "商品名を入力 >>> ";
        cin >> name;

        cout << "単価を入力 >>> ";
        cin >> price;

        cout << "個数を入力 >>> ";
        cin >> quantity;

        rp->name = name;
        rp->price = price;
        rp->quantity = quantity;
        
        rp++;
    }
}

void printGoods(struct receipt* rp, int n){
    while(n-- > 0){
        rp->total = rp->price * rp->quantity;
        cout << rp->name << " | 単価: " << rp->price << ", 個数: " << rp->quantity << ", 合計: " << rp->total << endl;

        rp++;
    }
}

int main(){
    int n = 0;
    cout << "レシートの数を指定してください >>> ";
    cin >> n;

    struct receipt fruit[n] = {};

    inputGoods(fruit, n);
    printGoods(fruit, n);
}