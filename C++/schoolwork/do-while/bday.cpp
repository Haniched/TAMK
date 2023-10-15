//smt got sly difficult 

#include <iostream>

// Palauttaa tiedon siita, montako paivaa on annetussakuukaudessa. Ottaa myos huomioon karkauspaivan. 

int kuukauden_paivat (int vuosi, int kuukausi, int paivat){

    int summa ( 0 );
        switch (kuukausi){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                summa +=31;
                break;
            case 4: case 6: case 9:
                summa += 30;
                break;
            case 2:
                summa += 28;
                if (((vuosi % 4 == 0) && (vuosi % 100 != 0))
                    || (vuosi % 400 == 0)) {
                        summa +=1; // lisätään karkauspäivä
                }
                break;

            default:
                break;

        }

    return summa; 

    }
    
   int main (){
    int syntymavuosi ( 2004 );
    int syntymakuukausi ( 4 );
    int syntymapaiva ( 14 );
    int vuosi ( 2023 );
    int kuukausi ( 10 );
    int paiva ( 2 );

    // Algoritmi:
    // - 1) Laske ensin syntymävuoden jäljellä olevat vuorokaudet
    // - 2) Laske sitten syntymävuotta seuraavan vuoden ja tämän vuoden väliset vuorokaudet
    // - 3) Laske tämän vuoden kuluneet vuorokaudet
    // Ensimerkissä 1) = 14.4.2004 - 31.12.2004
    //              2) = täydet vuodet 2005 - 2022
    //              3) = 1.1.2023 - 1.10.2023

    int summa ( 0 );
    for (int kk = syntymakuukausi + 1; kk <= 12; kk++){
        summa += kuukauden_paivat(syntymavuosi,kk);
        }
    summa += kuukauden_paivat (syntymavuosi, syntymakuukausi) - syntymapaiva;
    
    std::cout << "Syntymapaiva on jaljella " << summa << "vuorokautta. \n";

}