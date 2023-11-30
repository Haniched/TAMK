#include "hotelli.hpp"

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
    std::cerr << "VIRHE: Tiedostoa '" << tiedoston_nimi << "' ei voitu avata." << std::endl;
    exit (EXIT_FAILURE);
};

bool vahvistus (std::string viesti){
    std::string vastaus;
    do {
        std::cout << viesti << " vastaa Y tai N (Joo tai Ei): ";
        std::cin >> vastaus;
        if (vastaus == "Y" || vastaus == "y"){return true;}
        else if (vastaus == "N" || vastaus == "n"){return false;}
        else {std::cerr << "Hmm... onko se joo vai ei? Vastaa uudelleen!" << std::endl;}
    } while (vastaus == "N" || vastaus == "n");
    return false;
}

// hotelli huoneiden satunnainen parillinen luku
int satunnainen_huoneetmaara(){
    static std::random_device rd ();
    static std::default_random_engine rand ();
    static std::uniform_int_distribution <int> randomi {40 , 300};
    int kokonais = randomi (rand);
    if (kokonais % 2 != 0){return kokonais+=1;}
    return kokonais;
}

std::vector <int> yksih;
yksih.resize (satunnainen_huoneetmaara()/2);
std::vector <int> parih;
parih.resize (satunnainen_huoneetmaara()-yksih.size());

// huoneen numeron määrittely 
// huoneen vapauksesta kannattaa ottaa huolta 
int huonenumerot (const std::vector<int>& tyyppi){
    int huoneen_numero;
    for (int n : tyyppi){
        huoneen_numero = ((tyyppi[n]/10)+1)*100 + (tyyppi[n]%10);
        if (tyyppi[n]/10){huoneen_numero++;}
    }
    return huoneen_numero;
}

// tarkistaa tiedoston sisältö
void tiedoston_tarkistus (const std::string& tiedosto, std::ifstream& input){
    input.open (tiedosto);
    if (input.is_open()){
        input.seekg (0, std::ios::end);
    }
    else {tulosta_virhe(tiedosto)};
}

// kirjoita tiedostoon
void kirjoitus_numero (const std::string& tiedosto, int n){
    std::ofstream out;
    out.open (tiedosto); 
    out << n;
    /*if (input.tellg >= 3){
        out (tiedosto, std::ios::app);
        out << n;
    }*/
};

void lukema_numero (const std::string& tiedosto, std::string lause){
    std::ifstream in (tiedosto);
    tiedoston_tarkistus (tiedosto, in);
    int n;
    while (in >> n) {
        std::cout << n << lause << std::endl;
    }
};

bool Vieras_tarkistus (const std::string& tiedosto, const std::string& nimi, int n){
    std::fstream Tieto (tiedosto, std::fstream::in);
    int rivi = 0;
    std::string line;
    try {
        while (std::getline (Tieto, line, ',')){
            rivi++;
            if (line.find(nimi) != std::string::npos){
            Tieto.seekg (0, std::ios::end);
                if (Tieto.tellg () <= n){
                return true;  
                }
            }
        }
    } catch (const std::exception&) {
        return false;
    }
    std::cout << "Pahoillaan, varattavien huoneiden määrä on täynnä." << std::endl;
    return false;
}

void varaus (std::string tiedosto, Vieras vieras) {
    using namespace std;
    fstream out;
    out.open (tiedosto, ios::out | ios::app);

    array<string, 4>syotto_vieras = {"Sukunimesi: ", "Huoneen tyyppi: ", "Huoneen määrä: ", "Öiden määrä: "};

    if (Vieras_tarkistus (tiedosto, vieras.nimi, vieras.huoneenmaara) == true){ 
        cout << syotto_vieras [0];
        cin >> vieras.nimi;
        cout << syotto_vieras [1];
        cin >> vieras.huonetyyppi;
        cout << syotto_vieras [2];
        cin >> vieras.huoneenmaara;
        cout << syotto_vieras [3];
        cin >> vieras.yonmaara;
        
        out << vieras.nimi << ", "
        << vieras.huonetyyppi << ", "
        << vieras.huoneenmaara << ", "
        << vieras.yonmaara << ", ";
        rivi ();
    } else {
        Vieras_tarkistus (tiedosto, vieras.nimi, vieras.huoneenmaara);
    }
};

std::array <double, 3>& prosentti = {0, 0.1, 0.2};
int alennus (int& hinta){
    int alennus_num = std::rand();
    RAND_MAX = 2;
    hinta*= prosentti [alennus_num];
    return hinta;
}


