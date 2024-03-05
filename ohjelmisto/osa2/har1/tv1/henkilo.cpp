#include <string>
#include <iostream>
#include "henkilo.h"

void henkilo::setNimi(std::string aNimi) {
    nimi = aNimi;
}
void henkilo::setIka(int aIka){
    if (aIka >= 0){
        ika = aIka;
    }
}
int henkilo::getIka(){
    return ika;
}
std::string henkilo::getNimi(){
    return nimi;
}
