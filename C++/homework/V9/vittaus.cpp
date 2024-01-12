// V9_4

#include <iostream>
// & merkki on reference parameter
int asetalka (int& ika){ 
    std::cout << "kerro ikasi: ";
    std::cin >> ika;
    return ika;
}

int main (){
    int ika;
    asetalka (ika);
    std::cout << "ikasi on: " << ika << std::endl;
}