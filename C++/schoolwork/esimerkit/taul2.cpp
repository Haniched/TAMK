#include <iostream>
#include <array>  // otetaan mukaan std::array

int main() {
    // Alustetaan taulukko halutuilla luvuilla:
    std::array<int, 8> luvut { 32, 27, 64, 18, 95, 53, 12, 9 };
    
    for (size_t i{0}; i < luvut.size(); i++) {
        std::cout << luvut.at(i) << ' ';
    }
    std::cout << '\n';

    int summa{0};  // taulukon alkioiden summa

    // C++11: "range-based for", const-viitteellä
    for (const int& luku : luvut) {
        std::cout << luku << ' ';
        summa += luku;
    }
    std::cout << '\n';
    std::cout << "summa = " << summa << '\n';

    // C++11: "range-based for", tavallinen viite
    for (int& luku : luvut) {
        luku *= 2;
        std::cout << luku << ' ';
    }
    std::cout << '\n';
}
