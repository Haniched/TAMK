// V9_2 Sademäärä

#include <iostream>

void rivi (){
    std::cout << "\n";
}

void tulostatahti (int sademaara){
    for (int tahti = 0; tahti < sademaara; tahti++) {
        std::cout << "*";
    }
}

int main (){
    int sademaara[12];
   
    for (int kuu = 0; kuu < 12; kuu++){
        std::cout << "Syota kuukausi " << kuu+1 << " sademaara: ";
        std::cin >> sademaara[kuu];
    }
    
    for (int i = 0; i < 12; i++){
        tulostatahti(sademaara[i]);
        rivi();
    }
      
    return 0;
}