//
//  main.cpp
//  String_Bool
//
//  Created by Heejeong Han on 10.10.2023.
//

#include <iostream>
#include <string>

int main () {
    bool ok (false); //bool=boolean tyyppi boolen alkebra arvo true or false
    
    std::cout << "Onko kaikki hyvin? ";
    std::string vastaus;
    std::cin >> vastaus;
    
    if (vastaus == "on") {
        ok = true;
    }
    
    if (ok) {
        std::cout << "OK\n";
    }
    else {
        std::cout << "Ei OK.\n";
    }
}
