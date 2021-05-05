#ifndef PROJECT_1_SDIZO_LIST_H
#define PROJECT_1_SDIZO_LIST_H

// Klasa zawierajaca element listy
class List {

public:
    List *next; // wskaznik na nastepny element
    List *prev; // wskaznik na poprzedni element
    int data; // wartosc w tablicy

    // Konstruktor 
    List(int data, List * next, List * prev);
};

#endif
