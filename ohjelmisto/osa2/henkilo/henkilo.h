#pragma once
#include <string>
using namespace std;

class henkilo {
public:
    
    henkilo();
    henkilo(string aNimi, int aIka);
    ~henkilo();

    void setNimi(string aNimi);
    void setIka(int aIka);
    int getIka();
    string getNimi();

    void tulostatiedot();
private:
    string nimi;
    int ika;
};