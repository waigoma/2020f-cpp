#include <iostream>
#include <string>

using namespace std;

int calc_price(int price, int count){
    return price * count;
}

int main(){
    struct receipt{
        string name;
        int price;
        int quantity;
        int total;
    };

    struct receipt fruit = {"りんご", 100, 5};

    cout << "商品名を入力 >>> ";
    cin >> fruit.name;

    cout << "値段を入力 >>> ";
    cin >> fruit.price;

    cout << "個数を入力 >>> ";
    cin >> fruit.quantity;

    fruit.total = calc_price(fruit.price, fruit.quantity);
    
    cout << fruit.name << " | " << "単価: " << fruit.price << ", 個数: " << fruit.quantity << ", 合計: " << fruit.total << endl;
}