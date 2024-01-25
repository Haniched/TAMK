// V11_2 Renkaan koko

#include <iostream>
#include <iomanip>
#include <cmath>

float ulkohalkasija (int leveys, int korkeus, int vanne){
    float tuuma = 25.4;
    float ulkohalka = tuuma*vanne + 2*leveys* korkeus/100;
    return std::round (ulkohalka) /10;
}

float vierimiskeha (float halkasija){
    double kerroin = 3.049;
    float vierimis = halkasija * kerroin;
    return vierimis;
}

int main (){
    using namespace std;
    int leveys, korkeus, vanne;
    float halkasija;
    cout << "Anna renkaan leveys millimetreinä: " << '\n';
    cin >> leveys;
    cout << "Anna renkaan korkeusprofiili prosentteina leveydestä: " << '\n';
    cin >> korkeus;
    cout << "Anna vanteen halkaisija tuumina: " << '\n';
    cin >> vanne;

    halkasija = ulkohalkasija (leveys, korkeus, vanne);
    cout << "Renkaan halkaisija on " << std::fixed << std::setprecision(1) << halkasija << " senttimetriä." << '\n';
    cout << "Renkaan vierimiskehä on "<< std::fixed  << std::setprecision(1) << vierimiskeha (halkasija) << " senttimetriä." << '\n';

    return 0;
}
