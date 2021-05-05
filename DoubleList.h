#ifndef PROJECT_1_SDIZO_DOUBLELIST_H
#define PROJECT_1_SDIZO_DOUBLELIST_H

#include <iostream>
#include "List.h"

using namespace std;

// Klasa listy dwukierunkowej
class DoubleList{

private:
    int size; // wielkosc listy
    List *tail; // wskaznik na koniec listy
    List *head; // wskaznik na poczatek listy
                                         
public:
    DoubleList();
    ~DoubleList();
    void add_back(int value);
    void add_front(int value);
    void add(int index, int value);
    void delete_back();
    void delete_front();
    void remove(int index);
    int find_elem(int index);
    int find_elem_value(int value);
    void show();
    List * move_elem(int index);
    int getSize();

};

#endif
