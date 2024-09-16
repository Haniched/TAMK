#pragma once
#include "henkilo.h"
#include <string>
#include <vector>
using namespace std;

class Opettaja : public henkilo
{
public:
    Opettaja();
    Opettaja(const string& aNimi, int aIka, const osoite& aOsoite, const string& aKoulutusala);
    ~Opettaja();
    void setKoulutusala(const string& aKoulutusala);
    string getKoulutusala() const;
    void lisaaKurssi(const string& aKurssi);
    void poistaKurssi(const string& aKurssi);
    void tulostaTiedot() const override;

protected:
    // nimi, ika and osoite is generated already by calling henkilo class
    string koulutusala;
    vector<string> kurssit;
};