// V10_3 Struct opiskelija_funktio

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int PISTEET = 3;

// määritellään opiskelija tietueet
struct opiskelija {
    string infot [3];
    int piste;
};

string annos [4] = {
    "Anna opiskelijan etunimi: ",
    "Anna opiskelijan sukunimi: ",
    "Anna opiskelijan opiskelijanumero: ",
    "Anna opiskelijan opintopisteet: "
};

string tulos [4] = {
    "Etunimi: ",
    "Sukunimi: ",
    "Opiskelijanumero: ",
    "Opintopisteet: "
};

void tulostaOpiskelijanTiedot(opiskelija O){
    for (size_t i = 0; i < sizeof(tulos) / sizeof(tulos[0]); i++) {
        if (i == PISTEET) {
            cout << tulos [i] << O.piste << "\n";
        } else {
            cout << tulos [i] << O.infot [i] << "\n";
        }
    }
}


int main (){

    opiskelija O;

    // saadaan infoa käyttäjästä
    for (size_t i = 0; i < sizeof(annos) / sizeof(annos[0]); i++){
        std::cout << annos [i];
        if (i == PISTEET){
            std::cin >> O.piste;
        } else {
            std::cin >> O.infot [i];
        }
    }
    tulostaOpiskelijanTiedot (O);
    return 0;
}

