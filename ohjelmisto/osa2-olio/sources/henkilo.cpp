#include <iostream>
#include "../headers/henkilo.h"

using namespace std;

henkilo::henkilo() {
}

henkilo::henkilo(string aNimi, int aIka, osoite aKotiosoite) {
    nimi = aNimi;
    ika = aIka;
    kotiosoite = aKotiosoite; 
}

henkilo::~henkilo(){
    // cout << nimi << " on poistettu" << endl;
    cout << endl;
}

// henkilo::henkilo(string aNimi, int aIka): nimi(aNimi), ika(aIka) {}

void henkilo::setNimi(string aNimi) {
    nimi = aNimi;
}

void henkilo::setIka(int aIka){
    if (aIka >= 0){
        ika = aIka;
    }
}

void henkilo::setOsoite(osoite aKotiosoite) {
    kotiosoite = aKotiosoite;
}

int henkilo::getIka() const{
    return ika;
}

string henkilo::getNimi() const{
    return nimi;
}

osoite henkilo::getOsoite() const{
    return kotiosoite;
}

void henkilo::tulostaTiedot () const{
    cout << "Nimi: " << nimi << endl;
    cout << "Ika: " << ika << endl;
    kotiosoite.tulostaOsoite();
}
