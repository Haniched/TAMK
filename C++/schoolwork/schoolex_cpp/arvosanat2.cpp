#include <iostream>

int main() {
    int kpl { 0 };    // arvosanojen lukumäärä
    int summa { 0 };  // arvosanojen summa
    
    std::cout << "Anna arvosana (0-5, lopetus = -1): ";
    int arvosana;
    std::cin >> arvosana;
    
    while (arvosana != -1) {
        kpl = kpl + 1;
        summa = summa + arvosana;

        std::cout << "Arvosanoja syotetty: " << kpl << ", summa = " << summa << "\n";

        std::cout << "Anna arvosana (0-5, lopetus = -1): ";
        std::cin >> arvosana;        
    }
    
    if (kpl != 0) {  // ei saa jakaa nollalla!
        float keskiarvo = summa / float(kpl);
        std::cout << "Keskiarvo = " << keskiarvo << "\n";
    }
}
