#include <iostream>
#include <windows.h>
#include <iomanip>
#include "Time.h"


using namespace std;


//konstruktor
Time :: Time(){
    count_ = 0;
}

// funkcja okreslajaca czas wykonania
long long int Time :: time(){

    LARGE_INTEGER count;   
    QueryPerformanceCounter(&count); 
    return ((long long int)count.QuadPart);

}

// funkcja zliczajaca wszystkie czasy wykonania
long long int Time :: count(){

    count_ += time_end;
    return (long long int) count_;
}
