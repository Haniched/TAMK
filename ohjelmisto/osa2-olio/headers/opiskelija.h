#pragma once
#include "henkilo.h"
#include <vector>
#include <string>
using namespace std;

class Opiskelija : public henkilo {
public: 
    Opiskelija();
    Opiskelija(const string& aNimi, int aIka, const osoite& aOsoite, const string& aOpnumero, int aOpintopiste);
    ~Opiskelija();

    void setOpintopisteet(int aOpintopiste);
    int getOpintopisteet() const;
    void setOpNro(const string& aOpnumero);
    string getOpNro() const;

    void lisaaKurssi(const string& aKurssi);
    void lisaaOpintopisteita(int aOpintopiste);
    void tulostaTiedot() const override;

protected: 
    string opNro;
    vector<string> s_Kurssi;
    int opintopiste;
};