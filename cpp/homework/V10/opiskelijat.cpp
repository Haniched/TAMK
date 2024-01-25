// V10_4 Struct funktio opiskelijat

#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Opiskelija {
    string info [3];
    int piste;
};

array <string, 4> annos = {
    "etunimi: ",
    "sukunimi: ",
    "opiskelijanumero: ",
    "opintopisteet: "
};

array <string, 4> tulos = {
    "Etunimi: ",
    "Sukunimi: ",
    "Opiskelijanumero: ",
    "Opintopisteet: "
};

// tee funktio joka kayttaja syottaa
Opiskelija luoOpiskelija (array <Opiskelija, 20>& opiskelijat, int& opiskelijat_maara){
    for (int n = 0; n < opiskelijat_maara; n++){
        for (int i = 0; i < annos.size(); i++){
        cout << "Anna opiskelijan " << annos [i];
        if (i == 3){cin >> opiskelijat[n].piste;}
        else {cin >> opiskelijat[n].info[i];}
        } cout << '\n';
    }
    return opiskelijat[0];
}

int main (){
    // kysyy kayttajalle paljonko opiskelijat halua syottaa
    int opiskelijat_maara;
    cout << "Kuinka monelle opiskelijalle luodaan tiedot? (MAX 20): ";
    cin >> opiskelijat_maara;

    if (opiskelijat_maara > 20){
        cout << "배부른돼지들부르주아척결";
    }

    array <Opiskelija, 20> opiskelijat;
    luoOpiskelija(opiskelijat, opiskelijat_maara);
    // tulostaa opiskelijan tiedot
    for (int n = 0; n < opiskelijat_maara; n++){
        cout << "Opiskelijan numero " << n+1 << " tiedot." << '\n';
        for (int i = 0; i < annos.size(); i++){
            if (i == 3) {cout << tulos [i] << opiskelijat[n].piste;}
            else {cout << tulos [i] << opiskelijat[n].info [i];}
            cout << '\n';
        } cout << '\n';
    }
return 0;
}