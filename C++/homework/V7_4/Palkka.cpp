// V7_4_Palkka

#include <iostream>
using namespace std;

int palkka (int tuntimaara){
    int perustuntipalkka = 10;
    int ylituntipalkka = 15;
    int vkotunti = 40;  // Määrittää perus viikon työ tunnit

    //Tässä lasketaan palkka tuntimäärän perusteella
    //ja palautetaan tulos kutsujalle

    if (tuntimaara <= vkotunti){
        return perustuntipalkka*tuntimaara;     // Palauta perustunnin palkka, joka ei ylittää perus viikon työ tunnit
    }
    else {
        int ylitunti = tuntimaara-vkotunti;     // Määrittää kuinka paljon tuntimäärä ylittää kuin perus viikon tunnit
        return (perustuntipalkka*vkotunti)+(ylitunti*ylituntipalkka); // Palauta 40 tunnilla työskennellyt palkka + sen ylittävä työtunneiden palkka
    }
}

int main (){
    int tuntimaara;
    cout << "Anna viikon tyotunnit: ";          // Kysyy työtunnit
    cin >> tuntimaara;
    
    int bruttoansiot = palkka(tuntimaara);      // tulostaa viikon bruttoansiot
    cout << "Viikon palkkasi on: " << bruttoansiot << " euroa.\n";
}