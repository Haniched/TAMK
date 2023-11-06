#include <iostream>

int main() {
    int laskuri { 5 };
    
    while (laskuri >= 1) {
        std::cout << laskuri << "... ";
        laskuri = laskuri - 1;
    }
    
    std::cout << "LIFTOFF!!!\n";
}
