#include <iostream>
#include <fstream>
#include "price.h"
using namespace std;

void sum(price a, price b, price &c) {
    c.hryvnia = a.hryvnia + b.hryvnia;
    c.kopiyka = a.kopiyka + b.kopiyka;
    if (c.kopiyka >= 100) {
        c.hryvnia += c.kopiyka / 100;
        c.kopiyka %= 100;
    }
}
void res(price p, int kil, price &result){
    result.hryvnia = p.hryvnia * kil;
    result.kopiyka = p.kopiyka * kil;
    if (result.kopiyka >= 100) {
        result.hryvnia += result.kopiyka / 100;
        result.kopiyka %= 100;
    }
}
void round_price(price p, price &r){
    int money = p.hryvnia * 100 + p.kopiyka;
    int last = money % 10;

    if(last <= 4) money -= last;
    else money += (10 - last);
    r.hryvnia = money / 100;
    r.kopiyka = money % 100;
}
void readfile( const char* filename){
    int h, kil;
    short k;
    
    ifstream file (filename);
    if (file.is_open()) {
        cout << "Error!! << endl;
        return;"
}  
    }

    price total = {0, 0};
    while (file >> h >> k >> kil) {
        price p = {h, k};
        price line = {0, 0};
        price temp = {0, 0};
        res(p, kil, line);
        sum (total, line, temp);
        total = temp;
    }
    file.close(); {

    cout << "Total without rounding: ";
        << total.hryvnia << " UAH " << total.kopiyka << " kop" << endl;
    price rounded;
    round_price(total, rounded);
    cout << "Total with rounding: ";
        << rounded.hryvnia << " UAH " << rounded.kopiyka << " kop" << endl;
}
