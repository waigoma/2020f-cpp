#include <iostream>
#include <string>

using namespace std;

struct Sequence{
    string name;
    struct Sequence* next;
};

void print_list(Sequence* sp){
    do{
        cout << "名前: " << sp->name << endl;
        sp = sp->next;
    }while(sp != NULL);
}

void tail(Sequence* tp, Sequence* dp){
    do{
        if(tp->next == NULL) break;
        tp = tp->next;
    }while(tp != NULL);
    
    tp->next = dp;
}

int main(){
    Sequence first = {"太郎", NULL};
    Sequence second = {"花子", NULL};
    Sequence jirop = {"次郎", NULL};
    first.next = &second;

    tail(&first, &jirop);
    print_list(&first);
}