#include "hotelli.hpp"

static void alkuteksti() {
    tulosta ("Terveltuloa Hotelli Californiaan! Onpas ihana paikka.\n", true);
};

static void lopputeksti() {
    tulosta ("Kiitoksia käynnistä.", true);
};

int main (){
    // std::cout << __FUNCTION__ << std::endl;
    alkuteksti();
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

    } else if (in.is_open()){
        // 파일이 존재 할 경우, 호텔이 가지고 있는 정보를 출력한다. 
        int kokonais = lukema_numero(TIETOKANTA);
        tulosta ("Hotellissamme on ", kokonais, " huoneetta.\n", true);

    } else {tulosta_virhe(TIETOKANTA);}

    /* 사용자의 예약 여부 의사를 확인한다
    if (!vahvistus ("Haluatko varata? ")) {
        std::cout << "Selvä, toivotaan nähdämme uudestaan!" << std::endl;
        return 0;
    }*/ 
    
    Vieras vieras1;
    int kokolasku = 0;

    do {
         // 사용자가 정보를 입력한다
        tulosta ("Syota alle...", true);
        // 이미 예약한 사용자인지 이름을 파일에서 찾고, 있다면 출력하기
        if (!varaus_nimi(vieras1)){
            break;
        }
        varaus (vieras1);
        rivi ();

        // 예약가능한 방이 있는지 확인한다
        if (taysi(vieras1) == "vapaa") {
            
             // 파일에 적기 kirjoita tiedostoon syotetty tiedot
            kirjoitus_varaus (vieras1);   

            int laskusi = lasku(vieras1);
            // 가격 출력 tulostaa hinta
            std::cout << "Laskusi on " << laskusi << " euroa.\n";
            rivi();
            std::cout << "Varauskesi nimellä '" << vieras1.nimi << "' on tehty." << std::endl;
            kokolasku = kokolasku + laskusi;
            
        } else if (taysi(vieras1) == "toinen vapaa"){
            if (vieras1.tyyppi == "s"){
                tulosta ("Meidän single huoneet ovat täynnä.", true); 
            } else if (vieras1.tyyppi == "d"){
                tulosta ("Meidän double huoneet ovat täynnä.", true); 
            } 
            // tulosta ("Syotta joku toiseen tyyppin huone.", true);
        } else {
            tulosta ("Hotellin kaikki huoneet ovat varattu.", true);
            break;
        }
        
        rivi();

    } while (vahvistus("Haluatko varata lisää? "));
    
    rivi ();

    if (kokolasku > 0){
        std::cout << "Yhteensä " << alennushinta(kokolasku) << " euroa.\n" << std::endl;
    }

    lopputeksti();

    return 0;
}
