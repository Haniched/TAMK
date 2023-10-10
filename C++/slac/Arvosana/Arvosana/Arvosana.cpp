//
//  main.cpp
//  Arvosana
//
//  Created by Heejeong Han on 10.10.2023.
//

#include <iostream>

int main() {
    int kpl { 0 };    // arvosanojen lukumäärä
    int summa { 0 };  // arvosanojen summa
    
    while (kpl < 5) {
        std::cout << "Anna arvosana (0-5): ";
        int arvosana;
        std::cin >> arvosana;

        kpl = kpl + 1;
        summa = summa + arvosana;

        std::cout << "Arvosanoja syotetty: " << kpl << ", summa = " << summa << "\n";
    }
    
    float keskiarvo = summa / float(kpl);
    std::cout << "Keskiarvo = " << keskiarvo << "\n";
}
