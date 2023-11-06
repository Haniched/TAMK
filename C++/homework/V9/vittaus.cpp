// V9_4

#include <iostream>

int asetalka (int& ika){ // & merkki on reference parameter
    std::cout << "kerro ikasi: ";
    std::cin >> ika;
    return ika;
}

int main (){
    int ika;
    asetalka (ika);
    std::cout << "ikasi on: " << ika << std::endl;
}