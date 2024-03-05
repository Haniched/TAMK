#include "paivays.cpp"
using namespace std;

int main (){

    int kPaiva, kKausi, kVuosi;
    
    cout << "Syota taman paivan maara\nPaiva: ";
    cin >> kPaiva;
    cout << "Kuukausi: ";
    cin >> kKausi;
    cout << "Vuosi: ";
    cin >> kVuosi;

    paivays tanaan;
    tanaan.setPaiva(kPaiva);
    tanaan.setKuukausi(kKausi);
    tanaan.setVuosi(kVuosi);
    cout << "Tanaan ";
    tanaan.tulostaPaivays();

    paivays huomenna;
    huomenna.setPaiva(kPaiva+1);
    if (kPaiva == 31) {
        huomenna.setKuukausi(kKausi+1);
    }
    if (kKausi == 12) {
        kKausi = 1;
        huomenna.setVuosi(kVuosi+1);
    } else {
        huomenna.setVuosi(kVuosi);
    }
    cout << "Huomenna ";
    huomenna.tulostaPaivays();
    
    return 0;
}
