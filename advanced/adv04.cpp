#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    vector<string> cards;

    for (string suit : {"S", "H", "D", "C"}){
        for(int i=0; i < 13; i++){
            ostringstream oss;
            oss << i + 1;
            if(i == 0) {
                cards.push_back(suit + "A");
                continue;
            }
            if(i == 9) {
                cards.push_back(suit + "T");
                continue;
            }
            if(i == 10) {
                cards.push_back(suit + "J");
                continue;
            }
            if(i == 11) {
                cards.push_back(suit + "Q");
                continue;
            }
            if(i == 12) {
                cards.push_back(suit + "K");
                continue;
            }
            cards.push_back(suit + oss.str());
        }
    }
    srand(time(NULL));
    int count = rand() % 100 + 1;

    for(int i=0; i < count; i++) random_shuffle(cards.begin(), cards.end());

    for(string str : cards) cout << str << " || ";
}
