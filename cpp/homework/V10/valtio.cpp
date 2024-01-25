// V10_2 struct valtio

#include <iostream>
#include <string>
using namespace std;

struct valtio{
    string nimi, johtaja;
    int asukas, ala;
};

int main(){

    valtio valtiot [2];

    string annos_info [4] = {
    "nimi: ",
    "asukasluku: ",
    "pinta-ala: ",
    "johtaja: "
    };

    string tulos_info [4] = {
        "Nimi: ",
        "Asukasluku: ",
        "Pinta-ala: ",
        "Johtaja: "
    };

    // käyttäjä syötä valtio1 tiedot

    for (int v = 0; v < 2; v++){
        for (int i = 0; i < 4; i++){
            cout << "Anna valtion " << v+1 << ' ' << annos_info [i];
            if (i == 0){cin >> valtiot[v].nimi;}
            else if (i == 1){cin >> valtiot[v].asukas;}
            else if (i == 2){cin >> valtiot[v].ala;}
            else if (i == 3){cin >> valtiot[v].johtaja;}   
        } cout << "\n";
    }
        // tulosta annettu valtio1 tietoa

    for (int v = 0; v < 2; v++){    
        cout << "Valtio numero " << v+1 << "\n";
        for (int i = 0; i < 4; i++){
            cout << tulos_info [i];
            if (i == 0) {cout << valtiot[v].nimi << "\n";}
            else if (i == 1) {cout << valtiot[v].asukas << "\n";}
            else if (i == 2) {cout << valtiot[v].ala << "\n";}
            else if (i == 3) {cout << valtiot[v].johtaja << "\n";}
        } cout << '\n' << '\n';
    }
return 0;
}