#include <string>
#include <iostream>
#include "henkilo.h"
using namespace std;

henkilo::henkilo() {
}

henkilo::henkilo(string aNimi, int aIka) {
    nimi = aNimi;
    ika = aIka;
}

henkilo::~henkilo(){
    cout << nimi << " on poistettu" << endl;
}

void henkilo::setNimi(string aNimi) {
    nimi = aNimi;
}
void henkilo::setIka(int aIka){
    if (aIka >= 0){
        ika = aIka;
    }
}
int henkilo::getIka(){
    return ika;
}
string henkilo::getNimi(){
    return nimi;
}

void henkilo::tulostatiedot () {
    cout << "Nimi: " << nimi << endl;
    cout << "Ika: " << ika << endl;
}
