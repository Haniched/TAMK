#include <iostream>

int main() {
    int pisteet { 0 };
    std::cout << "Anna pistemaara: ";
    std::cin >> pisteet;

    int arvosana { 0 };
    if (pisteet > 42) {
        arvosana = 5;
    }
    else if (pisteet > 36) {
        arvosana = 4;
    }
    else if (pisteet > 30) {
        arvosana = 3;
    }
    else if (pisteet > 24) {
        arvosana = 2;
    }
    else if (pisteet > 16) {
        arvosana = 1;
    }

    std::cout << "Arvosana: " << arvosana << "\n";
}
