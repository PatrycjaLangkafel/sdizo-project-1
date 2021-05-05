#include <iostream>
#include <fstream>
#include "Time.h"
#include "Test.h"
#include "Tab.h"
#include "DoubleList.h"
#include "Heap.h"
#include <string>
#include <ctime>
#include <chrono>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>

using namespace std;


// funkcja testujaca liste dwukierunkowa
void Test :: list_test(){

    int choice;
    int data;
    int number;
    int index;
    DoubleList list;
    Time t;
    fstream file_input;
    fstream file_output;
    string nazwa_pliku;
    const int max = 1000;
    const int min = -1000;
    QueryPerformanceFrequency((LARGE_INTEGER *)&t.frequency);
    cout<< "Podaj nazwe pliku z liczbami: ";
    cin>> nazwa_pliku;

    cout<< "Podaj ile razy petla testow bedzie sie wykonywac: ";
    cin>> number;

    file_output.open("wyniki.txt", ios::out | ios::app);


    if (!file_output.is_open()){
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }


    do{
        cout << "Wybrales/as LISTE DWUKIERUNKOWA: " << endl;
	    cout << "# MENU #" << endl;
	    cout << "1. Dodaj na poczatek" << endl;
        cout << "2. Dodaj na koniec" << endl;
        cout << "3. Dodaj w okreslone miejsce" << endl;
        cout << "4. Usun pierwszy element" << endl;
        cout << "5. Usun ostatni element" << endl;
        cout << "6. Usun element pod zadanym indeksem" << endl;
        cout << "7. Wyszukaj element po indeksie" << endl;
        cout << "8. Wyszukaj element po wartosci" << endl;
        cout << "9. Wydrukuj liste" << endl;
        cout << "0. Wyjscie" << endl;
	    cout << "Podaj swoj wybor: ";
	    cin >> choice;

        while (choice > 9){
            cout<< "Podales zla liczbe. Wybierz ponownie: ";
            cin >> choice;
        }

        if (choice==0){

            file_output.close();
            return;
        }


        switch (choice){

        case 1:
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            t.count_ = 0;
            cout<< "Rozpaczynam testy metody dodawania na poczatek..."<<endl;
            file_output<<"Lista: czasy dla metody add_front: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){
                    file_input>>data;
                    t.start = t.time();
                    list.add_front(data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }
            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;

        case 2:
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            t.count_ = 0;
            cout<< "Rozpaczynam testy metody dodawania na koniec..."<<endl;
            file_output<<"Lista: czasy dla metody add_back: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){

                    file_input>>data;
                    t.start = t.time();
                    list.add_back(data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;


        case 3:
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            t.count_ =0;
            cout<< "Rozpaczynam testy metody dodawania na okreslone miejsce..."<<endl;
            file_output<<"Lista: czasy dla metody add: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){
                    file_input>>data;
                    t.start = t.time();
                    list.add(rand()% list.getSize(), data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;

        case 4:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania z poczatku..."<<endl;
            file_output<<"Lista: czasy dla metody delete_front: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                list.delete_front();
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 5:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania z konca..."<<endl;
            file_output<<"Lista: czasy dla metody delete_back: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                list.delete_back();
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 6:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania z okreslonego miejsca..."<<endl;
            file_output<<"Lista: czasy dla metody remove: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                list.remove(rand()% list.getSize());
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 7:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody znajdowania po indeksie..."<<endl;
            file_output<<"Lista: czasy dla metody find_elem: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                list.find_elem(rand() % list.getSize());
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 8:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody znajdowania po wartosci..."<<endl;
            file_output<<"Lista: czasy dla metody find_elem_value: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                list.find_elem_value(rand() %(( max - min )+ min));
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 9:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody wyswietlania..."<<endl;
            file_output<<"Lista: czasy dla metody show: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                list.show();
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        }

    }while (choice != 0);

}

// funkcja testujaca tablice dynamiczna
void Test :: tab_test(){

    int choice;
    int data;
    int number;
    Tab tab;
    Time t;
    fstream file_input;
    fstream file_output;
    string nazwa_pliku;
    const int max = 1000;
    const int min = -1000;
    QueryPerformanceFrequency((LARGE_INTEGER *)&t.frequency);

    cout<< "Podaj nazwe pliku z liczbami: ";
    cin>> nazwa_pliku;

    cout<< "Podaj ile razy petla testow bedzie sie wykonywac: ";
    cin>> number;

    file_output.open("wyniki.txt", ios::out | ios::app);

    if (!file_output.is_open()){
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }


    do{
        cout << "Wybrales/as TABLICE DYNAMICZNA: " << endl;
	    cout << "# MENU #" << endl;
	    cout << "1. Dodaj na poczatek" << endl;
        cout << "2. Dodaj na koniec" << endl;
        cout << "3. Dodaj w okreslone miejsce" << endl;
        cout << "4. Usun pierwszy element" << endl;
        cout << "5. Usun ostatni element" << endl;
        cout << "6. Usun element pod zadanym indeksem" << endl;
        cout << "7. Wyszukaj element po indeksie" << endl;
        cout << "8. Wyszukaj element po wartosci" << endl;
        cout << "9. Wydrukuj tablice" << endl;
        cout << "0. Wyjscie" << endl;
	    cout << "Podaj swoj wybor: ";
	    cin >> choice;

        while (choice > 9){
            cout<< "Podales zla liczbe. Wybierz ponownie: ";
            cin >> choice;
        }

        if (choice==0){

            file_output.close();
            return;
        }


        switch (choice){

        case 1:
            t.count_ = 0;
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            cout<< "Rozpaczynam testy metody dodawania na poczatek..."<<endl;
            file_output<<"Tablica: czasy dla metody add_front: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){
                    file_input>>data;
                    t.start = t.time();
                    tab.add_front(data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;


        case 2:
            t.count_ = 0;
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            cout<< "Rozpaczynam testy metody dodawania na koniec..."<<endl;
            file_output<<"Tablica: czasy dla metody add_back: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){
                    file_input>>data;
                    t.start = t.time();
                    tab.add_back(data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;


        case 3:
            t.count_ = 0;
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            cout<< "Rozpaczynam testy metody dodawania na okreslone miejsce..."<<endl;
            file_output<<"Tablica: czasy dla metody add: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){
                    file_input>>data;
                    t.start = t.time();
                    tab.add(rand() % tab.getSize(), data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;

        case 4:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania z poczatku..."<<endl;
            file_output<<"Tablica: czasy dla metody delete_front: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                tab.delete_front();
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 5:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania z konca..."<<endl;
            file_output<<"Tablica: czasy dla metody delete_back: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                tab.delete_back();
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 6:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania z okreslonego miejsca..."<<endl;
            file_output<<"Tablica: czasy dla metody remove: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                tab.remove(rand()% tab.getSize());
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 7:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody znajdowania po indeksie..."<<endl;
            file_output<<"Tablica: czasy dla metody find_elem: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                tab.find_elem(rand() % tab.getSize());
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 8:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody znajdowania po wartosci..."<<endl;
            file_output<<"Tablica: czasy dla metody find_elem_value: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                tab.find_elem_value(rand() %(( max - min )+ min));
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 9:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody wyswietlania..."<<endl;
            file_output<<"Tablica: czasy dla metody show: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                tab.show();
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        }

    }while (choice != 0);
}

// funkcja testujaca kopiec binarny
void Test :: heap_test(){

    int choice;
    int data;
    int number;
    Heap heap;
    Time t;
    fstream file_input;
    fstream file_output;
    string nazwa_pliku;
    const int max = 1000;
    const int min = -1000;
    QueryPerformanceFrequency((LARGE_INTEGER *)&t.frequency);

    cout<< "Podaj nazwe pliku z liczbami: ";
    cin>> nazwa_pliku;

    cout<< "Podaj ile razy petla testow bedzie sie wykonywac: ";
    cin>> number;

    file_output.open("wyniki.txt", ios::out | ios::app);

    if (!file_output.is_open()){
        cout<< "Nie otworzono pliku zapisowego. Zakonczenie testow"<<endl;
        return;
    }

    do{
        cout << "Wybrales/as KOPIEC BINARNY: " << endl;
	    cout << "# MENU #" << endl;
	    cout << "1. Dodaj element" << endl;
        cout << "2. Usun element" << endl;
        cout << "3. Wyszukaj element po indeksie" << endl;
        cout << "4. Wyszukaj element po wartosci" << endl;
        cout << "5. Wydrukuj kopiec" << endl;
        cout << "0. Wyjscie" << endl;
	    cout << "Podaj swoj wybor: ";
	    cin >> choice;

        while (choice > 5){
            cout<< "Podales zla liczbe. Wybierz ponownie: ";
            cin >> choice;
        }

        if (choice==0){

            file_output.close();
            return;
        }


        switch (choice){
        case 1:
            t.count_ = 0;
            file_input.open(nazwa_pliku.c_str(), ios::in);

            if (!file_input.is_open()){
                cout<< "Nie otworzono pliku z danymi. Zakonczenie testow"<<endl;
                return;
            }

            cout<< "Rozpaczynam testy metody dodawania ..."<<endl;
            file_output<<"Kopiec: czasy dla metody add: ";
            file_output<<"dla liczb " << number<< " : ";

            if(file_input.good()==true){

                for (int i = 0; i<number; i++){
                    file_input>>data;
                    t.start = t.time();
                    heap.add(data);
                    t.time_end = t.time() - t.start;
                    t.count();

                }

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            file_input.close();
            break;

        case 2:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody usuwania ..."<<endl;
            file_output<<"Kopiec: czasy dla metody remove: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<1; i++){

                t.start = t.time();
                heap.remove();
                t.time_end = t.time() - t.start;
                t.count();
            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 3:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody znajdowania po indeksie..."<<endl;
            file_output<<"Kopiec: czasy dla metody find_elem: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                heap.find_elem(rand() % heap.getSize());
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 4:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody znajdowania po wartosci..."<<endl;
            file_output<<"Kopiec: czasy dla metody find_elem_value: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<number; i++){

                t.start = t.time();
                heap.find_elem_value(rand() %(( max - min )+ min));
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        case 5:
            t.count_ = 0;
            cout<< "Rozpaczynam testy metody wyswietlania..."<<endl;
            file_output<<"Kopiec: czasy dla metody show: ";
            file_output<<"dla liczb " << number<< " : ";

            for (int i = 0; i<1; i++){

                t.start = t.time();
                heap.show();
                t.time_end = t.time() - t.start;
                t.count();

            }

            file_output<<setprecision(6)<<(1000.0*t.count())/t.frequency;
            file_output<<endl;
            cout<< "Koniec..."<<endl;
            break;

        }

    }while (choice != 0);
}

