#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>

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
    ofstream ofs("data5.csv");
    int test1, test2, n;
    while(sp != NULL){
        test1 += sp->first;
        test2 += sp->second;
        n++;
        cout << "名前: " << sp->name << ", 第一回: " << sp->first << ", 第二回: " << sp->second << ", 平均: " << sp->average << ", 評価: " << sp->grade << endl;
        sp = sp->next;
    }

    double test1Average = test1 / (double)n;
    double test2Average = test2 / (double)n;

    double test1DevSum, test2DevSum, testDevSum;

    sp = top;
    while(sp != NULL){
        test1DevSum += pow(sp->first - test1Average, 2.0);
        test2DevSum += pow(sp->second - test2Average, 2.0);

        sp = sp->next;
    }
    
    double test1Dev = sqrt(test1DevSum / n);
    double test2Dev = sqrt(test2DevSum / n);

    
    cout << "第一回平均: " << test1Average << ", 第二回平均: " << test2Average << endl;
    cout << "第一回偏差: " << test1Dev << ", 第二回偏差: " << test2Dev << endl;
    
    ofs.close();
    ifs.close();
}