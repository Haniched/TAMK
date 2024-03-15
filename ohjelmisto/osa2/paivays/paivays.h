#include <iostream>

class paivays {
public:
    void setPaiva(int aPaiva);
    void setKuukausi(int aKausi);
    void setVuosi(int aVuosi);
    int getPaiva();
    int getKuukausi();
    int getVuosi();
    void tulostaPaivays();
private: 
    int paiva;
    int kuukausi;
    int vuosi;
};