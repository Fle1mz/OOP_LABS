#include <iostream>
#include <fstream>
#include "price.h"
using namespace std;

void sum(Price a, Price b, Price &c) {
    c.hryvnia = a.hryvnia + b.hryvnia;
    c.kopiyka = a.kopiyka + b.kopiyka;
    if (c.kopiyka >= 100) {
        c.hryvnia += c.kopiyka / 100;
        c.kopiyka %= 100;
    }
}
void res(Price p, int kil, Price &result){
    result.hryvnia = p.hryvnia * kil;
    result.kopiyka = p.kopiyka * kil;
    if (result.kopiyka >= 100) {
        result.hryvnia += result.kopiyka / 100;
        result.kopiyka %= 100;
    }
}
void round_price(Price p, Price &r){
    int money = p.hryvnia * 100 + p.kopiyka;
    int last = money % 10;

    if(last <= 4) money -= last;
    else money += (10 - last);
    r.hryvnia = money / 100;
    r.kopiyka = money % 100;
}
void readfile(const char* filename) {
    int h, kil;
    short k;
    
    ifstream file(filename);
    if (!file.is_open()) { 
        cout << "Error opening file!" << endl; 
        return;
    }

    Price total = {0, 0};
    while (file >> h >> k >> kil) {
        Price p = {h, k};
        Price line_price;
        
        res(p, kil, line_price); 
        
        Price new_total;
        sum(total, line_price, new_total); 
        total = new_total;
    }
    file.close();

    cout << "Total without rounding: " 
        << total.hryvnia << " UAH " << total.kopiyka << " kop" << endl;

    Price rounded;
    round_price(total, rounded);
    
    cout << "Total with rounding: " 
        << rounded.hryvnia << " UAH " << rounded.kopiyka << " kop" << endl;
}

int main() {
    readfile("input.txt");
    return 0;
}