// V10_1 Opiskelijan struct

#include <iostream>
#include <string>
#include <array>

/*
enum {
    ETUNIMI,
    SUKUNIMI,
    NUMERO,
    PISTEET
};
*/

#define PISTEET 3;

// määritellään opiskelija tietueet
struct Opiskelija{
    std::string infot [3];
    int piste;
};

int main(){

    Opiskelija opiskelija;

    std::array <std::string, 4> annos {
        "Anna opiskelijan etunimi: ",
        "Anna opiskelijan sukunimi: ",
        "Anna opiskelijan opiskelijanumero: ",
        "Anna opiskelijan opintopisteet: "
};

    std::array <std::string, 4> tulos {
        "Etunimi: ",
        "Sukunimi: ",
        "Opiskelijanumero: ",
        "Opintopisteet: "
    };
    
    // saadaan infoa käyttäjästä
    for (size_t i {0}; i < annos.size(); i++){
        std::cout << annos [i];
        if (i == PISTEET){
            std::cin >> opiskelija.piste;
        } else {
            std::cin >> opiskelija.infot [i];
        }
    }
    // tulostaa infoa
    for (size_t i {0}; i < tulos.size(); i++) {
        if (i == PISTEET) {
            std::cout << tulos [i] << opiskelija.piste << "\n";
        } else {
            std::cout << tulos [i] << opiskelija.infot [i] << "\n";
        }
    }
    return 0;
}


