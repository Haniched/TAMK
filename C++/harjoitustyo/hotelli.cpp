#include "hotelli.hpp"

std::array <float, 3> prosentti = {0, 0.1, 0.2};

static std::string sym_to_typ (std::string tyyppi) {
    if (tyyppi == "s"){
        return "single";
    }
    return "double";
}

void rivi (){
    std::cout << '\n';
}
void tulosta (std::string t, bool RIVI){
    // std::cout << __FUNCTION__ << std::endl;
    std::cout << t;
    if (RIVI){rivi();}
};

void tulosta (std::string t, int& n, std::string s, bool RIVI){
    // std::cout << __FUNCTION__ << std::endl;
    std::cout << t << n << s;
    if (RIVI){rivi();}
};

void tulosta_virhe (std::string tiedoston_nimi){
    // std::cout << __FUNCTION__ << std::endl;
    std::cerr << "VIRHE: Tiedostoa '" << tiedoston_nimi << "' ei voitu avata." << std::endl;
};

bool vahvistus (std::string viesti){
    // std::cout << __FUNCTION__ << std::endl;
    std::string vastaus;
    do {
        std::cout << viesti << "(Y/N): ";
        std::cin >> vastaus;
        if (vastaus == "Y" || vastaus == "y"){return true;}
        else if (vastaus == "N" || vastaus == "n"){return false;}
        else {std::cerr << "Vastaa Y tai N:llä.\n" << std::endl; continue;}
    } while (true);
    return true;
}

int satunnainen_huoneetmaara(){
    // std::cout << __FUNCTION__ << std::endl;
    std::random_device rd;
    std::default_random_engine kone { rd() };
    std::uniform_int_distribution <int> randomi { 2, 10 };
    
    int kokonais = randomi(kone);
    
    if (kokonais % 2 != 0) {
        return kokonais += 1;
    }
    return kokonais;
}

// huoneen vapauksesta kannattaa ottaa huolta 
int huonenumero(int num) {
    // std::cout << __FUNCTION__ << std::endl;
    num++;
    int huoneen_numero = ((num / 10) + 1) * 100 + (num % 10);
    if (num / 10) {
        return ++huoneen_numero;
    }
    return huoneen_numero;
}

// get a guitar
std::string get_nth_column (std::string line, int n){
    // std::cout << __FUNCTION__ << std::endl;
	std::string column;
	std::istringstream stream(line);

	while (std::getline(stream, column, ',')) {
		if (n == 0) {
			break;
		}
		n--;
	}
	if (n != 0) {
        return "";
	}
	return column;
}
/*
 현재 구현 상황
 예약 하고 싶나 아닌가
 루프 시작
    1. 사용자 정보 입력
    2. (TODO)예약가능한 방이 있는지 확인
    3. 파일에 씀
    3. 가격을 출력함
    4. 더 예약 할건지 물어봄
        if Yes, return to 1
        if no, exit the loop
예약을 한 동안 계산된 모든 가격을 출력하고 종료
*/




/*
 예약 하고 싶나 아닌가
 루프 시작 do-while (더 예약할 것임?)
    1. 사용자 정보 입력
    2. (TODO)이미 예약한 사용자인지 파일에서 찾기
        1. 이미 예약한 사용자라면 그 정보를 출력해줌, if-else(위에 입력한 정보로 계속 예약할까?)
            if Y, 3번으로
            if N, shut down 
        2. 아니라면, 3번으로
    3. TODO 예약가능한 방이 있는지 확인
        1. 있으면 4번으로
        2. 없으면 shut down
    4. 파일에 사용자가 입력한 정보를 씀
    5. TODO (할인율 전) 가격을 출력함
    6. 더 예약 할건지 물어봄
        if Yes, return to 1
        if no, 루프 종료
할인율이 적용된 최종 가격을 출력하고 프로그램 종료
*/   

/*
만약 2번에서 예약한 방 가격까지 출력하고 싶은가?
No
*/

// 만약에, 할인율을 안빼면
// 1. 사용자가 정보를 입력함
// 2. 프로그램은 이미 예약한 사용자인지 아닌지 이름을 파일에서 찾음
//      찾았다면, 그 정보를 출력하고 더 예약 할 것 인지 물어봄          
//      못찾았다면 가격을 출력 그리고 3번으로 continue
// 3. 더 예약하시겠습니까??



void kirjoitus_tiedot (const std::string &txt, std::vector <huonetiedot> &tieto, int &MAX){
    // std::cout << __FUNCTION__ << std::endl;
    std::ofstream out (txt);
    if (out.is_open()){
        for (int i = 0; i < MAX; i++){
            out << tieto[i].hnum << ','
                << tieto[i].tyyppi << ',' << '\n';
        }
    }
};

int lukema_numero (const std::string &txt){
    // std::cout << __FUNCTION__ << std::endl;
    std::ifstream in (txt);
    int numero = 0;
    std::string rivi;
    while (std::getline(in, rivi)){
        ++numero;
    }
    return numero;
}

// 1. 사용자 정보를 받는 함수
void varaus (Vieras &vieras) {
    // std::cout << __FUNCTION__ << std::endl;

    using namespace std;

    array<string, 4> syotto_vieras = {"      sukunimesi      : ", 
                                      " huoneen tyyppi (s/d) : ", 
                                      " öiden määrä (numero) : "};

    cout << syotto_vieras [0];
    cin >> vieras.nimi;

    // vieras.tyyppi syöttö
    bool syotto = true;
    do {
        cout << syotto_vieras [1];
        cin >> vieras.tyyppi;
        if (vieras.tyyppi == "s" || vieras.tyyppi == "d"){
            syotto = true;
        } else {
            cerr << "Syotä 's' tai 'd'.\ns: Yhden hengen huone\nd: kahden hengen huone" << endl;
            syotto = false;
        }
    } while (syotto == false);

    // vieras.yo syöttö
    do {
        cout << syotto_vieras [2];
        if (!(cin >> vieras.yo)){
            cerr << "Syötä numeroina, kiitos." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
};

// 2. 사용자가 입력한 정보를 확인하는 함수
bool varattu (Vieras &vieras){
    // std::cout << __FUNCTION__ << std::endl;
    std::ifstream in (TIETOKANTA);
    std::string line;
    bool found = false;
    while (std::getline (in, line)){
        if (vieras.nimi == get_nth_column(line, 2)){
            found = true;
            std::cout << sym_to_typ(get_nth_column (line, 1)) << ", "
                      << get_nth_column (line, 0) << ", "
                      << get_nth_column (line, 3) << " yötä." << std::endl;
        }
    }
    if (found) {
        std::cout << "Ylä oleva huoneet ovat, jotka olet varannut aiemmin.\n" << std::endl;
        return true;
    }
    return false;
}

// 3. 예약가능한 방이 있는지 확인하는 함수


// kun kirjoita käyttäjältä syötetty tiedot tiedostoon, 
// ensin etsi sopiva huonetyyppi jonka syotetty, sitten syötä nimi, huoneen maara, yonmaara


// 1. 원본파일을 한 줄 씩 읽어서 수정하고 싶은 라인을 찾는다.
//     a. 게스트가 예약하고싶은 방타입이 매치가 된 경우
//     b. 빈방인 경우
// 2. 찾은 라인을 수정한다.
//     a. 방번호, 방타입 + 사용자가 입력한 내용을 struct huonetiedot 으로 만들어야함.
// 3. 임시파일을 만든 후 원본파일에서 라인을 한 줄 씩 임시파일로 쓴다.
// 4. 만약 라인이 수정되었다면 원본파일에서 가져온 라인 대신 수정된 라인을 쓴다.
// 5. 파일을 끝까지 다 쓰면 임시파일의 이름을 원본파일로 변경한다.
// 6. 임시파일을 삭제한다.

// 참고로 얘는 랜덤한 할인율을 생성해주는 함수다. 기특한넘...
static float luo_ale (void) {
    // std::cout << __FUNCTION__ << std::endl;

    std::random_device rd;
    std::default_random_engine kone { rd() };
    std::uniform_int_distribution <int> randomi { 0, 2 };
    int alennus_num = randomi(kone);
    return prosentti[alennus_num];
}

// 1. 원본에서 한줄 읽음
// 101,s,intaek,1,0.1
// 102,s
// 2. 원본 방번호와 uusi_varaus 방번호가 일치하면 원본 게스트이름이 있는지 확인
//      a. 원본에 게스트이름이 있으면 3으로
//      b. 원본에 게스트이름이 없으면 4로
//
// 3. 원본에서 읽은 줄을 그대로 임시에 씀
// 4. uusi_varaus 를 임시에 씀
// 

// 1. 첫번째 예약시 할인율이 지정됨
//     a. 사용자 인풋 입력이 끝나면 파일에 씀
// 2. 두번째 예약시 이미 지정된 할인율을 그대로 가져다 씀
//     b. 사용자 인풋 입력이 끝나면 파일에 씀
// 3.
// :
// n. 사용자가 더 예약하겠냐는 프로그램의 질문에 No 라고 답하면
//      총 가격 계산해서 출력


struct huonetiedot luo_varaus(Vieras &vieras) {
    // std::cout << __FUNCTION__ << std::endl;

    std::ifstream in (TIETOKANTA);
    std::string line;

    struct huonetiedot uusi_varaus; // == luo_varaus
    while (std::getline (in, line)){
        if ((get_nth_column(line, 1)) == vieras.tyyppi &&
            (get_nth_column(line, 2)) == "") {
            uusi_varaus.hnum = stoi (get_nth_column(line, 0));
            uusi_varaus.tyyppi = get_nth_column(line, 1);
            uusi_varaus.nimi = vieras.nimi;
            uusi_varaus.yo = vieras.yo;
            break;
        }
    }
    return uusi_varaus;
}


void kirjoita_tallennus (struct huonetiedot uusi_varaus){
    std::ifstream in (TIETOKANTA);
    std::ofstream out (TALLENNUS);

    std::string line;
    while (std::getline(in, line)){
        int hnum = stoi (get_nth_column(line, 0)); // string to int
        std::string nimi = get_nth_column(line, 2);
        // kirjoita tiedostoon vain stringina 
        if (hnum == uusi_varaus.hnum && nimi == "") {
            out << std::to_string(uusi_varaus.hnum) << ','
                << uusi_varaus.tyyppi << ','
                << uusi_varaus.nimi << ','
                << std::to_string (uusi_varaus.yo) << '\n';
        } else {
            out << line << '\n';
        }
    }
}
    
void kirjoitus_varaus (Vieras& vieras){
    // std::cout << __FUNCTION__ << std::endl;
    struct huonetiedot uusi_varaus = luo_varaus(vieras);
    kirjoita_tallennus(uusi_varaus);
    std::rename (TALLENNUS, TIETOKANTA);
}

// 가격 출력하기
// 여기서 필요한건 파일에 적은 할인율, 방타입, 몇박, 이름
// 
int lasku (Vieras& vieras){

    float alennus = luo_ale();
    int hinta = 0;
    int alku_hinta = 0;

    if (alennus != 0){
        std::cout << "Saat " << alennus*100 << '%' << " alennusta, ";
    }
    if (vieras.tyyppi == "s"){
        alku_hinta = 100*vieras.yo;
        hinta = alku_hinta - (alennus*alku_hinta);
    } else if (vieras.tyyppi == "d"){
        alku_hinta = 150*vieras.yo;
        hinta = alku_hinta - (alennus*alku_hinta);
    }
    return hinta;
}