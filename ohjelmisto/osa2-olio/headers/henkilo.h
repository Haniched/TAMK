#pragma once
#include <string>
#include "osoite.h"
using namespace std;

class henkilo {
public:
    
    henkilo();
    henkilo(string aNimi, int aIka, osoite aKotiosoite);
    ~henkilo();

    void setNimi(string aNimi);
    void setIka(int aIka);
    void setOsoite(osoite aKotiosoite);
    int getIka() const;
    string getNimi() const;
    osoite getOsoite() const;

    virtual void tulostaTiedot() const;
    
private:
    osoite kotiosoite;
    string nimi;
    int ika;
};