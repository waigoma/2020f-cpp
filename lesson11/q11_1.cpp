#include <iostream>
#include <string>

using namespace std;

int calc_tax(int price, int tax){
    return price * (1.0 + tax / 100.0);
}

int main(){
    struct product{
        string name;
        int price;
        int tax;
        int priceWithTax;
    };

    struct product p;

    cout << "商品名を入力 >>> ";
    cin >> p.name;

    cout << "値段を入力 >>> ";
    cin >> p.price;

    p.tax = 10;
    p.priceWithTax = calc_tax(p.price, p.tax);

    cout << "商品名: " << p.name << ", " << "価格: " << p.price << ", " << "消費税: " << p.tax << "%, " << "税込価格: " << p.priceWithTax << endl;
}