#include <iostream>
#include "Heap.h"

using namespace std;

// konstruktor
Heap :: Heap(){
    len = 0;
    tab = NULL;
}

// destruktor
Heap :: ~Heap(){
    delete[] tab;
}

// funkcja dodajaca element kopca na koniec
void Heap :: add(int value){

    int *elem;

    if(len == 0){
        tab = new int [1];
        *tab = value;
    }
    else{

        elem = new int [len+1];

        for (int i = 0; i < len; i++) {
            elem[i] = tab[i];
        }

        elem [len] = value;

        delete tab;
        tab = elem;

    }

    len++;
    heap_fix_up();


}

// funkcja usuwajaca element kopca z poczatku
void Heap :: remove(){

    int *elem;

    if (len == 0){
        cout<< "Nie ma elementu do usuniecia!!"<<endl;
        return;
    }
    else if(len == 1){
        delete tab;
        tab = NULL;

    }else{

        elem = new int [getSize()-1];

        for (int i = 0; i < getSize() -1; i++) {
            elem[i+1] = tab[i+1];
        }
        elem[0] = tab[getSize()-1];

        delete tab;
        tab = elem;
    }

    len--;

	heap_fix_down(0);
}

// funkcja zwracajaca wartosc z tablicy na podstawie indeksu
int Heap :: find_elem(int index){

    if (index < 0 || index > len){
        cout<< "Nie ma takiego indeksu!!"<<endl;
    }

    for (int i = 0; i<len; i++){

        if (i==index){
            return *(tab + i);
        }
    }

    return -2;
}

// funkcja zwracajaca index z tablicy na podstawie wartosci elementu
int Heap :: find_elem_value(int value){

    for (int i = 0; i<len; i++){

        if (*(tab + i) == value){
            return i;
        }
    }

    return -2;
}

// funkcja wyswietlajaca kopiec
void Heap :: show(){

    if (tab != NULL) {
        for (int i = 0; i < len; i++) {
            cout << tab[i]<< " [" << i << "] "<< " , ";
        }
    }else {
        cout << "Kopiec nie ma elementow !!" << endl;
    }
    cout<<endl;
}

// funkcja naprawiajaca kopiec w gore
void Heap :: heap_fix_up(){

    int index = getSize() -1;
    int parent = (index-1)/2;

    while(find_elem(parent) < find_elem(index)){

        int data = find_elem(index);

        tab[index] = find_elem(parent);
        tab[parent] = data;

		index = parent;

		parent = (index - 1) / 2;
    }

}

// funkcja naprawiajaca kopiec w dol
void Heap :: heap_fix_down(int index){

    int r = 2*index +2;
    int l = 2*index +1;

    while(r<len){

        int i;
        if(find_elem(l) < find_elem(r)){
            i = r;
        }else{
            i = l;
        }

        if(find_elem(index) >= find_elem(i)){
            return;
        }

        int data = find_elem(index);

        tab[index] = find_elem(i);
        tab[i] = data;

		index = i;

        r = 2*index +2;
        l = 2*index +1;
    }

}

// funkcja zwracajaca rozmiar kopca
int Heap :: getSize(){
    return len;
}
