#include "hotelli.hpp"

const std::string RAJA = "\n--------------------------------------------------------\n";

static void alkuteksti() {
    tulosta (RAJA, true);
    display_slowly ("           TERVETULOA HOTEL CALIFORNIAAN!\n                Onpas ihana paikka.\n");
};

static void lopputeksti() {
    display_slowly ("Kiitoksia käynnistä.\n");
    rivi();
};


int main (){
    // std::cout << __FUNCTION__ << std::endl;
    alkuteksti();
    tulosta (RAJA, true);

    std::ifstream in (TIETOKANTA);

    if (!in.is_open()) {
        // 방 갯수 사이즈의 vector 가 필요하다.
        // 이 vector에는 여러 정보가 담겨야 한다.
        // 1. 방 번호
        // 2. 싱글룸 또는 더블룸
        // 3. 게스트
        // 4. 몇 박
        std::vector <huonetiedot> huoneet;

        // 1. 방 갯수를 설정 (랜덤으로)
        // 1. Hotelli satunnainen huoneiden määrän asetus
        int kokonaismaara = satunnainen_huoneetmaara();

        // 2. 방 번호를 배정
        // 2. Huoneen numeroiden määräminen            
        huoneet.resize(kokonaismaara);
        for (int i = 0; i < kokonaismaara; i++) {
            huoneet[i].hnum = huonenumero(i);
        }   

        // 3. 1인실 2인실 배정 (파일에 쓰기 직전에) 
        // 3. Yksihenkilön/kaksihenkikön huoneen määräminen

        // jos kokonaismaara = 80, 
        // s = 0-39
        for (int i = 0; i < kokonaismaara / 2; i++){
            huoneet[i].tyyppi = 's';
        }
        // d = 40-79, 
        for (int i = kokonaismaara / 2; i < kokonaismaara; i++){
            huoneet[i].tyyppi = 'd';
        }
        
        // 4. 쓴다. 
        // 4. Kirjoita ylä olevat hotellien tiedot hotelli.txt tiedostoon.
        kirjoitus_tiedot (TIETOKANTA, huoneet, kokonaismaara);

    } else if (in.is_open()){ // 파일이 존재 할 경우, 호텔이 가지고 있는 총 방의 개수를 출력한다. 
        int kokonais = lukema_numero(TIETOKANTA);
        display_slowly ("   MEILTA LOYTYY ");
        std::cout << kokonais/2 << " SINGLE SEKA "<< kokonais/2 << " DOUBLE HUONEETTA" << std::endl;
        tulosta (RAJA, true);
    } else {tulosta_virhe(TIETOKANTA);}

    /* 사용자의 예약 여부 의사를 확인한다
    if (!vahvistus ("Haluatko varata? ")) {
        std::cout << "Selvä, toivotaan nähdämme uudestaan!" << std::endl;
        return 0;
    }*/ 
    
    Vieras vieras1;
    int kokolasku = 0;

    do {
        
        // 예약가능한 방이 있는지 확인한다
        if (taysi(vieras1) == '0'){
            display_slowly ("Valitettavasti hotellissamme on ei ole vapaita huoneita täällä hetkellä.\n");
            break;
        }
         // 사용자가 정보를 입력한다
        tulosta ("Syota alle...\n", true);
        // 이미 예약한 사용자인지 이름을 파일에서 찾고, 있다면 출력하기
        if (!varaus_nimi(vieras1)){
            break;
        }
        varaus (vieras1);
        tulosta (RAJA, true);


        switch (taysi(vieras1)) {

            // 파일에 적기 kirjoita tiedostoon syotetty tiedot
            case '1': {
                kirjoitus_varaus (vieras1);   
                int laskusi = lasku(vieras1);
                // 가격 출력 tulostaa hinta
                std::cout << "\nVarauskesi nimellä '" << vieras1.nimi << "' on tehty." << std::endl;
                kokolasku = kokolasku + laskusi;
                break;
            }

            // Kayttajan syotetty huonetyyppi on kaikki varattu, mutta kun toinen tyyppi on saatavilla 
            case '2':
                if (vieras1.tyyppi == "s"){
                    tulosta ("Meidan SINGLE huoneet ovat taynna, ", false); 
                } else if (vieras1.tyyppi == "d"){
                    tulosta ("Meidan DOUBLE huoneet ovat taynna, ", false); 
                } 
                tulosta ("Syotta joku toiseen tyyppinen huone.", true);
                break;

            default:
                tulosta ("Unexpected error occured in switch", true);
        }

        tulosta (RAJA,false);

    } while (vahvistus("Haluatko varata lisää? "));
    
    if (kokolasku > 0){
        std::cout << alennushinta(kokolasku) << " euroa yhteensä. \n" << std::endl;
    }

    lopputeksti();

    return 0;
}
