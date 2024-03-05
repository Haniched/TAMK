#include <string>
#include <iostream>
#include "henkilo.cpp"

using namespace std;

int main (){
    // Prosessin suoritus alkaa tästä
    henkilo huni;
    huni.setNimi("Huni");
    huni.setIka(22);
    cout << "Nimi: " << huni.getNimi() << endl;
    cout << "Ika: " << huni.getIka() << endl;

    henkilo wani;
    wani.setNimi("Wani");
    wani.setIka(30);
    cout << "Nimi: " << wani.getNimi() << endl;
    cout << "Ika: " << wani.getIka() << endl;
    
    return 0;
}