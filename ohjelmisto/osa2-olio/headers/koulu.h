#pragma once
#include "opettaja.h"
#include "opiskelija.h"
#include <map>
using namespace std;

class Koulu {

    public:
        Koulu(const string& aNimi);
        void lisaaOpiskelija(Opiskelija* aOpiskelija);
        void lisaaOpettaja (Opettaja* aOpettaja);
   
        void lisaaOpettajalleKurssi(const string& akurssi);
        void lisaaOpiskelijalleKurssi(const string& akurssi);
        
        void tulostaopettajat() const;
        void tulostaopiskelijat() const;
        void tulostakoulunTiedot();
        
        void setkoulunNimi(const string& aNimi);
        string getKoulunNimi() const;

    private:
        string nimi;
        vector <Opettaja*> opettajat;
        vector <Opiskelija*> opiskelijat;
};  