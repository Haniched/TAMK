#include <iostream>
using namespace std;

struct ajat{
 int tunti, min, sec; 
 double sekunnit;  
};

ajat sekunnit_ajaksi(){
    ajat in;
    cin >> in.sekunnit;
    in.tunti = in.sekunnit / 3600;
    in.min = (in.sekunnit-in.tunti*3600)/60;
    in.sec = in.sekunnit-(in.tunti*3600+in.min*60);
    return in;
}

int main (){
    ajat input;
    cout << "Sec: ";
    input = sekunnit_ajaksi();
    cout << input.sekunnit << " sekuntia on " 
        << input.tunti << " tuntia " 
        << input.min << " minuuttia "
        << input.sec << " sekuntia." << endl;
    return 0;
}