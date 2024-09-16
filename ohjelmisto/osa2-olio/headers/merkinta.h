#pragma once
#include "paivays.h"
#include <string>
using namespace std;
class merkinta {
public:
    merkinta();
    merkinta(Paivays aPaiva, const string& aMerkinta, bool aMuistutus);
    merkinta(const merkinta& aMerkinta);
    ~merkinta();

    void setPaivays(Paivays aPaiva);
    void setMerkinta(const string& aMerkinta);
    void setMuistutus(bool aMuistutus);

    Paivays getPaivays();
    std::string getMerkinta();
    bool getMuistutus();
    
    void tulostaMerkinta() const; 
    void kysyTiedot();
private:
    Paivays paiva;
    std::string asia;
    bool muistutus;
};