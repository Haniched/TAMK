#include <iostream>
using namespace std;

struct aika_ty {
    int tunti, min, sec;
};

int main (){
    
    aika_ty aika;
    
    bool on = true;
    do {
        cout << "Anna tunnit: ";
        cin >> aika.tunti;
        cout << "Anna minuutit: ";
        cin >> aika.min;
        cout << "Anna sekunnit: ";
        cin >> aika.sec;
        if (aika.tunti < 0 || aika.tunti > 23){
            cerr << "Virhe: HH 0-23" << endl;
        } else if (aika.min < 0 || aika.min > 59){
            cerr << "Virhe: MM 0-60" << endl;
        } else if (aika.sec < 0 || aika.sec > 59){
            cerr << "Virhe: SS 0-60" << endl;
        } else {
            on = false;
        }
    } while (on);

    cout << "Aika on " << aika.tunti << ':' << aika.min << ':' << aika.sec << endl;
    
    aika_ty *aikaptr = &aika;

    cout << "Pointer " << (*aikaptr).tunti << ':' << (*aikaptr).min << ':' << (*aikaptr).sec << endl;

    aika_ty org_aika = {15, 47, 10};
    aika_ty ver_aika = org_aika;

    if (org_aika.tunti == ver_aika.tunti && org_aika.min == ver_aika.min && org_aika.sec == ver_aika.sec){
        cout << "Vertailu " << org_aika.tunti << ':' << org_aika.min << ':' << org_aika.sec << endl;
    }

    return 0;
}
