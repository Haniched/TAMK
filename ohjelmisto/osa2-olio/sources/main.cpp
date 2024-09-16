#include "../headers/osoite.h"
#include "../headers/henkilo.h"
#include "../headers/opettaja.h"
#include "../headers/opiskelija.h"
#include "../headers/koulu.h"
#include <iostream>
#include <vector>
using namespace std;


int main(){

    Koulu koulu("Alto");

    int toiminto = 0;

    while (toiminto != 8) {

        cout << "\nValitse toiminto:" << endl;
        cout << "1: Lisää opettajan tiedot" << endl;
        cout << "2: Lisää opettajalle kurssi" << endl;
        cout << "3: Lisää opiskelijan tiedot" << endl;
        cout << "4: Lisää opiskelijalle kurssi" << endl;
        cout << "5: Tulosta opettajien tiedot" << endl;
        cout << "6: Tulosta opiskelijoiden tiedot" << endl;
        cout << "7: Tulosta koulun tiedot" << endl;
        cout << "8: Lopeta\n>> ";
        cin >> toiminto;
        cout << endl;

        switch(toiminto) {
            case 1: {
            string opettajannimi;
            int opettajanika;
            cout << "Opettajan nimi: ";
            cin >> opettajannimi;
            cout << "Opettajan ika: ";
            cin >> opettajanika;
            koulu.lisaaOpettaja( new Opettaja(opettajannimi, opettajanika, osoite("","",""),""));
            break;
            }

            case 2:{
            string opettajakurssi;
            cout << "Opettajan vastukurssin nimi: ";
            cin >> opettajakurssi;
            koulu.lisaaOpettajalleKurssi(opettajakurssi);
            break;
            }

            case 3:{
            string opiskelijanimi;
            int opiskelijaika;
            cout << "Opiskelijan nimi: ";
            cin >> opiskelijanimi;
            cout << "Opiskelijan ika: ";
            cin >> opiskelijaika;
            koulu.lisaaOpiskelija( new Opiskelija(opiskelijanimi, opiskelijaika, osoite("","",""), "",0));
            break;
            }

            case 4:{
            string opiskelijakurssi;
            cout << "Opiskelijan suoritettava kurssi: ";
            cin >> opiskelijakurssi;
            koulu.lisaaOpiskelijalleKurssi(opiskelijakurssi);
            break;
            }

            case 5: 
            koulu.tulostaopettajat();
            break;
            

            case 6:
            koulu.tulostaopiskelijat();
            break;
            

            case 7: 
            koulu.tulostakoulunTiedot();
            break;
            
            case 8:
            cout << "bye bye" << endl;
            break;

            default:
            cout << "oi that's wrong input" << endl;
            break;

        }
    }

    return EXIT_SUCCESS;
}