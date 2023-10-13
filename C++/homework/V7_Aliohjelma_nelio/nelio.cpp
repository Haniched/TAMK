//
//  nelio.cpp
//  V7_Aliohjelma_nelio
//
//  Created by Heejeong Han on 12.10.2023.
//

#include <iostream>
#include <cmath>

//create a function
void Nelio (){
    
    int luku ( 0 );
    std::cout << "Anna luku, jonka nelio lasketaan: ";
    std::cin >> luku;
    
    int p = 2;
    int nelio = pow(luku,p);         // pow (n,p) = power function (value, powervalue)

    std::cout << "Luvun nelio on: " << nelio;
}

int main (){
    Nelio();
    return 0;
}