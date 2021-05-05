#include <iostream>
#include "NumberGenerator.h"
#include "Test.h"
#include "Menu.h"
#include <stdlib.h>

using namespace std;

int main(){

	int menu;
    char choice;
    NumberGenerator *generator = new NumberGenerator();

    generator->generate();

    Test test;

    cout<<"Chcesz sprawdzic jak dzialaja struktury? Podaj [y/n] : ";
    cin>>choice;

    if (choice == 'y'){
        Menu m;
        m.menu();
    }


	do{
        cout<< "Do testow"<<endl;
	    cout << "# MENU GLOWNE #" << endl;
	    cout << "1. Lista dwukierunkowa" << endl;
	    cout << "2. Tablica dynamiczna" << endl;
	    cout << "3. Kopiec binarny" << endl;
	    cout << "0. Wyjscie" << endl;
	    cout << "Podaj swoj wybor: ";
	    cin >> menu;

        switch (menu){
            
        case 1:
            test.list_test();
            break;

        case 2:
            test.tab_test();
            break;

        case 3:
            test.heap_test();
            break;

        case 0:
            exit(0);

        default:
            cout<< "Podales zla liczbe."<<endl;
            break;   
        }
    }while(menu!=0);

	return 0;
}