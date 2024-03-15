#include <string>
#include <iostream>
#include "henkilo.cpp"

using namespace std;

void generateperson () {
    henkilo rani ("Rani", 21);
    rani.tulostatiedot();
}

int main (){

    if (true) {
        henkilo huni ("Huni", 22);
        huni.tulostatiedot();

        henkilo* wani = new henkilo ("Wani", 30);
        wani->tulostatiedot();
        delete wani;
    }

    for (int i = 0; i < 2; i++) {
        henkilo kani ("Kani", 32);
        kani.tulostatiedot();
    }

    generateperson();
    
    return EXIT_SUCCESS;
}