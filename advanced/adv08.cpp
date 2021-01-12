#include "canvas/canvas.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace canvas;
using namespace std;

void spade(int, int, double);
void club(int, int, double);
void heart(int, int, double);
void diamond(int, int, double);
void drawSuit(int, int, int, double);
void drawCard(int, int, int, int);
void drawDumCard(int, int);
void delCard(int, int);
void drawA(int, int, int);
void draw2(int, int, int);
void draw3(int, int, int);
void draw4(int, int, int);
void draw5(int, int, int);
void draw6(int, int, int);
void draw7(int, int, int);
void draw8(int, int, int);
void draw9(int, int, int);
void draw10(int, int, int);
void drawJ(int, int, int);
void drawQ(int, int, int);
void drawK(int, int, int);
void random_cards();

vector<string> cards;

int main(){
    show(1500, 720);
    setColor(0, 125, 75);
    fillRectangle(0, 0, 1500, 700);
    random_cards();

    int states[52] = {0};

    int x = 25;
    int y = 25;
    for(int suit = 0; suit < 4; suit++){
        for(int num = 1; num <= 13; num++){
            drawDumCard(50 + num * 85, 50 + suit * 125);
        }
    }

    int count = 0;

    while(true){
        waitForPoint();
        int i = (getPointedY() - 50) / 125;
        int j = (getPointedX() - 50) / 85;

        if(j >= 1 && j <= 13){
            if (i == 0){
                if(states[j - 1] != 2) {
                    states[j - 1] = 1;
                    count++;
                }
            }else if(i == 1){
                if(states[j + 12] != 2) {
                    states[j + 12] = 1;
                    count++;
                }
            }else if(i == 2){
                if(states[j + 25] != 2) {
                    states[j + 25] = 1;
                    count++;
                }
            }else if(i == 3){
                if(states[j + 38] != 2) {
                    states[j + 38] = 1;
                    count++;
                }
            }
        }

         for(int num = 1; num <= 52; num++){
            int x = states[num - 1];
            string suit_s = cards[num - 1];
            string rank_s = cards[num - 1];
            if(x == 0){
                if(num <= 13){
                    i = 0;
                    j = num;
                }else if(num <= 13 * 2){
                    i = 1;
                    j = num % 13;
                }else if(num <= 13 * 3){
                    i = 2;
                    j = num % 13;
                }else if(num <= 13 * 4){
                    i = 3;
                    j = num % 13;
                }
                if(j == 0) j = 13;
                drawDumCard(50 + j * 85, 50 + i * 125);
            }else if(x == 1){
                if(num <= 13){
                    i = 0;
                    j = num;
                }else if(num <= 13 * 2){
                    i = 1;
                    j = num % 13;
                }else if(num <= 13 * 3){
                    i = 2;
                    j = num % 13;
                }else if(num <= 13 * 4){
                    i = 3;
                    j = num % 13;
                }
                if(j == 0) j = 13;

                string suit = suit_s.replace(1, 1, "");
                string rank = rank_s.replace(0, 1, "");

                int suit_i, rank_i = 0;
                if(suit == "S") suit_i = 0;
                if(suit == "H") suit_i = 1;
                if(suit == "D") suit_i = 2;
                if(suit == "C") suit_i = 3;

                if(rank == "A") rank_i = 1;
                else if(rank == "T") rank_i = 10;
                else if(rank == "J") rank_i = 11;
                else if(rank == "Q") rank_i = 12;
                else if(rank == "K") rank_i = 13;
                else rank_i = stoi(rank);

                drawCard(suit_i, rank_i, 50 + j * 85, 50 + i * 125);
            }else if(x == 2){
                if(num <= 13){
                    i = 0;
                    j = num;
                }else if(num <= 13 * 2){
                    i = 1;
                    j = num % 13;
                }else if(num <= 13 * 3){
                    i = 2;
                    j = num % 13;
                }else if(num <= 13 * 4){
                    i = 3;
                    j = num % 13;
                }
                if(j == 0) j = 13;
                delCard(50 + j * 85, 50 + i * 125);
            }
        }

        if(count >= 2){
            int num = 1;
            int rank1[2] = {0}, rank2[2] = {1};
            string suits[2];
            int ct = 0;
            for(int x : states){
                if(x == 1){
                    string rank_s = cards[num - 1];
                    string rank = rank_s.replace(0, 1, "");
                    string suit_s = cards[num - 1];
                    string suit = suit_s.replace(1, 1, "");

                    int rank_i;

                    if(rank == "A") rank_i = 1;
                    else if(rank == "T") rank_i = 10;
                    else if(rank == "J") rank_i = 11;
                    else if(rank == "Q") rank_i = 12;
                    else if(rank == "K") rank_i = 13;
                    else rank_i = stoi(rank);

                    if(ct == 0) {
                        rank1[0] = rank_i;
                        rank1[1] = num - 1;
                        suits[0] = suit;
                    }
                    if(ct == 1){ 
                        rank2[0] = rank_i;
                        rank2[1] = num - 1;
                        suits[1] = suit;
                    }
                    ct++;
                }
                num++;
            }
            if(rank1[0] == rank2[0]){
                    if(suits[0] != suits[1]){
                    states[rank1[1]] = 2;
                    states[rank2[1]] = 2;
                }else{
                    states[rank1[1]] = 0;
                    states[rank2[1]] = 0;
                }
            }else{
                states[rank1[1]] = 0;
                states[rank2[1]] = 0;
            }
            count = 0;
        }
    }
}

void random_cards(){
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

    // for(string str : cards) cout << str << " || ";
}

void spade(int x, int y, double s){
    setColor(0, 0, 0);
    fillTriangle(x, y, x - 40 * s, y + 125 * s, x + 40 * s, y + 125 * s);
    fillTriangle(x, y - 50 * s, x - 70 * s, y + 20 * s, x + 70 * s, y + 20 * s);

    fillCircle(x - 30 * s, y + 50 * s, 50 * s);
    fillCircle(x + 30 * s, y + 50 * s, 50 * s);
}

void club(int x, int y, double s){
    setColor(0, 0, 0);
    fillTriangle(x, y, x - 50 * s, y + 125 * s, x + 50 * s, y + 125 * s);

    fillCircle(x - 50 * s, y + 25 * s, 50 * s);
    fillCircle(x, y - 35 * s, 50 * s);
    fillCircle(x + 50 * s, y + 25 * s, 50 * s);
}

void heart(int x, int y, double s){
    setColor(255, 0, 0);
    fillTriangle(x, y + 100 * s, x - 80 * s, y, x + 80 * s, y);

    fillCircle(x - 37 * s, y - 25 * s, 50 * s);
    fillCircle(x + 38 * s, y - 25 * s, 50 * s);
}

void diamond(int x, int y, double s){
    setColor(255, 0, 0);
    fillTriangle(x, y + 120 * s, x - 60 * s, y, x + 60 * s, y);
    fillTriangle(x, y - 120 * s, x - 60 * s, y, x + 60 * s, y);
}

void drawA(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "A");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 40, y + 60, .15);
    setTextColor(0, 0, 0);
}

void draw2(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "2");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 40, y + 24, .07);
    drawSuit(suit, x + 40, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw3(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "3");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 40, y + 24, .07);
    drawSuit(suit, x + 40, y + 60, .07);
    drawSuit(suit, x + 40, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw4(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "4");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw5(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "5");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 60, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw6(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "6");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 60, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 60, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw7(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "7");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 60, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 48, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 60, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw8(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "8");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 60, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 48, .07);
    drawSuit(suit, x + 40, y + 72, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 60, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw9(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "9");
    drawSuit(suit, x + 8, y + 26, .07);

    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 48, .07);
    drawSuit(suit, x + 25, y + 72, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 60, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 48, .07);
    drawSuit(suit, x + 55, y + 72, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw10(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "10");
    drawSuit(suit, x + 8, y + 26, .07);

    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 48, .07);
    drawSuit(suit, x + 25, y + 72, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 36, .07);
    drawSuit(suit, x + 40, y + 84, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 48, .07);
    drawSuit(suit, x + 55, y + 72, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void drawJ(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "J");
    drawSuit(suit, x + 8, y + 26, .07);

    drawRectangle(x + 20, y + 30, 40, 60);
    setTextColor(0, 0, 0);
}

void drawQ(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "Q");
    drawSuit(suit, x + 8, y + 26, .07);

    drawRectangle(x + 20, y + 30, 40, 60);
    setTextColor(0, 0, 0);
}

void drawK(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "K");
    drawSuit(suit, x + 8, y + 26, .07);

    drawRectangle(x + 20, y + 30, 40, 60);
    setTextColor(0, 0, 0);
}

void drawSuit(int suit, int x, int y, double s){
    switch (suit){
        case 0: // spade
            spade(x, y, s);
            break;
        case 1: // heart
            heart(x, y, s);
            break;
        case 2: // diamond
            diamond(x, y, s);
            break;
        case 3: // club
            club(x, y, s);
            break;
    }
}

void drawDumCard(int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);

    setColor(200, 0, 0);
    drawRectangle(x + 10, y + 10, 60, 100);

    setColor(200, 0, 0);
    fillRectangle(x + 20, y + 20, 40, 80);
    setTextColor(0, 0, 0);
}

void delCard(int x, int y){
    setColor(0, 125, 75);
    fillRectangle(x, y, 80, 120);
}

void drawCard(int suit, int rank, int x, int y){
    switch (rank){
    case 1:
        drawA(suit, x, y);
        break;
    case 2:
        draw2(suit, x, y);
        break;
    case 3:
        draw3(suit, x, y);
        break;
    case 4:
        draw4(suit, x, y);
        break;
    case 5:
        draw5(suit, x, y);
        break;
    case 6:
        draw6(suit, x, y);
        break;
    case 7:
        draw7(suit, x, y);
        break;
    case 8:
        draw8(suit, x, y);
        break;
    case 9:
        draw9(suit, x, y);
        break;
    case 10:
        draw10(suit, x, y);
        break;
    case 11:
        drawJ(suit, x, y);
        break;
    case 12:
        drawQ(suit, x, y);
        break;
    case 13:
        drawK(suit, x, y);
        break;
    }
}