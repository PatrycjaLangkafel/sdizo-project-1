#ifndef PROJECT_1_SDIZO_TAB_H
#define PROJECT_1_SDIZO_TAB_H

#include <iostream>

using namespace std;

// Klasa tablicy dynamicznej
class Tab{

private:
    int *head; // wskaznik na poczatek tablicy
    int len; // dlugosc tablicy
public:
    Tab();
    ~Tab();
    void add_back(int value);
    void add_front(int value);
    void add(int index, int value);
    void delete_back();
    void delete_front();
    void remove(int index);
    int find_elem(int index);
    int find_elem_value(int value);
    void show();
    int getSize();
};

#endif