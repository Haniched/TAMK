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
        for (int i = 0; i <= kokonaismaara; i++) {
            huoneet[i].hnum = huonenumero(i);
        }   
        // 3. 1인실 2인실 배정 (파일에 쓰기 직전에) 
        // Yksihenkilön/kaksihenkikön huoneen määräminen
        for (int i = 0; i <= kokonaismaara / 2; i++){
                huoneet[i].yksi_pari = 's';
        }
        for (int i = kokonaismaara / 2 + 1; i <= kokonaismaara; i++){
                huoneet[i].yksi_pari = 'd';
        }
        
        // 4. 쓴다.
        // Kirjoita ylä olevat hotellien tiedot teksti tiedostoon.
        kirjoitus_tiedot (HUONEINFO_FILE, huoneet, kokonaismaara);
    }

    // 여기선 호텔이 가지고 있는 정보를 출력해야한다. 예약한게 있을시 차감 당한 번호여야 함 (차감하는 코드 짜기를 잊지 말자) 
    // 여기까진 그냥 읽기만 하면됨 근데 문제는...
    /* 
    만약 방 타입에 따라 남은 방 수까지 공지할 경우 >> 방 타입에 따라 또 차감 해줘야 하는데, 하기 짜증남
    이걸 또 파일에 쓰는 함수를 만들고 방타입 전체 수 저장하는 변수를 만들고 그걸 또 예약 시스템에 링크해줘야하는데
    거기서 저장되는 변수가 정말 여기서 공지해주는 역할 말고는 없는 것 같음
    왜냐면 어차피 룸이 예약된 룸인지 아닌지는 csv 파일에서 읽기만 하면 되니까
    결정: 필요없는데 더 복잡해지기만 함, 그냥 멘트만 날린다 
    */
    else {
        tulosta ("Hotellissamme on tällä hetkellä varattavissa yksihenkilön sekä kahden henkilön huoneet.\n", true);
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
