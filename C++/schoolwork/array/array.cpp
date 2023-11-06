// array (taulukko) tunninmalli

#include <iostream>
#include <array> // otetann mukaan std::array

int main (){
    std::array <int, 8> luvut;

    // Alustetaan taulukon luvut nolliksi
    for (size_t i {0}; i < luvut.size(); i++){ 
        luvut[i] = 0; // aseta alkion indeksillä i arvoksi 0
    }

    for (size_t i {0}; i < luvut.size(); i++){
        std::cout << luvut [i] << ' ';
    }

     for (size_t i {0}; i < luvut.size(); i++){
        std::cout << luvut.at(i) << ' '; // 
    }
    std::cout << "\n";
}

