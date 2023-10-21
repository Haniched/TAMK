// V7_3_MatkaHinta

#include <iostream> 
using namespace std;

float Matkahinta (float kilometrit, float kulutus, float poltto_hinta){
    float poltto_kulut = (kilometrit/100)*kulutus*poltto_hinta;
    return poltto_kulut;
}

int main(){

    float kilometrit, kulutus, poltto_hinta;

    cout << "Anna autolla ajettava matka kilometrina: ";
    cin >> kilometrit;

    cout << "Anna auton polttoaineen kulutus sadalla kilometrilla: ";
    cin >> kulutus;

    cout << "Anna polttoaineen hinta: ";
    cin >> poltto_hinta;

    cout << "Autolla ajettavan matkan polttoainekulut ovat: " << Matkahinta(kilometrit, kulutus, poltto_hinta)<< " euroa.\n";
    return 0;
}

   