//
//  main.cpp
//  String
//
//  Created by Heejeong Han on 10.10.2023.
//

#include <iostream>
#include <string>

int main ()
{
    std::string nimi; // alustaa tyhjän merkkijonon
    
    std::cout << "Anna nimesi:";
    std::cin >> nimi; // lukee näppäimistöltä muuttujaan
    
    if (nimi.empty()) {
        std::cout << "Hmm, olet siis nimetön?\n";
    }
    else {
        std::cout << "Moro, " << nimi << "! Miten Menee?\n";
        std::cout << "Nimesi on muuten " << nimi.size() << "-merkkinen. \n";
        }

}
