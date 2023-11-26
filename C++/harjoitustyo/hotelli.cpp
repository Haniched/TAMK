
#include <fstream>
#include <iostream>
#include <string>
#include <array>

void rivi (){
    std::cout << '\n';
};

void tulosta (std::string t, bool RIVI){
    std::cout << t;
    if (RIVI){std::cout << '\n';}
};

void tulosta (std::string t, int n, bool RIVI){
    std::cout << t << n;
    if (RIVI){std::cout << '\n';}
};

void tulosta_virhe (std::string tiedoston_nimi){
    std::cerr << "VIRHE: Tiedostoa " << tiedoston_nimi << " ei voitu avata." << std::endl;
};

bool vahvistus (std::string viesti){
    std::string vastaus;

    do {
        std::cout << viesti << " vastaa Y tai N (Joo tai Ei): ";
        std::cin >> vastaus;
        if (vastaus == "Y" || vastaus == "y"){return true;}
        else if (vastaus == "N" || vastaus == "n"){return false;}
        else {std::cerr << "Hmm... onko se joo vai ei? Vastaa uudelleen!" << std::endl;}
    } while (true && false);
}

// huoneen numeron määrittely
int huonenumerot (int& num){
    int huoneen_numero = ((num/10)+1)*100 + (num%10);
    if (num/10){return huoneen_numero++;}
    return huoneen_numero;
}

int puoli (int n){
    n = n / 2;
    return n;
}

// tiedoston tarkistus, onko se auki vai ei
void tarkistus (const std::string& tiedosto, std::ifstream input){
    input.open (tiedosto);
    if (!input.is_open()){tulosta_virhe(tiedosto);}
}

void kirjoitus_numero (const std::string& tiedosto, int& n){
    // tarkistaa tiedoston sisältö
    std::ifstream input (tiedosto);
     if (input.is_open){
        input.seekg (0, std::ios::end);
        // kirjoita tiedostoon
        std::ofstream out;
        if (input.tellg () < 0){
            out (tiedosto); 
            out << n;
        } /*else if (input.tellg >= 3){
            out (tiedosto, std::ios::app);
            out << n;
        }*/
     else {tulosta_virhe(tiedosto);}
    }
   
};

void lukema_numero (const std::string& tiedosto, std::string lause){
    std::ifstream in (tiedosto);
    tarkistus (tiedosto, in);
    int n;
    while (std::getline (in,n)){
        std::cout << n << lause << std::endl;
    }
};

struct Vieras {
    std::string nimi, huonetyyppi;
    int huoneenmaara, yonmaara;
};


bool Vieras_tarkistus (const std::string& tiedosto, const std::string& nimi, int n){
    std::fstream Tieto (tiedosto, std::ios::end);
    int rivi = 0;
    std::string line;
    while (std::getline (Tieto, line, ',')){
        rivi++;
        if (Tieto.find(nimi) != std::string::npos){
            Tieto.seekg (0, std::ios::end);
            if (Tieto.tellg () <= n){
                return true;
            } else { 
                std::cout << "Pahoillaan, varattavien huoneiden määrä on täynnä." << std::endl;
                return false;
            }
        }
    }
}



void varaus (std::string tiedosto, Vieras) {
    using namespace std;
    fstream out;
    out.open (tiedosto, ios::out | ios::app);

    Vieras vieras;

    array syotto_vieras <string, 4> {
        "Sukunimesi: ", 
        "Huoneen tyyppi: ", 
        "Huoneen määrä: ", 
        "Öiden määrä: ";
    }

    if (Vieras_tarkistus (tiedosto, vieras.nimi, vieras.huoneenmaara) == true){ 
        cout << syotto_vieras [0];
        cin >> vieras.nimi;
        cout << syotto_vieras [1];
        cin >> vieras.huonetyyppi;
        cout << syotto_vieras [2];
        cin >> vieras.huoneenmaara;
        cout << syotto_vieras [3];
        cin >> vieras.yonmaara;
        
        out >> vieras.nimi << ", "
        >> vieras.huonetyyppi << ", "
        >> vieras.huoneenmaara << ", "
        >> vieras.yonmaara << ", "
        rivi ();
    } else {
        Vieras_tarkistus (tiedosto, vieras.nimi, vieras.huoneenmaara) == false;
    }
};


