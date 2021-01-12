#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Score{
    string name;
    int first;
    int second;
    double average;
    string grade;
    struct Score* next;
};

int main(){
    ifstream ifs("data4.csv");

    string line;
    stringstream stream;
    Score *top = NULL;
    Score *sp;
    
    while(getline(ifs, line)){
        sp = new Score;
        sp->next = top;
        top = sp;

        stream.clear();
        stream << line;

        int i = 0;
        string buf;
        while(getline(stream, buf, ',')){
            if(i == 0){
                sp->name = buf;
            }
            if(i == 1){
                sp->first = atoi(buf.c_str());
            }
            if(i == 2){
                sp->second = atoi(buf.c_str());
            }
            i++;
        }
        sp->average = (sp->first + sp->second) / 2.0;
        if(sp->average >= 90){
            sp->grade = "A+";
        }else if(sp->average >= 80 && sp->average < 90){
            sp->grade = "A";
        }else if(sp->average >= 70 && sp->average < 80){
            sp->grade = "B";
        }else if(sp->average >= 60 && sp->average < 70){
            sp->grade = "C";
        }
        i = 0;
    }
    sp = top;
    while(sp != NULL){
        cout << "名前: " << sp->name << ", 第一回: " << sp->first << ", 第二回: " << sp->second << ", 平均: " << sp->average << ", 評価: " << sp->grade << endl;
        sp = sp->next;
    }
    ifs.close();
}