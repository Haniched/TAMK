#include "./../headers/opiskelija.h"
#include <iostream>
using namespace std;

Opiskelija::Opiskelija()
    : henkilo(" ", 0, osoite(" ", " ", " ")), opNro(0), opintopiste(0)
{
}

Opiskelija::Opiskelija(const string& aNimi, int aIka, const osoite& aOsoite, const string& aOpnumero, int aOpintopiste)
    : henkilo(aNimi, aIka, aOsoite), opNro(aOpnumero), opintopiste(aOpintopiste) 
    {
        cout << "Opiskelija- luokan rakentaja" << endl;
    }

Opiskelija::~Opiskelija() {
    cout << "Opiskelija- luokan purkaja" << endl;
}

void Opiskelija::setOpintopisteet(int aOpintopiste){
    opintopiste = aOpintopiste;
}

int Opiskelija::getOpintopisteet() const {
    return opintopiste;
}

void Opiskelija::setOpNro(const string& aOpnumero) {
    opNro = aOpnumero;
}  

string Opiskelija::getOpNro() const {
    return opNro;
}

void Opiskelija::lisaaKurssi(const string& aKurssi){
    s_Kurssi.push_back(aKurssi);
}
    
void Opiskelija::lisaaOpintopisteita(int aOpintopiste){
    // setOpNro(aOpintopiste);
    opintopiste += aOpintopiste;
}

void Opiskelija::tulostaTiedot() const {
    cout << "Opiskelijan tiedot: " << endl;
    cout << getNimi() << endl;
    cout << "Ika: " << getIka() << endl;
    cout << "Osoite: " << endl;
    getOsoite().tulostaOsoite();
    cout << "Opintonumero: " << getOpNro() << endl;
    cout << "Opintopisteet: " << getOpintopisteet() << endl;
    cout << "Suoritetut kurssit: ";
    for ( string s : s_Kurssi) {
        cout << s << ", ";
    }
    cout << endl;
}