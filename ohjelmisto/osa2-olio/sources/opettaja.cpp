#include "./../headers/opettaja.h"
#include <iostream>
using namespace std;

Opettaja::Opettaja() 
    : henkilo(" ", 0, osoite(" ", " ", " ")), koulutusala(" ")
{
}

Opettaja::Opettaja(const string& aNimi, int aIka, const osoite& aOsoite, const string& aKoulutusala)
    : henkilo(aNimi, aIka, aOsoite), koulutusala(aKoulutusala)
{
    cout << "Opettaja luokan rakentaja" << endl;
}

Opettaja::~Opettaja(){
    cout << "Opettaja luokan purkaja" << endl;
}

void Opettaja::setKoulutusala(const string& aKoulutusala) {
    koulutusala = aKoulutusala;
}

string Opettaja::getKoulutusala() const{
    return koulutusala;
}

void Opettaja::lisaaKurssi(const string& aKurssi){
    kurssit.push_back(aKurssi);
}

void Opettaja::poistaKurssi(const string& aKurssi){
    // kurssit.erase(aKurssi);
}

void Opettaja::tulostaTiedot() const {
    cout << "Opettajan tiedot: " << endl;
    cout << getNimi() << endl;
    cout << "Ika: " << getIka() << endl;
    cout << "Osoite: " << endl;
    getOsoite().tulostaOsoite();
    cout << "Koulutusala: " << koulutusala << endl;
    cout << "Vastuukurssit: ";
    for ( string s : kurssit) {
        cout << s << ", ";
    }
    cout << endl;
}