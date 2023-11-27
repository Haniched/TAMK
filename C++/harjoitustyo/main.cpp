#include "hotelli.hpp"

void alkuteksti() {
    tulosta ("Terveltuloa Hotelli Californiaan!\nOnpas ihana paikka.\n", true);
};

// hotelli huoneiden satunnainen parillinen luku
int satunnainen_huoneetmaara (){
    int huoneetmaara = rand() % 301+40;
    if (huoneetmaara % 2 == 0) {return huoneetmaara;}
    else {return huoneetmaara++;}
    return huoneetmaara;
}

int main (){
    
    rivi(); alkuteksti();
    
    tulosta ("Aika paljon huoneetta Hotelli Californiassa on.", true);
    
    // 
    kirjoitus_numero ("hotelli.txt", satunnainen_huoneetmaara());
    lukema_numero ("hotelli.txt", " huoneita ovat saatavilla.");
    rivi ();
    tulosta ("Californiassa on yhden tai kahden hengen huoneita.", true);

    // huoneet, joka alku puolet ovat yksihenkinen huone ja loput ovat pari henkilön
    std::vector <int> huonetyyppi;
    int yksi = puoli(satunnainen_huoneetmaara());
    int pari = satunnainen_huoneetmaara()-yksi;
    huonetyyppi.push_back (yksi);
    huonetyyppi.push_back (pari);
    
    for (int i : huonetyyppi){
        kirjoitus_numero ("hotelli.txt", huonenumerot(i));
        rivi ();
    }

    if (!vahvistus ("Haluatko varata?")) {
        std::cout << "Selvä, toivotaan nähdämme uudestaan!" << std::endl;
        return 0;
    } 
    
    Vieras vieras;
    tulosta ("Syötä varajan tietoa alle", true);
    varaus ("varaus.csv", vieras);
    
}