#include <iostream>
#include "Tab.h"

using namespace std;


// przypisanie wartoci poczatkowych
Tab :: Tab(){
    len = 0;
    head = NULL;
}

// destruktor
Tab :: ~Tab(){
    delete[] head;
}

// funkcja dodajaca element tablicy na poczatek
void Tab :: add_back(int value){

    int *tab;

    if(len == 0){
        add_front(value);
    }
    else{

        tab = new int [len+1];

        for (int i = 0; i < len; i++) {
            tab[i] = head[i];
        }

        tab [len] = value;

        delete head;
        head = tab;
        len++;

    }

}

// funkcja dodajaca element tablicy na koniec
void Tab :: add_front(int value){

    int *tab;

    if(len == 0){
        head = new int [1];
        *head = value;
    }
    else{

        tab = new int [len+1];
        tab [0] = value;

        for (int i = 1; i <= len; i++) {
            tab[i] = head[i-1];
        }

        delete head;
        head = tab;

    }

    len++;
}

// funkcja dodajaca element tablicy na okreslonej pozycji
void Tab :: add(int index, int value){

    if (index < 0 || index>len ){
        cout<<"Nie istnieje taki index w tablicy!!"<<endl;
        return;
    }

    if (index ==0){
        add_front(value);
        return;
    }
    else if (index == len-1){
        add_back(value);
        return;
    }


    int *tab;

    if(len == 0){
        add_front(value);
        return;
    }
    else{

        tab = new int [len+1];
        tab [index] = value;

        for (int i = 0; i < len; i++) {

            if (i<index){
                tab[i] = head[i];
            }
            else if (i >=index){
                tab[i+1] = head[i];
            }

        }

        delete head;
        head = tab;
        len++;

    }

}

// funkcja usuwajaca element tablicy z konca
void Tab :: delete_back(){

    int *tab;

    if (len == 1){
        delete head;
        head = NULL;
    }
    else if (len == 0){
        cout<< "Nie ma elementu do usuniecia!!"<<endl;
        return;
    }
    else{

        tab = new int [len-1];

        for (int i = 0; i < len -1; i++) {
            tab[i] = head[i];
        }

        delete[] head;
        head = tab;

    }

    len--;
}

// funkcja usuwajaca element tablicy z poczatku
void Tab :: delete_front(){

    int *tab;

    if (len == 1){
        delete head;
        head = NULL;
    }
    else if (len == 0){
        cout<< "Nie ma elementu do usuniecia!!"<<endl;
        return;
    }
    else{

        tab = new int [len-1];

        for (int i = 0; i < len -1; i++) {
            tab[i] = head[i+1];
        }

        delete[] head;
        head = tab;

    }

    len--;
}

// funkcja usuwajaca element tablicy z okreslonej pozycji
void Tab :: remove(int index){


    if (index < 0 || index>=len ){
        cout<<"Nie istnieje taki index w tablicy!!"<<endl;
        return;
    }

    if (index ==0){
        delete_front();
        return;
    }
    else if (index == len-1){
        delete_back();
        return;
    }


    int *tab;

    if(len == 0){
        cout<< "Nie ma elementu do usuniecia!!"<<endl;
        return;
    }
    else{

        tab = new int [len-1];

        for (int i = 0; i < len - 1; i++) {

            if (i<index){
                tab[i] = head[i];
            }
            else if (i >=index){
                tab[i] = head[i+1];
            }

        }

        delete[] head;
        head = tab;

    }

    len--;
}

// funkcja zwracajaca wartosc z tablicy na podstawie indeksu
int Tab :: find_elem(int index){

    if (index < 0 || index >= len){
        cout<< "Nie ma takiego indeksu!!"<<endl;
    }

    for (int i = 0; i<len; i++){

        if (i==index){
            return *(head + i);
        }
    }

    return -2;
}

// funkcja zwracajaca index z tablicy na podstawie wartosci elementu
int Tab :: find_elem_value(int value){

    for (int i = 0; i<len; i++){

        if (*(head + i) == value){
            return i;
        }
    }

    return -2;
}

// funkcja wyswietlajaca wszystkie elementy tablicy
void Tab :: show(){

    if (head != NULL) {
        for (int i = 0; i < len; i++) {
            cout << head[i] << " [" << i << "] " << " , ";
        }
    }
    else {
        cout << "Tablica nie ma elementow !!" << endl;
    }
    cout<<endl;
}

// funkcja zwracajaca rozmiar tablicy
int Tab :: getSize(){
    return len;
}
