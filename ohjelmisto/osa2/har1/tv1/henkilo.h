#pragma once
#include <string>

class henkilo {
public:
    void setNimi(std::string aNimi);
    void setIka(int aIka);
    int getIka();
    std::string getNimi();
private:
    std::string nimi;
    int ika;
};