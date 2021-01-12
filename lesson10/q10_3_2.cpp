#include <iostream>
#include <cstdlib>

using namespace std;

void mem_set(void* p, int n, unsigned char v){
    unsigned char* cp = (unsigned char*)p;
    for(int i = 0; i < n; i++){
        cp[i] = v;
    }

    cout << "mem_setを呼び出した結果 = {";
    for (int i = 0; i < n; i++){
        if(n - 1 == i){
            cout << cp[i];
            continue;
        }
        cout << cp[i] << ", ";
    }
    cout << "}" << endl;

}

int main(){
    int size = 0;
    cout << "バイトを入力>>> ";
    cin >> size;

    void* xp = malloc(sizeof(unsigned char) * size);

    mem_set(xp, size, '0');

    free(xp);
}