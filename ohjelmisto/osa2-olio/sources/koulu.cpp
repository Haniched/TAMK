#include "./../headers/koulu.h"
#include "./../headers/opettaja.h"
#include "./../headers/opiskelija.h"
#include <iostream>

using namespace std;

Koulu::Koulu(const string& aNimi) : nimi(aNimi)
{

}

void Koulu::lisaaOpiskelija(Opiskelija* aOpiskelija) {
    opiskelijat.push_back(aOpiskelija);
}

void Koulu::lisaaOpettaja (Opettaja* aOpettaja) {
    opettajat.push_back(aOpettaja);
}


void Koulu::lisaaOpettajalleKurssi(const string& aKurssi) {
    for (Opettaja* opettaja : opettajat) {
        opettaja->lisaaKurssi(aKurssi);
    }
}

void Koulu::lisaaOpiskelijalleKurssi(const string& aKurssi) {
    for (Opiskelija* opiskelija : opiskelijat){
        opiskelija->lisaaKurssi(aKurssi);
    }
}


void Koulu::tulostaopettajat() const { 
    cout << "Opettajat:" << endl;
    for (const Opettaja* opettaja : opettajat) {
        opettaja->tulostaTiedot();
        cout << endl;
    }
}

void Koulu::tulostaopiskelijat() const {
    cout << "Opiskelijat:" << endl;
    for (const Opiskelija* opiskelija : opiskelijat) {
        opiskelija->tulostaTiedot();
        cout << endl;
    }
}

void Koulu::tulostakoulunTiedot() {
    cout << "Koulun nimi: " << nimi << endl;

    cout << "Opettajat:" << endl;
    for (const Opettaja* opettaja : opettajat) {
        opettaja->tulostaTiedot();
        cout << endl;
    }

    cout << "Opiskelijat:" << endl;
    for (const Opiskelija* opiskelija : opiskelijat) {
        opiskelija->tulostaTiedot();
        cout << endl;
    }
}


void Koulu::setkoulunNimi(const string& aNimi) {
    nimi = aNimi;
}

string Koulu::getKoulunNimi() const  {
    return nimi;
}
