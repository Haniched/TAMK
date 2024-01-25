#include <iostream>
using namespace std;

struct aika_ty {
    int tunti, min, sec;
};

int aika_sekunneiksi (aika_ty in){
    return (in.tunti * 3600) + (in.min * 60) + in.sec;
}

aika_ty sekunnit_ajaksi(int sekunnit){
    aika_ty in;
    in.tunti = sekunnit / 3600;
    in.min = (sekunnit-in.tunti*3600)/60;
    in.sec = sekunnit-(in.tunti*3600+in.min*60);
    return in;
}

aika_ty aikojen_erotus (aika_ty ens, aika_ty toka){
    int sekunnit = aika_sekunneiksi(toka) - aika_sekunneiksi(ens);
    return sekunnit_ajaksi (sekunnit);
}

int main (){ 
    
    aika_ty aika_ens = {12, 40, 35};
    aika_ty aika_toka = {16, 12, 25}; 
    
    aika_ty aika_ero;
    aika_ero = aikojen_erotus (aika_ens, aika_toka);
    
    cout << "Aikojen ero on " << aika_ero.tunti << ':' << aika_ero.min << ':' << aika_ero.sec << endl;
    
    return 0;
}
