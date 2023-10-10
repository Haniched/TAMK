#include <iostream>
#include <cmath>

int main (){
    using namespace std;
    
    int luku;
    float tulos;
    bool lopeta { false };
    
    do {
        
        cout << "Valitse laskutoimitus (1=neliöjuuri, 2=log, 3=exp ja 4=tan, L=lopetus): ";
        int lasku;
        cin >> lasku;
        
        if (lasku == 1 || lasku == 2 || lasku == 3 || lasku == 4){
            cout << "Syötä luku: ";
            cin >> luku;
        }
        
        switch (lasku){
            case 1:
                tulos = sqrt(luku);
                cout << "Syöttämäsi luvun neliöjuuri on " << tulos << "\n";
                break;
                
            case 2:
                tulos = log(luku);
                cout << "Syöttämäsi luvun logaritmi on " << tulos << "\n";
                break;
                
            case 3:
                tulos = exp(luku);
                cout << "Syöttämäsi luvun exponenttifunktio on " << tulos << "\n";
                break;
                
            case 4:
                tulos = tan (luku);
                cout << "Syöttämäsi luvun tangentt on " << tulos << "\n";
                break;
                
            default:
                lopeta = true;
                break;
                
        }
    } while (!lopeta);
}
