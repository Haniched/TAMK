// V11_3 Lotto
#include <iostream>
#include <array>
#include <random>

using namespace std;

//maarittellaan loton arvoa
array <int,7> lottonum = {2, 3, 10, 26, 29, 32, 37};
array <int,3> bonusnum = {11, 17, 27};


// konen random numero generaattori
random_device rd;
uniform_int_distribution <int> randomi {1,100};

// tulosta voittonumeroita
void voittonumerot (){
    cout << "\nJa voittonumerot ovat... "; 
    for (int num : lottonum){cout << num << ", ";} 
    cout << "ja bonusnumerot ";
    for (int num = 0; num < bonusnum.size()-1; num++){cout << bonusnum[num] << ", ";}
    cout << bonusnum [2] << ".\n"; 
}
// Lotto pelin toiminnon valintaminen
void toiminto (){
    cout << "\nMitä haluaisit tehdä? (Syötä numero 1-4)\n";
    array <string, 4> optio = {
        "Katso palkintosummat", 
        "Pelaa koneen arpomalla rivillä", 
        "Pelaa omilla numeroilla", 
        "Lopeta pelaaminen"
    };
    for (int i = 0; i < 4; i++){cout << i+1 << ": " << optio [i] << endl;}
}
// Palkintosummat taulukon tulostaminen (case 1)
void tulostapalkkio (){
    array <string,8> num = {"7","6+1","6","5","4","3+1","2","1"}; 
    array <string,8> euro = {"10 000 000 e","1 000 000 e", "100 000 e", "2000 e", "50 e", "10 e", "2 e", "1 e"};
    cout << "\nNumeroita + lisänumeroita oikein    " << "Voittosumma" << '\n';
    for (int i = 0; i < num.size(); i++){
        if (num[i].length() == 1){
          cout << num [i] << "                                   " << euro [i] << '\n';} 
        else {cout << num [i] << "                                 " << euro [i] << '\n';}
        
    }
}

// palkkio numeroiden tarkastelu ja tulostaminen
void palkkio(array<int, 7>& lottoarvo, array<int, 3>& bonusarvo) {
    long palkkioeuro = 0;
    array<long, 8> euro = {1,2,10,50,2000,100000,1000000,10000000};
    
    int lottopointCount = 0;
    for (int i = 0; i < lottoarvo.size(); ++i) {
        for (int j = 0; j < lottonum.size(); ++j) {
            if (lottoarvo[i] == lottonum[j]) {lottopointCount++;}
        }
    }
    int bonuspointCount = 0;
    for (int i = 0; i < bonusarvo.size(); ++i) {
        for (int j = 0; j < bonusnum.size(); ++j){
            if (bonusarvo[i] == bonusnum [j]) {bonuspointCount++;}
        }
    }
    // tulosta paljonko point saanut oikein
    cout << "\nSait " << lottopointCount << "+" << bonuspointCount << " oikein!\n";
    // tulosta saatava palkkio 
    if (lottopointCount != 0) {
        if (lottopointCount == 6 && bonuspointCount >= 1) {palkkioeuro = euro[6];}      // palkkio 6+1  
        else if (lottopointCount == 3 && bonuspointCount >= 1) {palkkioeuro = euro [2];} // palkkio 3+1
        else {palkkioeuro = euro[lottopointCount];};
        cout << "Olet voittanut " << palkkioeuro << " euroa!\n\n";
    } else {cout << "Voi harmi. Yrittäkääpäs toiseen kerran.\n";}    
}
int main (){
    cout << "Tervetuloa helppoon lottoon, voiton saaminen on helppoa!\n";

    int toimitus; // toiminnon valitseminen syotto numero
    array <int, 7> konelotto, omalotto; // lottonumerot 
    array <int, 3> konebonus, omabonus; // bonusnumerot 

    do {
        toiminto();
        cin >> toimitus; 
        switch (toimitus){
            case 1: 
                tulostapalkkio(); 
            break;

            case 2: // koneella arvotettuna numerolla
                // maarita konearvot
                for (int& num : konelotto){num = randomi (rd);} 
                for (int& num : konebonus){num = randomi (rd);} 
                // tulosta konearvo numerot
                cout << "\nLottorivisi on: ";
                for (int num : konelotto){cout << num << ", ";}  
                cout << "ja bonusnumerot ";
                for (size_t num = 0; num < konebonus.size()-1; num++){cout << konebonus[num] << ", ";}  
                cout << konebonus [2] << ".\n";
                voittonumerot(); // tulosta voittonumeroita
                palkkio (konelotto, konebonus); // tulosta arvastettu palkkioita
            break;

            case 3: // oma arvolla
                cout << "\nLottorivisi on\n";
                for (int& num : omalotto){cout << ":"; cin >> num;}
                cout << "ja bonusnumerot\n";
                for (size_t num = 0; num < omabonus.size(); num++){cout << ":"; cin >> omabonus[num];}
                cout << "\n";
                voittonumerot();
                palkkio (omalotto, omabonus); 
            break;

            default:
                break;
        }
        cout << "--------------------------------------------------------------------------------\n";
    } while (toimitus != 4);

    cout << "\nTervetuloa uudestaan.";
    return 0;
}