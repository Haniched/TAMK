// Arvauspeli, jossa on useita elämää helpottavia aliohjelmia.
// Käännös Microsoft C/C++:lla: cl /std:c++20 /EHsc arvaus_funktioilla.cpp

#include <iostream>
#include <random>  // satunnaislukugeneraattori alk. C++11
#include <string>

// Ajateltavan luvun (ja arvauksen) arvoalue, eli suljetun
// välin päätepisteet.
const int ARVAUS_PIENIN{ 1 };
const int ARVAUS_SUURIN{ 100 }; 

// Funktioiden prototyypit. 
// HUOM. Jos prototyyppejä käytetään, niin funktion parametrien 
// oletusarvojen pitää olla prototyypissä, ei funktion määrittelyssä. 
void uusirivi(int montako = 1);
void tulosta(std::string s, bool rivinvaihto = false);
void tulosta(int n);
void alkutekstit();
void lopputekstit(bool oikein);
void paljasta(int luku);
bool on_valilla(int luku, int pienin, int suurin);

const bool RIVINVAIHTO{ true };  // apuvakio tulostusta varten

int main() {
    // Aseta Windowsin komentoikkunan merkistöasetukset
    // niin että ääkköset näkyvät oikein kun ohjelmateksti
    // on tallennettu UTF-8-merkistökoodauksella.
    setlocale(LC_ALL, "C");
    setlocale(LC_CTYPE, ".UTF-8");

    alkutekstit();

    std::random_device rd;  // laitteiston / käyttöjärjestelmän satunnaislaite
    std::default_random_engine moottori{ rd() };  // tuottaa satunnaislukuja
    // em. satunnaislaitteen avulla

    // Jakauma joka tuottaa numerovälin arvot satunnaisesti mutta tasaisesti
    std::uniform_int_distribution aivo{ ARVAUS_PIENIN, ARVAUS_SUURIN };  // HUOM.! C++20

    int luku{ aivo(moottori) };  // Luku jota tietokone "ajattelee".
    //paljasta(luku);

    bool oikein{ false };  // onko pelaajan arvaus oikein (true) vai ei (false)

    const int MAX_KERRAT{ 10 };  // arvauskertojen suurin mahdollinen määrä
    int kerrat{ 0 };             // montako kertaa on jo arvattu

    while (!oikein) {  // jatketaan niin kauan kuin vastaus ei ole oikein
        tulosta("Anna arvauksesi: ");
        int arvaus{ 0 };
        std::cin >> arvaus;  // HUOM.! Ei toimi jos syöte ei olekaan kokonaisluku!

        // Tarkistetaan että arvaus on halutulla välillä.
        if (!on_valilla(arvaus, ARVAUS_PIENIN, ARVAUS_SUURIN)) {
            tulosta("Arvauksen pitää olla välillä ");
            tulosta(ARVAUS_PIENIN);
            tulosta(" ... ");
            tulosta(ARVAUS_SUURIN);
            tulosta("!", RIVINVAIHTO);
            continue;  // siirtyy seuraavalle kierrokselle silmukassa
        }

        kerrat += 1;  // sama kuin 'kerrat = kerrat + 1' mutta lyhyempi

        if (arvaus > luku) {
            tulosta("Liian suuri!");
        }
        else if (arvaus < luku) {
            tulosta("Liian pieni!");
        }
        else {
            tulosta("Arvasit oikein!");
            oikein = true;
        }
        uusirivi();

        tulosta("Arvauksia jäljellä: ");
        tulosta(MAX_KERRAT - kerrat);
        uusirivi();

        if (kerrat == MAX_KERRAT && !oikein) {
            tulosta("Olet arvannut jo ");
            tulosta(kerrat);
            tulosta(" kertaa. ");
            tulosta("Peli päättyy.", RIVINVAIHTO);
            break;  // poistuu heti ohjausrakenteesta, eli tässä while-silmukasta
        }
    }

    lopputekstit(oikein);    
}

// Tulostaa rivinvaihdon.
void uusirivi(int montako) {
    if (montako <= 0) {
        return;
    }

    for (int i{ 0 }; i < montako; i++) {
        std::cout << '\n';
    }
}

// Tulostaa merkkijonon ja mahdollisesti rivinvaihdon sen perään.
void tulosta(std::string s, bool rivinvaihto) {
    std::cout << s;
    if (rivinvaihto) {
        uusirivi();
    }
}

// Tulostaa kokonaisluvun.
void tulosta(int n) {
    std::cout << n;
}

// Tulostaa ohjelman alkutekstit.
void alkutekstit() {
    uusirivi(2);
    tulosta("Ajattelen jotain lukua väliltä 1-100. Arvaatko sen?", RIVINVAIHTO);
}

// Tulostaa erilaiset lopputekstit riippuen pelin tuloksesta.
void lopputekstit(bool oikein) {
    if (oikein) {
        tulosta("Onneksi olkoon, arvasit luvun!");
    }
    else {
        tulosta("Voi harmi! Parempi onni ensi kerralla.");
    }
    uusirivi();
}

void paljasta(int luku) {
    tulosta("(Ajattelemani luku on ");
    tulosta(luku);
    tulosta(". Shhh!!!)", RIVINVAIHTO);
}

// Palauttaa `true` jos `luku` on välillä `[pienin..suurin]`, muutoin `false`. 
bool on_valilla(int luku, int pienin, int suurin) {
    if (luku >= pienin && luku <= suurin) {
        return true;
    }
    return false;
}
