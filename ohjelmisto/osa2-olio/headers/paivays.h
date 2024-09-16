#pragma once
#include <iostream>

class Paivays {
public:

    Paivays(int aPaiva, int aKausi, int aVuosi);

    void setPaiva(int aPaiva);
    void setKuukausi(int aKausi);
    void setVuosi(int aVuosi);

    int getPaiva() const;
    int getKuukausi() const;
    int getVuosi() const;

    void tulostaPaivays() const;

private: 
    int paiva;
    int kuukausi;
    int vuosi;
};