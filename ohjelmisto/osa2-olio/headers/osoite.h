#pragma once
#include <string>
using namespace std;

class osoite {
    public:
        // Rakentajat ja purkajat
        osoite();
        osoite(const string& aKatuosoite, const string& aPostinumero, const string& aPaikkakunta);
        ~osoite();
        // getterit ja setterit
        void setKatuosoite(string aKatuosoite);
        void setPostinumero(string aPostinumero);
        void setKunta(string aPaikkakunta);

        string getKatuosoite() const;
        string getPostinumero() const;
        string getPaikkakunta() const;

        void tulostaOsoite() const;

    private:
        string katuosoite;
        string postinumero;
        string paikkakunta;
};

