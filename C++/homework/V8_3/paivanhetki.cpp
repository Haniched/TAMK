// V8_3 Paivanhetki

#include <iostream>
#include <string>
using namespace std;

std::string aika (int tunti){
    if (tunti >= 6 && tunti <= 11){
        cout << "aamu";
    }
    else if (tunti >= 12 && tunti <= 16){
        cout << "päivä";
    }
    else if (tunti >= 17 && tunti <= 22){
        cout << "ilta";
    }
    else {
        cout << "yö";
    }
}

int main (){
    int tunti;
    cout <<  "Anna kellonaika tunneissa (0-23): ";
    cin >> tunti;
    if (tunti >= 0 || tunti < 24)
    cout << "Hetki päivästä on " << aika (tunti);
}