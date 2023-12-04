#include "hotelli.hpp"

static void alkuteksti() {
    tulosta ("Terveltuloa Hotelli Californiaan! Onpas ihana paikka.\n", true);
};

int main (){
    
    alkuteksti();

    if (!tiedoston_tarkistus(HUONEINFO_FILE)) {
        // 방 갯수 사이즈의 vector 가 필요하다.
        // 이 vector에는 여러 정보가 담겨야 한다.
        // 1. 방 번호
        // 2. 게스트
        // 3. 싱글룸 또는 더블룸
        std::vector <huonetiedot> huoneet;

        // 1. 방 갯수를 설정 (랜덤으로)
        // Hotelli satunnainen huoneiden määrän asetus
        int kokonaismaara = satunnainen_huoneetmaara();

        // 2. 방 번호를 배정
        // Huoneen numeroiden määräminen
        // 지금 코드를 출력하면 1층을 제외한 다른 층은 방 호수가 1-10까지 출력되는데 1층은 9까지 밖에 없다
        // 1층에는 로비가 있어서 공간이 부족하다고 둘러대자 
        huoneet.resize(kokonaismaara);
        for (int i = 1; i <= kokonaismaara; i++) {
            huoneet[i].hnum = huonenumero(i);
        }   
        // 3. 1인실 2인실 배정 (파일에 쓰기 직전에) 
        // Yksihenkilön/kaksihenkikön huoneen määräminen
        // jos kokonaismaara = 80, yksi = 1-40
        for (int i = 1; i <= kokonaismaara / 2; i++){
                huoneet[i].yksi_pari = 's';
        }
        // pari = 41-80, 
        for (int i = kokonaismaara / 2 + 1; i <= kokonaismaara; i++){
                huoneet[i].yksi_pari = 'd';
        }
        
        // 4. 쓴다.
        // Kirjoita ylä olevat hotellien tiedot teksti tiedostoon.
        kirjoitus_tiedot (HUONEINFO_FILE, huoneet, kokonaismaara);
    }

    // 여기선 호텔이 가지고 있는 정보를 출력해야한다. 예약한게 있을시 차감 당한 번호여야 함 (차감하는 코드 짜기를 잊지 말자) 

    else {
        int kokonais = lukema_numero (HUONEINFO_FILE);
        tulosta ("Hotellissamme on tällä hetkellä varattavissa ", kokonais, false);
        tulosta (" huoneet, jotka ovat yhden sekä kahden henkilön huoneita.", true);
    }

    // 사용자의 예약 여부 의사를 확인한다
    if (!vahvistus ("Haluatko varata?")) {
        std::cout << "Selvä, toivotaan nähdämme uudestaan!" << std::endl;
        return 0;
    } 
    
    // 사용자가 정보를 입력한다
    Vieras vieras1;
    tulosta ("Syötä alle...", true);
    varaus (vieras1);
    
    // 이미 예약을 한 사용자인지 확인한다

    // 예약을 한 사용자가 아니면 파일에 정보를 쓴다
    
    
    return 0;
}
