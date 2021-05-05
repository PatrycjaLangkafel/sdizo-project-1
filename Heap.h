#ifndef PROJECT_1_SDIZO_HEAP_H
#define PROJECT_1_SDIZO_HEAP_H

#include <iostream>
#include "Tab.h"

using namespace std;

// Klasa kopca
class Heap{

private:
    int *tab; // wskaznik na poczatek kopca
    int len; // dlugosc kopca
public:
    Heap();
    ~Heap();
    void add(int value);
    void remove();
    int find_elem(int index);
    int find_elem_value(int value);
    void show();
    void heap_fix_up();
    void heap_fix_down(int index);
    int getSize();
};

#endif
