#include "../headers/paivays.h"

Paivays::Paivays(int aPaiva, int aKausi, int aVuosi){
   paiva = aPaiva;
   kuukausi = aKausi;
   vuosi = aVuosi;
}

void Paivays::setPaiva(int aPaiva) {
    if ((aPaiva > 0) && (aPaiva <= 31)) {
        paiva = aPaiva;
    } else {
        paiva = 1;
    }
}

void Paivays::setKuukausi(int aKausi){
    if ((aKausi > 0) && (aKausi <= 12)){
        kuukausi = aKausi;
    } else {
        kuukausi = 1;
    }
}

void Paivays::setVuosi(int aVuosi) {
    vuosi = aVuosi;
}

int Paivays::getPaiva() const{
    return paiva;
}
int Paivays::getKuukausi() const {
    return kuukausi;
}
int Paivays::getVuosi() const{
    return vuosi;
}

void Paivays::tulostaPaivays() const{
    std::cout << paiva << "." << kuukausi << "." << vuosi << std::endl;
}