#include "../headers/merkinta.h"
#include <iostream>
using namespace std;

merkinta::merkinta() : paiva(0, 0, 0), asia(""), muistutus(false) {

}

merkinta::merkinta(Paivays aPaiva, const std::string& aMerkinta, bool aMuistutus)
    : paiva(aPaiva), asia(aMerkinta), muistutus(aMuistutus) 
    {
}

// Destructor
merkinta::~merkinta() {
    // Destructor implementation, if needed
}

merkinta::merkinta(const merkinta& aMerkinta)
    :paiva(8, 4, 2024), asia(aMerkinta.asia), muistutus(aMerkinta.muistutus)
{
    cout << "kopioidaan kalentarimerkinta" << endl;
}

// Setter for paiva
void merkinta::setPaivays(Paivays aPaiva) {
    paiva = aPaiva;
}

// Setter for asia
void merkinta::setMerkinta(const std::string& aMerkinta) {
    asia = aMerkinta;
}

// Setter for muistutus
void merkinta::setMuistutus(bool aMuistutus) {
    muistutus = aMuistutus;
}

// Getter for paiva
Paivays merkinta::getPaivays() {
    return paiva;
}

// Getter for asia
string merkinta::getMerkinta() {
    return asia;
}

// Getter for muistutus
bool merkinta::getMuistutus() {
    return muistutus;
}

// Method to print merkinta details
void merkinta::tulostaMerkinta() const {
    cout << "Päivä: " << paiva.getPaiva() << "." << paiva.getKuukausi() << "." << paiva.getVuosi() << endl;
    cout << "Merkintä: " << asia << endl;
    cout << "Muistutus: " << (muistutus ? "Kyllä" : "Ei") << endl;
}

// Method to prompt user for merkinta details
void merkinta::kysyTiedot() {
    int p, k, v;
    cout << "Syötä päivä: ";
    cin >> p;
    cout << "Syötä kuukausi: ";
    cin >> k;
    cout << "Syötä vuosi: ";
    cin >> v;

    paiva.setPaiva(p);
    paiva.setKuukausi(k);
    paiva.setVuosi(v);

    cout << "Syötä merkintä: ";
    cin.ignore(); // Clear input buffer
    getline(cin, asia);

    cout << "Onko muistutus? (1 - Kyllä, 0 - Ei): ";
    cin >> muistutus;
}
