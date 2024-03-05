#include <iostream>
using namespace std;

struct ajat{
 int tunti, min, sec;  
};

int aika_sekunneiksi (ajat in){
    return (in.tunti * 3600) + (in.min * 60) + in.sec;
}

ajat sekunnit_ajaksi(ajat in, int sekunnit){
    in.tunti = sekunnit / 3600;
    in.min = (sekunnit-in.tunti*3600)/60;
    in.sec = sekunnit-(in.tunti*3600+in.min*60);
    return in;
}

void print (ajat in){
    cout << in.tunti << " tuntia "
        << in.min << " minuuttia "
        << in.sec << " sekuntia on ";
}

int main (){
    ajat input;
    cout << "Anna tunnit: ";
    cin >> input.tunti;
    cout << "Anna minuutit: ";
    cin >> input.min;
    cout << "Anna sekunnit: ";
    cin >> input.sec;

    print (input);
    int sekunnit = aika_sekunneiksi(input);
    cout << sekunnit << " sekuntia joka on puolestaan ";

    print (sekunnit_ajaksi (input, sekunnit));
    cout << endl;

    return 0;
}