#include "price.h"
#include <iostream>
#include <iomanip>

void Price::add(Price other) {
    this->hryvnia += other.hryvnia;
    this->kopiyka += other.kopiyka;
    
    if (this->kopiyka >= 100) {
        this->hryvnia += this->kopiyka / 100;
        this->kopiyka %= 100;
    }
}

void Price::multiply(int quantity) {
    long totalKopecks = (long)(this->hryvnia * 100 + this->kopiyka) * quantity;
    this->hryvnia = totalKopecks / 100;
    this->kopiyka = totalKopecks % 100;
}

void Price::roundKopecks() {
    // Правило НБУ: 
    // 1-4 копійки -> 0
    // 5-9 копійок -> 10
    int lastDigit = this->kopiyka % 10;
    if (lastDigit >= 5) {
        this->kopiyka += (10 - lastDigit);
    } else {
        this->kopiyka -= lastDigit;
    }

    // Якщо після заокруглення вийшло 100 копійок
    if (this->kopiyka == 100) {
        this->hryvnia += 1;
        this->kopiyka = 0;
    }
}

void Price::print() const {
    std::cout << hryvnia << " UAH " << std::setw(2) << std::setfill('0') << kopiyka << " kop";
}