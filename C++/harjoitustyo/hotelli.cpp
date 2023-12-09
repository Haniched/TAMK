#include "hotelli.hpp"

std::array <float, 3> prosentti = {0, 0.1, 0.2};

std::array<std::string, 4> syotto_vieras = {
    "sukunimesi           : ", 
    "huoneen tyyppi (s/d) : ", 
    "yon maara (numero)   : "
};

// s를 single로, d를 double로 변환해줌
static std::string sym_to_typ (std::string tyyppi) {
    if (tyyppi == "s"){
        return "SINGLE";
    }
    return "DOUBLE";
}

// 랜덤한 할인율을 생성해주는 함수
static float luo_ale () {
    // std::cout << __FUNCTION__ << std::endl;

    std::random_device rd;
    std::default_random_engine kone { rd() };
    std::uniform_int_distribution <int> randomi { 0, 2 };
    int alennus_num = randomi(kone);
    return prosentti[alennus_num];
}

// FUNKTIOT

void rivi (){
    std::cout << '\n';
};
void tulosta (std::string t, bool RIVI){
    // std::cout << __FUNCTION__ << std::endl;
    std::cout << t;
    if (RIVI){rivi();}
};

void tulosta_virhe (std::string tiedoston_nimi){
    // std::cout << __FUNCTION__ << std::endl;
    std::cerr << "VIRHE: Tiedostoa '" << tiedoston_nimi << "' ei voitu avata." << std::endl;
};

void display_slowly (const std::string &text){
    for (const char &ch : text){
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(
            std::chrono::milliseconds(20)
        );
    }
};

bool vahvistus (std::string viesti){
    // std::cout << __FUNCTION__ << std::endl;
    std::string vastaus;
    do {
        std::cout << viesti << "(Y/N): ";
        std::cin >> vastaus;
        rivi ();
        if (vastaus == "Y" || vastaus == "y"){return true;}
        else if (vastaus == "N" || vastaus == "n"){return false;}
        else {std::cerr << "Vastaa Y tai N:llä.\n" << std::endl; continue;}
    } while (true);
    return true;
}

// Satunnainen hotellin huoneiden kokonaismäärän generaattori parillinen luku välillä 40 - 300
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

// huoneen numeron määrittely 
int huonenumero(int num) {
    // std::cout << __FUNCTION__ << std::endl;
    num++;
    int huoneen_numero = ((num / 10) + 1) * 100 + (num % 10);
    if (num / 10) {
        return ++huoneen_numero;
    }
    return huoneen_numero;
}

// Reading the line
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

// File stream using functions
//-----------------------------------------------------------------------------------------
void kirjoitus_tiedot (const std::string &txt, std::vector <huonetiedot> &tieto, int &MAX){
    // std::cout << __FUNCTION__ << std::endl;
    std::ofstream out (txt);
    if (out.is_open()){
        for (int i = 0; i < MAX; i++){
            out << tieto[i].hnum << ','
                << tieto[i].tyyppi << ',' << '\n';
        }
    } else {tulosta_virhe(txt);}
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
// kun kirjoita käyttäjältä syötetty tiedot tiedostoon, 
// ensin etsi sopiva huonetyyppi jonka syotetty, sitten syötä nimi, huoneen maara, yonmaara

// [0] vieras.nimi syotto
// 싱글룸 101호 2박
// 싱글롬 102호 3박
// 당신은 위와같이 방들을 예약하셨습니다
// 더 예약하시겠습니까?
bool varaus_nimi (Vieras &vieras) {
    using namespace std;
    cout << syotto_vieras [0];
    cin >> vieras.nimi;
    if (onko_varattu (vieras)){
        if (!vahvistus("Haluatko varata lisaa? ")){
            return false;
        }
    } 
    return true;
}

void varaus (Vieras &vieras) {
    // std::cout << __FUNCTION__ << std::endl;
    using namespace std;

    // [1] vieras.tyyppi syöttö
    bool syotto = true;
    do {
        cout << syotto_vieras [1];
        cin >> vieras.tyyppi;
        if (vieras.tyyppi == "s" || vieras.tyyppi == "d"){
            syotto = true;
        } else {
            cerr << "Syota 's' tai 'd'.\ns: single huone\nd: double huone" << endl;
            syotto = false;
        }
    } while (syotto == false);

    // [2] vieras.yo syöttö
    do {
        cout << syotto_vieras [2];
        if (!(cin >> vieras.yo)){
            cerr << "Syota numeroina, kiitos." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
};

// 2. 사용자가 입력한 정보를 확인하는 함수
bool onko_varattu (Vieras &vieras){
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
        std::cout << "Yla oleva huoneet ovat, jotka olet varannut aiemmin.\n" << std::endl;
        return true;
    }
    return false;
}

// 3. 예약가능한 방이 있는지 확인하는 함수
char taysi (Vieras &vieras){
    std::ifstream in (TIETOKANTA);
    std::string line;
    if (!in.is_open()){tulosta_virhe(TIETOKANTA);}
    while (in){
        getline(in, line);
        if (get_nth_column(line, 2) == ""){ // JOS nimikentta on tyhja 
            if (get_nth_column(line, 1) == ""){ // empty line, file reader has been reached till the end, 
                break; // so no available room
            } else if (get_nth_column(line, 1) == vieras.tyyppi){ // if (matches with user input room type) 
                return '1'; 
                break; // proceed to booking
            } else if (get_nth_column(line, 1) != vieras.tyyppi){ 
                if (get_nth_column (line, 2) != ""){
                    continue;
                    return '2'; // input room type is all booked alr but not the other one
                } else {
                    break;
                }
            } 
        } else {
            continue; // keep reading
        }
    }
    return '0';
}

/* 위의 taysi 로직
0,1,2,3
101,s,name,night

맨처음
d를 넣었을 때,
2는 비어있으므로, != 이 있는 곳으로 넘어감 get은 s부터 시작
인풋과 일치하지 않을떄, 
    그 일치하지 않는 타입이 다 차있는 경우 리턴 2
    차있지 않은 경우 continue

if [2] (이름) 가 비어있다
    if [1] (룸 타입)이 비어있다
        파일의 마지막 비어있는 줄을 읽은 것이므로, 방에 모든 예약이 꽉차있다, 프로그램 종료
    else if 룸타입이 유저인풋과 일치한다
        예약 가능
    else if 룸타입이 유저인풋과 일치 하지 않는다 (여기서문제)
        이 룸타입은 예약 불가능, 다른 룸타입은 비어있다
else 계속 읽는다

여기서 생기는 문제는, 맨 처음에 예약을 할 때 더블룸을 한다고 치면, 맨 처음으로 읽는 줄은 당연히... d와 일치하지 않으므로 예약 불가능하다고 나온다 
읽은 룸타입과 입력한 룸타입과 다르지만 그 뒤가 비어있다면 라인에서 읽은 그 다른 룸타입은 예약가능한거다

*/

// 파일에 옮겨적기 위한 아주 긴긴과정...

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

// 가격 출력하기 (할인율 없음)
int lasku (Vieras& vieras){
    int hinta = 0;
    if (vieras.tyyppi == "s"){
        hinta = 100*vieras.yo;
    } else if (vieras.tyyppi == "d"){
        hinta = 150*vieras.yo;
    }
    std::cout << "Laskusi on " << hinta << " euroa.\n";
    return hinta;
}

// 최종가격에 할인율 적용된 가격 출력하기
int alennushinta (int &hinta){
    float alennus = luo_ale();

    if (alennus != 0){
        std::cout << "Saat " << alennus*100 << '%' << " alennusta, ";
    }
    return hinta - (alennus*hinta);
}