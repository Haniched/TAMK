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
        // 2. 게스트
        // 3. 싱글룸 또는 더블룸
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
        // jos kokonaismaara = 80, s = 0-39
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
    }

    // 파일이 존재 할 경우, 호텔이 가지고 있는 정보를 출력한다. 
    else {
        int kokonais = lukema_numero(TIETOKANTA);
        tulosta ("Hotellissamme on ", kokonais, " huoneetta.\n", true);
    }

    /* 사용자의 예약 여부 의사를 확인한다
    if (!vahvistus ("Haluatko varata? ")) {
        std::cout << "Selvä, toivotaan nähdämme uudestaan!" << std::endl;
        return 0;
    }*/ 
    
    Vieras vieras1;
    int kokolasku = 0;

    do {
         // 사용자가 정보를 입력한다
        tulosta ("Syötä alle...", true);
        varaus (vieras1);
        rivi ();


        // 싱글룸 101호 2박
        // 싱글롬 102호 3박
        // 당신은 위와같이 방들을 예약하셨습니다
        // 더 예약하시겠습니까?

        // 이미 예약한 사용자인지 파일에서 찾고, 있다면 출력하기
        if (varattu (vieras1)){
            if (!vahvistus("Haluatko pitää syötetty varauksesi? ")){
                std::cout << "\n";
                if (!vahvistus("Jos haluat varata uudella tiedolla, paina [Y].\nJos haluat vaan lopettaa tämä sessio, paina [N]\n")){
                    lopputeksti();
                    return 0;
                } else {
                    tulosta ("Syötä alle...", true);
                    varaus (vieras1);
                    rivi();
                }
            }
        }


        /*if (예약함) {
            출력 101,s,nimi,2 Olet vrautettu nimellä nimi, s tyyppinen huone numero 101, 3 yötä. 
            if (!더 예약할 건지 물어봄())
                종료
        }*/

        // 예약가능한 방이 있는지 확인한다
        std::ifstream in (TIETOKANTA);
        std::string line;
        bool taysi = false;
        while (std::getline(in, line)){
            if ((get_nth_column(line, 1)) == vieras1.tyyppi && (get_nth_column(line, 2)) != "") {
                if (vieras1.tyyppi == "s"){
                    tulosta ("Meidän yhden hengen huoneet ovat täynnä.", true); 
                } else {
                    tulosta ("Meidän kahden hengen huoneet ovat täynnä.", true); 
                }
            } else {
                taysi = true;
            }
        }
        
        if (taysi) {
            kirjoitus_varaus (vieras1);
            // 가격 출력 tulostaa hinta
            int laskusi = lasku(vieras1);
            std::cout << "Laskusi on " << laskusi << " euroa.\n";
            std::cout << "\nVarauskesi nimellä '" << vieras1.nimi << "' on tehty.\n" << std::endl;
            kokolasku = kokolasku + laskusi;
        }

        
        
    } while (vahvistus("Haluatko varata lisää? "));

    tulosta ("\nYhteensä ", kokolasku, " euroa.\n", true);

    lopputeksti();

    return 0;
}
