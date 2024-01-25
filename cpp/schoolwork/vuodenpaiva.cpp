// Laskee monesko päivä vuodesta nyt on menossa.
// Ottaa huomioon myös karkausvuoden.

#include <iostream>

int main() {
    int summa{ 0 };  // tähän kertyy vuodesta kuluneiden päivien lukumäärä
    int p{ 31 };  // kuukauden päivän numero
    int k{ 12 }; // kuukauden numero
    int v{ 2020 };  // vuosiluku
    
    // Silmukka käy läpi arvot 1 ... kuukausi-1.
    // Muuttuja i edustaa tarkasteltavaa kuukautta.
    // Eri tapauksia on kolme: 31-päiväiset, 30-päiväiset ja helmikuu.
    for (int i{ 1 }; i < k; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            summa = summa + 31;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11) {
            summa = summa + 30;
        }
        else {
            summa = summa + 28;
            
            // Jos vuosi on karkausvuosi, lisätään karkauspäivä (29.2.)
            if (((v % 4 == 0) && (v % 100 != 0)) || (v % 400 == 0)) {
                summa = summa + 1;
            }
        }
    }
    
    summa = summa + p;  // lisätään "vajaan" kuukauden päivät 
    
    std::cout << summa;
}

// Jos löydät algoritmista virheen, kerro siitä!
