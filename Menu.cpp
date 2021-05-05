#include <iostream>
#include "Menu.h"
#include "DoubleList.h"
#include "Tab.h"
#include "Heap.h"
#include <stdlib.h>
#include <fstream>


using namespace std;

void Menu :: menu(){

    int menu = 9;
    int choice = 0;
    DoubleList list;
    Tab tab;
    Heap heap;
    int data;
    int index;
    int size;
    fstream file_input;

    while(menu!=0){

        file_input.open("10.txt", ios::in);


        if (!file_input.is_open()){
            cout<< "Nie otworzono pliku"<<endl;
            return;
        }

	    cout << "# MENU GLOWNE #" << endl;
	    cout << "1. Lista dwukierunkowa" << endl;
	    cout << "2. Tablica dynamiczna" << endl;
	    cout << "3. Kopiec binarny" << endl;
	    cout << "0. Wyjscie" << endl;
	    cout << "Podaj swoj wybor: ";
	    cin >> menu;

        if (menu==0){
            cout<<"Zamykam!!"<<endl;
            return;
        }

        switch (menu){

        case 1:

            if(file_input.good()==true){

                file_input>>size;
                for (int i = 0; i<size; i++){

                    file_input>>data;
                    list.add_back(data);

                }

            }
            file_input.close();

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
                    break;
                }

                switch (choice)
                {
                case 1:
                    cout<< "Podaj liczbe do wstawienia do listy: ";
                    cin>>data;
                    list.add_front(data);
                    list.show();
                    break;

                case 2:
                    cout<< "Podaj liczbe do wstawienia do listy: ";
                    cin>>data;
                    list.add_back(data);
                    list.show();
                    break;

                case 3:
                    cout<< "Podaj liczbe do wstawienia do listy i jej indeks: ";
                    cin>>data>>index;
                    list.add(index, data);
                    list.show();
                    break;

                case 4:
                    cout<< "Usuwam liczbe z poczatku!!"<<endl;
                    list.delete_front();
                    list.show();
                    break;

                case 5:
                    cout<< "Usuwam liczbe z konca!!"<<endl;
                    list.delete_back();
                    list.show();
                    break;

                case 6:
                    cout<< "Podaj indeks liczby do usuniecia: ";
                    cin>>index;
                    list.remove(index);
                    list.show();
                    break;

                case 7:
                    cout<< "Podaj indeks liczby do znalezienia: ";
                    cin>>index;
                    cout<<"Wartosc pod zadanym indeksem "<<list.find_elem(index)<<endl;
                    break;

                case 8:
                    cout<< "Podaj wartosc elementu do znalezienia: ";
                    cin>>data;
                    cout<<"Wartosc znajduje sie pod indeksem "<<list.find_elem_value(data)<<endl;
                    break;

                case 9:
                    cout<< "Wyswietlam cala liste!!"<<endl;
                    list.show();
                    break;
                }

            } while(choice!=0);
            break;

        case 2:
            if(file_input.good()==true){

                file_input>>size;
                for (int i = 0; i<size; i++){

                    file_input>>data;
                    tab.add_back(data);

                }

            }
            file_input.close();

            do
            {

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
                cout << "9. Wydrukuj liste" << endl;
                cout << "0. Wyjscie" << endl;
                cout << "Podaj swoj wybor: ";
                cin >> choice;

                while (choice > 9)
                {
                    cout<< "Podales zla liczbe. Wybierz ponownie: ";
                    cin >> choice;
                }

                if (choice==0)
                {
                    break;
                }

                switch (choice)
                {

                case 1:
                    cout<< "Podaj liczbe do wstawienia do tablicy: ";
                    cin>>data;
                    tab.add_front(data);
                    tab.show();
                    break;

                case 2:
                    cout<< "Podaj liczbe do wstawienia do tablicy: ";
                    cin>>data;
                    tab.add_back(data);
                    tab.show();
                    break;

                case 3:
                    cout<< "Podaj liczbe do wstawienia do tablicy i jej indeks: ";
                    cin>>data>>index;
                    tab.add(index, data);
                    tab.show();
                    break;

                case 4:
                    cout<< "Usuwam liczbe z poczatku!!"<<endl;
                    tab.delete_front();
                    tab.show();
                    break;

                case 5:
                    cout<< "Usuwam liczbe z konca!!"<<endl;
                    tab.delete_back();
                    tab.show();
                    break;

                case 6:
                    cout<< "Podaj indeks liczby do usuniecia: ";
                    cin>>index;
                    tab.remove(index);
                    tab.show();
                    break;

                case 7:
                    cout<< "Podaj indeks liczby do znalezienia: ";
                    cin>>index;
                    cout<<"Wartosc pod zadanym indeksem "<<tab.find_elem(index)<<endl;
                    break;

                case 8:
                    cout<< "Podaj wartosc elementu do znalezienia: ";
                    cin>>data;
                    cout<<"Wartosc znajduje sie pod indeksem "<<tab.find_elem_value(data)<<endl;
                    break;

                case 9:
                    cout<< "Wyswietlam cala tablice!!"<<endl;
                    tab.show();
                    break;
                }

            }while(choice!=0);
            break;

        case 3:
            if(file_input.good()==true){

                file_input>>size;
                    for (int i = 0; i<size; i++){

                        file_input>>data;
                        heap.add(data);

                    }

            }
            file_input.close();

            do{
                cout << "Wybrales/as KOPIEC BINARNY: " << endl;
                cout << "# MENU #" << endl;
                cout << "1. Dodaj element" << endl;
                cout << "2. Usun element" << endl;
                cout << "3. Wyszukaj element po indeksie" << endl;
                cout << "4. Wyszukaj element po wartosci" << endl;
                cout << "5. Wydrukuj liste" << endl;
                cout << "0. Wyjscie" << endl;
                cout << "Podaj swoj wybor: ";
                cin >> choice;

                while (choice > 5)
                {
                    cout<< "Podales zla liczbe. Wybierz ponownie: ";
                    cin >> choice;
                }

                if (choice==0)
                {
                    break;
                }

                switch (choice)
                {

                case 1:
                    cout<< "Podaj liczbe do wstawienia do kopca: ";
                    cin>>data;
                    heap.add(data);
                    heap.show();
                    break;

                case 2:
                    cout<< "Usuwam liczbe z poczatku kopca!!"<<endl;
                    heap.remove();
                    heap.show();
                    break;

                case 3:
                    cout<< "Podaj indeks liczby do znalezienia: ";
                    cin>>index;
                    cout<<"Wartosc pod zadanym indeksem "<<heap.find_elem(index)<<endl;
                    break;

                case 4:
                    cout<< "Podaj wartosc elementu do znalezienia: ";
                    cin>>data;
                    cout<<"Wartosc znajduje sie pod indeksem "<<heap.find_elem_value(data)<<endl;
                    break;

                case 5:
                    cout<< "Wyswietlam caly kopiec!!"<<endl;
                    heap.show();
                    break;
                }

            }while(choice!=0);
            break;

        default:
            cout<< "Podales zla liczbe."<<endl;
            break;

        }
    }
}


