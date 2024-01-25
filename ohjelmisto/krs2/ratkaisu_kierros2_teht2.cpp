#include <iostream>
#include <cmath>
using namespace std;

int alas (float luku){
    return floor(luku);
}

int ylos (float luku){
    return ceil (luku);
}

int main (){

    float luku;
    cout << "Anna luku: ";
    cin >> luku;

    cout << "Luku " << luku << " sisaltyy valille [ " << alas(luku) << ", " << ylos(luku) << " ]." << endl;
    return 0;
}