#include <iostream>
#include "../headers/osoite.h"

using namespace std;

// Constructor (no parameters)
osoite::osoite() {
    // cout << "osoite -luokan oletusrakentaja" << endl;
}

// Constructor (with parameters)
osoite::osoite(const string& aKatuosoite, const string& aPostinumero, const string& aPaikkakunta) 
{
    katuosoite = aKatuosoite;
    postinumero = aPostinumero;
    paikkakunta = aPaikkakunta;
}

// Destructor
osoite::~osoite() {
    // cout << "osoite vapautetaan" << endl;
}

// Setter for katuosoite
void osoite::setKatuosoite(string aKatuosoite) {
    katuosoite = aKatuosoite;
}

// Setter for postinumero
void osoite::setPostinumero(string aPostinumero) {
    postinumero = aPostinumero;
}

// Setter for paikkakunta
void osoite::setKunta(string aPaikkakunta) {
    paikkakunta = aPaikkakunta;
}

// Getter for katuosoite
string osoite::getKatuosoite() const{
    return katuosoite;
}

// Getter for postinumero
string osoite::getPostinumero() const{
    return postinumero;
}

// Getter for paikkakunta
string osoite::getPaikkakunta() const {
    return paikkakunta;
}


void osoite::tulostaOsoite() const{
    cout << "Katuosoite: " << getKatuosoite() << endl;
    cout << "Postinumero: " << getPostinumero() << endl;
    cout << "Paikkakunta: " << getPaikkakunta() << endl;
}
