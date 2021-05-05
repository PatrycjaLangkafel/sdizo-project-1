#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "NumberGenerator.h"


using namespace std;

// funkcja generujaca losowe wartosci do pliku z konkretna nazwa
void NumberGenerator :: generate(){

    const int max = 1000;
    const int min = -1000;
    int size = 0;

    string nazwa_pliku;
    fstream file_output;
    int number;
    char choice;


    cout<<"Chcesz wygenerewac jakis plik z danymi? Podaj [y/n] : ";
    cin>>choice;

    if (choice == 'n'){
        return;
    }else if (choice == 'y'){
        cout<<"Zaczynamy funkcje generujaca"<<endl;
    }


    cout<< "Podaj jaka ilosc liczb chcesz wygenerowac: ";
    cin>>size;

    cout<< "Podaj nazwe pliku do ktorego mam zapisac wygenerowane liczby: ";
    cin>> nazwa_pliku;

    file_output.open(nazwa_pliku.c_str(), fstream::out | fstream::app);

    if (!file_output.is_open()){
        cout<< "Nie otworzono pliku zapisowego";
        return;
    }

    for (int i = 1; i<=size; i++){

        if (i==size){
            number = 0;
        }else{
            number = rand() %(( max - min )+ min);
        }

        file_output<<number<<endl;

    }

    cout<< "Liczby zostaly zapisane do pliku"<<endl;
    file_output.close();
}