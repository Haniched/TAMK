// switch 
// calculate current days in this year

#include <iostream>

int main() {
     int currentDay ( 25 ); // monesko päivä tänään on?
     int currentMonth ( 9 ); // monesko kuukausi (1 = tammikuu, ..., 12 = joulukuu)
     int tulos ( 0 ); // vuoden tähän asti kuluneiden päivien lukumäärä
     for (int i = 1; i < currentMonth; i++) { // käy läpi arvot 1.. k-1
       switch (i) {
       case 1: case 3: case 5: case 7: case 8: case 10: case 12:
         tulos += 31;
         break;
       case 4: case 6: case 9: case 11:
         tulos += 30;
         break;
       case 2:
       tulos += 28 ; // HUOM Ei tarkisteta karkausvuotta vielä
       break;
       default:
       std::cout << "Kuukausi ei kelpaa!\n";
       break;
       }
     }
     tulos = tulos + currentDay;
     std::cout << tulos << "\n";

}
