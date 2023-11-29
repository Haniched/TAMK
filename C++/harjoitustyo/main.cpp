#include "hotelli.hpp"

void alkuteksti() {
    tulosta ("Terveltuloa Hotelli Californiaan!\nOnpas ihana paikka.\n", true);
};


/* huoneet, joka alku puolet ovat yksihenkinen huone ja loput ovat pari henkilön
    std::vector <int> huonetyyppi;
*/

int main (){
    
    rivi(); alkuteksti();
    
    tulosta ("Aika paljon huoneetta Hotelli Californiassa on.", true);
    // hotellin huoneiden määrän kirjoitus 
    kirjoitus_numero ("hotelli.txt", satunnainen_huoneetmaara());
    lukema_numero ("hotelli.txt", " huoneita ovat saatavilla.");
    rivi ();
    tulosta ("Californiassa on yhden tai kahden hengen huoneita.", true);


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