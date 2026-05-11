#include "price.h"
#include <iostream>
#include <iomanip>

void sum(Price a, Price b, Price &c) {
    c.hryvnia = a.hryvnia + b.hryvnia;
    c.kopiyka = a.kopiyka + b.kopiyka;

    if (c.kopiyka >= 100) {
        c.hryvnia += c.kopiyka / 100;
        c.kopiyka %= 100;
    }
}

void res(Price p, int kil, Price &result) {
    long totalKopecks = (long)(p.hryvnia * 100 + p.kopiyka) * kil;
    result.hryvnia = totalKopecks / 100;
    result.kopiyka = totalKopecks % 100;
}

void round_price(Price p, Price &r) {
    int money = p.hryvnia * 100 + p.kopiyka;
    int lastDigit = money % 10;

    if (lastDigit >= 5) {
        money += (10 - lastDigit);
    } else {
        money -= lastDigit;
    }

    r.hryvnia = money / 100;
    r.kopiyka = money % 100;
}

void print(const Price& p) {
    std::cout << p.hryvnia << " UAH " << std::setw(2) << std::setfill('0') << p.kopiyka << " kop";
}