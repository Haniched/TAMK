// V11_3 Lotto

#include <iostream>
#include <array>
using namespace std;

//maarittellaan loton arvoa
array <int,7> lottonum = {2, 3, 10, 26, 29, 32, 37};
array <int,3> bonusnum = {11, 17, 27};

// konen random numero generaattori
std::random_device loto;
std::default_random_engine lottori { loto{} };
std::uniform_int_distribution kone {1, 100};
array <int, 7> konelotto, konebonus { kone (lottori) };

// tulosta voittonumeroita
void voittonumerot (){
    cout << "\nJa voittonumerot ovat... ";
    for (size_t i = 0; i < lottonum.size (); i++){cout << lottonum [i] << ", ";} 
    cout << " ja bonusnumerot ";
    for (size_t i = 0; i < bonusnum.size ()-1; i++){cout << bonusnum [i] << ", ";} 
}

// Lotto pelin toiminnot
void toiminto (){
    cout << "Mitä haluaisit tehdä? (Syötä numero 1-4)\n";
    array <string, 4> optio = {
        "Katso palkintosummat", 
        "Pelaa koneen arpomalla rivillä", 
        "Pelaa omilla numeroilla", 
        "Lopeta pelaaminen"
    }
    for (int i = 0; i < 4; i++){cout << i+1 << ": " << optio [i];}
}

// Palkintosummat taulukon tulostaminen (case 1)
void tulostapalkkio (){
    array <char, 8> num = {'7',"6+1",'6','5','4', "3+1",'2','1'};
    array <string,8> euro = {"10 000 000 e","1 000 000 e", "100 000 e", "2000 e", "50 e", "10 e", "2 e", "1 e"};
    
    cout << "Numeroita + lisänumeroita oikein    " << "Voittosumma" << '\n';
    for (size_t i = 0; i < num.size; i++){
        cout << num[i] << "                                   " <<  << euro [i] << '\n';
    }
}
// palkkion tulostaminen 
int palkkio (int lottopoint, int bonuspoint){
    int bonusnum = 1;
    long palkkioeuro;
    array <int, 7> lottonum = {7,6,5,4,3,2,1},
    array <long,8> euro = {10000000,1000000,100000,2000,50,10,2,1};
    if (lottopoint == lottonum [0]){palkkioeuro =  euro[0];}
    else if (lottopoint == lottonum [1], bonuspoint == bonusnum){palkkioeuro = euro [1];}
    else if (lottopoint == lottonum [2,3]){palkkioeuro = euro [2,3];}
    else if (lottopoint == lottonum [4], bonuspoint == bonusnum){palkkioeuro =  euro [4];}
    else if (lottopoint == lottonum [5,6]){palkkioeuro = euro [5,6];}
    cout << "Sait " << lottotarkistus(lottopoint) << "+" << bonustarkistus(bonuspoint) " oikein!\n";
    cout << "Olet voittanut " << palkkioeuro << " euroa!\n";
}

// lottonumeroiden tarkistaminen
int lottotarkistus(array <int,7>& lottoarvo) {
    int lottopoint = 0;
    for (size_t i = 0; i < lottonum.size; i++){
        if (lottoarvo[i] = lottonum[i]){
            lottopoint++;} 
    }
    return point;
}

// bonusnumeroiden tarkistaminen
int bonustarkistus (array <int,7>& bonusarvo){
    int bonuspoint = 0;
    for (size_t i = 0; i < bonusnum.size; i++){
        if (bonusarvo[i] = bonusnum[i]){
            bonuspoint++;}   
    }
    return bonuspoint;
}

int main (){
    cout << "Tervetuloa helppoon lottoon, voiton saaminen on helppoa!"

    int toimitus; // toiminnon valitseminen syotto numero
    array <int, 7> omalottonum, omabonusnum; // oma numerot (case 3)
    toiminto ();
    cin >> toimitus;

    do {
        tulostapalkkio ();
        if (toimitus = 1){palkkio();}
        else if (toimitus = 2){
            // tulosta konearvo numerot
            cout << "Lottorivisi on: ";
            for (size_t i = 0; i < konelotto.size (); i++){cout << konelotto [i] << ", ";}  
            cout << " ja bonusnumerot ";
            for (size_t j = 0; j < konebonus.size ()-1; j++){cout << konebonus [j] << ", " }
            cout << ".\n";
            voittonumerot(); // tulosta voittonumeroita
            // tarkista koneella arvastettu lottonumerot
            palkkio (konelotto, konebonus);
        } else if (tomitus = 3){
            cout << "Lottorivisi on: ";
            for (size_t i = 0; i < omalottonum.size (); i++){cin >> omalottonum [i] << ", ";}
            cout << " ja bonusnumerot ";
            for (size_t i = 0; i < omabonusnum.size ()-1; i++){cin >> omabonusnum [i] << ", ";}
            cout << ".\n";
            voittonumerot();
            palkkio (omalottonum, omabonusnum); 
        } 
        cout << "--------------------------------------------------------------------------------\n";
    } while (toiminto !=4)
    cout << "\nTervetuloa uudestaan." << endl;
}