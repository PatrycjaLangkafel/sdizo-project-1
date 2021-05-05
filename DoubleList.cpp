#include <iostream>
#include "DoubleList.h"

using namespace std;

// konstruktor listy dwukierunkowej
DoubleList :: DoubleList(){

    size = 0;
    head = NULL;
    tail = NULL;
}

// destruktor listy
DoubleList :: ~DoubleList(){

    List *elem;

    // usuwanie elementow po kolei
	while (head != NULL)
	{
		elem = head->next;
		delete head;
		head = elem;
	}
	size = 0;
}

// funkcja dodajaca element do listy na koniec
void DoubleList :: add_back(int value){

    // nowy element tablicy
    List *p = new List(0, NULL, NULL);
    p->data = value;

    if (head == NULL){
        tail = p;
        head = tail;
    }
    else{
        p -> prev = tail;
        tail = p;
        p->prev -> next = p;
    }

    size++;
}

// funkcja dodajaca element do listy na poczatek
void DoubleList :: add_front(int value){

    // nowy element tablicy
    List *p = new List(0, NULL, NULL);
    p->data = value;

    if (head == NULL){
        head = p;
        tail = head;
    }
    else{
        p -> next = head;
        head = p;
        p->next -> prev = p;
    }

    size++;
}

// funkcja dodajaca element do listy w okreslonym miejscu
void DoubleList :: add(int index, int value){

    if (index == 0){
        add_front(value);
        return;
    }else if (index==size){
        add_back(value);
        return;
    }

    if (index < 0 || index > size){
        cout<< "Nie ma takiego indeksu na liscie!!"<<endl;
        return;
    }

    List *elem = move_elem(index);

    List *p = new List(0, NULL, NULL);

    p->data = value;
    p->next = elem;
    p->prev = elem->prev;

    size ++;
    elem->prev->next = p;
	elem->prev = p;

 }

// funkcja usuwajaca element z listy z poczatku
void DoubleList :: delete_front(){

    if (size == 0){
        return;
    }

    if (size == 1){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    else{
        List *p = head;
        head = head->next;
        head->prev = NULL;

        delete p;
        size--;
    }

}

// funkcja usuwajaca element z listy z konca
void DoubleList :: delete_back(){

    if (size == 0){
        return;
    }

    if (size == 1){
        delete_front();
        return;
    }
    else{
        List *p = tail;
        tail = tail-> prev;
        tail->next = NULL;
        delete p;
        size--;
    }

}

// funkcja usuwajaca element z listy z okreslonego miejsca
void DoubleList :: remove(int index){

    if (size == 0){
        return;
    }

    if (index == 0){
        delete_front();
        return;
    }
    else if (index == (size - 1)){
        delete_back();
        return;
    }

    if (index < 0 || index >= size){
        cout<< "Nie ma takiego indeksu na liscie!!"<<endl;
        return;
    }

    List *elem = move_elem(index);

    if (elem->prev != NULL){
        elem->prev->next = elem->next;
    }
    else{
        head = elem-> next;
    }

    if (elem->next != NULL){
        elem->next->prev = elem->prev;
    }
	else{
        tail = elem->prev;
    }

    delete elem;
    size --;
}

// Funkcja zwracajaca wartosc elementu listy po jego indeksie
int DoubleList :: find_elem(int index){

    if (index < 0 || index >= size){
        cout<< "Nie ma takiego indeksu w liscie!!"<<endl;
        return 0;
    }

    List *elem;

    if (index <= size/ 2 ) {

        elem = head;

        for (int i = 0; i < index; i++) {
            elem = elem->next;
        }

    } else {

        elem = tail;

        for (int i = size - 1; i != index; i--) {
            elem = elem->prev;
        }
    }

    return elem->data;
}

// Funkcja zwracajaca indeks elementu listy po jego wartosci
int DoubleList :: find_elem_value(int value){

    List *elem;

    elem = head;

    for (int i = 0; i < size; i++) {

        if (elem->data == value){
            return i;
        }
        else{
            elem = elem->next;
        }
	}

    return -2;
}

// funkcja wyswietlajaca cala liste
void DoubleList :: show(){

    List *elem;

    elem = head;
    for (int i = 0; i < size; i++) {
        cout<<elem->data<<" ";
        elem = elem ->next;

    }
    cout<<endl;
}

// funkcja przesuwajaca elementy listy i zwracajaca wskaznik na miejsce
// gdzie wstawiamy lub usuwamy element
List * DoubleList :: move_elem(int index){

    List *elem;

    if (index < (size-1)/ 2 ) {

        elem = head;

        for (int i = 0; i < index; i++) {
            elem = elem->next;
        }

    } else {

        elem = tail;

        for (int i = 0; i < size- index-1; i++) {
            elem = elem->prev;
        }
    }

    return elem;
}

// funkcja zwracajaca rozmiar listy
int DoubleList :: getSize(){
    return size;
}
