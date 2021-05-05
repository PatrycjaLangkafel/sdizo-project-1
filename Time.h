#ifndef PROJECT_1_SDIZO_TIME_H
#define PROJECT_1_SDIZO_TIME_H

#include <iostream>
#include <windows.h>
#include <iomanip>


using namespace std;

// Klasa do obliczania czasu
class Time{

public:
    long long int start; // wartosc start
    long long int time_end; // wartosc koncowa
    long long int frequency;
    long long int count_; 

    Time();
    long long int time();
    long long int count();

};

#endif  