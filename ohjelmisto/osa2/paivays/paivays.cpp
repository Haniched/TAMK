#include <iostream>
#include "paivays.h"

void paivays::setPaiva(int aPaiva) {
    if ((aPaiva > 0) && (aPaiva <= 31)) {
        paiva = aPaiva;
    } else {
        paiva = 1;
    }
}

void paivays::setKuukausi(int aKausi){
    if ((aKausi > 0) && (aKausi <= 12)){
        kuukausi = aKausi;
    } else {
        kuukausi = 1;
    }
}

void paivays::setVuosi(int aVuosi) {
    vuosi = aVuosi;
}

int paivays::getPaiva() {
    return paiva;
}
int paivays::getKuukausi(){
    return kuukausi;
}
int paivays::getVuosi() {
    return vuosi;
}

void paivays::tulostaPaivays(){
    std::cout << "on " << paiva << '.' << kuukausi << '.' << vuosi << std::endl;
}