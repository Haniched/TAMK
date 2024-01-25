//
//  nelio.cpp
//  V7_1_nelio
//
//  Created by Heejeong Han on 12.10.2023.

#include <iostream>
#include <cmath>
using namespace std;

//create a function
int Nelio (int p, int luku){
    cout << "Luvun nelio on: " << pow(luku,p);                       // pow (n,p) = power function (value, powervalue)
    return 0;
}

int main (){
    int luku;
    cout << "Anna luku, jonka nelio lasketaan: ";
    cin >> luku;

    Nelio(2,luku);
    return 0;
}   