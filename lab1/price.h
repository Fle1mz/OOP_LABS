#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hryvnia;
    short int kopiyka;
};

    void add(Price& p, Price other);
    void multiply(Price& p, int quantity);
    void roundKopecks(Price& p);
    void print(const Price& p);
#endif