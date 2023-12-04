#include "hotelli.hpp"


void tulosta (std::string t, bool RIVI){
    std::cout << t;
    if (RIVI){std::cout << '\n';}
};

void tulosta (std::string t, int& n, bool RIVI){
    std::cout << t << n;
    if (RIVI){std::cout << '\n';}
};

void tulosta_virhe (std::string tiedoston_nimi){
    std::cerr << "VIRHE: Tiedostoa '" << tiedoston_nimi << "' ei voitu avata." << std::endl;
};

bool vahvistus (std::string viesti){
    std::string vastaus;
    do {
        std::cout << viesti << " vastaa Y tai N: ";
        std::cin >> vastaus;
        if (vastaus == "Y" || vastaus == "y"){return true;}
        else if (vastaus == "N" || vastaus == "n"){return false;}
        else {std::cerr << "Vastaa uudelleen!\n" << std::endl; continue;}
    } while (true);
    return true;
}

int satunnainen_huoneetmaara(){
    std::random_device rd;
    std::default_random_engine kone { rd() };
    std::uniform_int_distribution <int> randomi { 40, 300 };
    
    int kokonais = randomi(kone);
    
    if (kokonais % 2 != 0) {
        return kokonais += 1;
    }
    return kokonais;
}

// huoneen vapauksesta kannattaa ottaa huolta 
int huonenumero(int& num) {
    int huoneen_numero = ((num / 10) + 1) * 100 + (num % 10);
    if (num / 10) {
        return ++huoneen_numero;
    }
    return huoneen_numero;
}

// tarkistaa tiedoston sisältö
bool tiedoston_tarkistus (const std::string& tiedosto){
    std::fstream file;
    file.open (tiedosto);
    if (file.is_open()) {
        return true;
    }
    tulosta_virhe();
    return false;
}

void kirjoitus_tiedot (const std::string &tiedosto, std::vector <huonetiedot> &tieto, int &MAX){
    std::ofstream out (tiedosto);
    tiedoston_tarkistus (tiedosto);
    for (int i = 1; i <= MAX; i++){
        out << '\n' 
            << tieto[i].hnum << ','
            << tieto[i].yksi_pari << ','
    }
};

int lukema_numero (const std::string& tiedosto){
    int numero = 0;
    std::string rivi;
    std::ifstream in (tiedosto);
    tiedoston_tarkistus (tiedosto);
    while (std::getline(in, rivi)){
        ++numero;
    }
    return numero;
}
// 사용자 정보를 받는 함수
void varaus (Vieras &vieras) {
    using namespace std;

    array<string, 4> syotto_vieras = {"sukunimesi: ", "huoneen tyyppi:  ", "huoneen määrä: ", "öiden määrä: "};

    cout << syotto_vieras [0];
    cin >> vieras.nimi;
    cout << syotto_vieras [1];
    cin >> vieras.huonetyyppi;
    cout << syotto_vieras [2];
    cin >> vieras.huoneenmaara;
    cout << syotto_vieras [3];
    cin >> vieras.yonmaara;
};


void kirjoita_syotto (const std::string &tiedosto, Vieras &vieras){
    std::ofstream out {tiedosto, std::ios::app};
    tiedoston_tarkistus (tiedosto);
    out << vieras.nimi << ','
        << vieras.huoneenmaara << ','
        << vieras.yonmaara << ',';
}

// 여기서 사용자가 입력한 이름을 읽고, 출력해야 한다?
// 아님 확인만 한다
// https://stackoverflow.com/questions/12463750/c-searching-text-file-for-a-particular-string-and-returning-the-line-number-wh
bool Vieras_tarkistus (const std::string& tiedosto, Vieras& vieras){
    std::ifstream in (tiedosto);
    try {
        while (std::getline (tiedosto, line)){
            if (line.find(vieras.nimi) != line.npos){
                return true;
            }
        }
    } catch (const std::exception&) {
        tulosta_virhe();
    }
    return false;
}



std::array <double, 3> prosentti = {0, 0.1, 0.2};

#define RAND_MAX 2 
int alennus (int& hinta){
    int alennus_num = std::rand();
    hinta*= prosentti [alennus_num];
    return hinta;
}


