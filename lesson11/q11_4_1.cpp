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

int main(){
    Sequence first = {"太郎", NULL};
    Sequence second = {"花子", NULL};
    first.next = &second;
    print_list(&first);
}