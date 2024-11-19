#include <iostream>

int main() {

    // Muistivuoto
    #if 0
    int* p = new int(42);
    p = nullptr;
    #endif

    // Alustamattoman osoittimen osoittamaan satunnaiseen muistipaikkaan viedaan arvo
    #if 0 
        int* uninitializedPtr;
        *uninitializedPtr = 10;
    #endif

    // NULL-osoitteeseen yritetaan vieda arvo
    #if 0
        int* nullPtr = nullptr;
        *nullval = 678;
    #endif

    // Aliohjelman muistivuoto
    #if 0
        auto allocateMemory = []() {
        allocateMemory();
            int* localPrt = new int(21);
        };
    #endif
    
    // Stattinen taulukko
    #if 0
        int array [10];
        array [20] = 50;
    #endif

    // Dynaaminen taulukko
    #if 0
        int* dynamicArray = new int[10]; // assign dynamic array
        dynamicArray[20] = 60; // error value
        delete[] dynamicArray; // disable array
    #endif

    return 0;
}