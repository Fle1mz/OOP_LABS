#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hryvnia;
    short int kopiyka;

    void add(Price other);
    void multiply(int quantity);
    void roundKopecks();
    void print() const;
};

#endif