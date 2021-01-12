#include <iostream>
#include <string>

using namespace std;

struct receipt{
    string name;
    int price;
    int quantity;
    int total;
};

void show_total(struct receipt* rp){
    rp->total = rp->price * rp->quantity;
}

int main(){
    struct receipt fruit = {"りんご", 100, 5};
    show_total(&fruit);
}