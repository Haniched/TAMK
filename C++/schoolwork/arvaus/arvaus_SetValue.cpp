#include <iostream>

int main (){
    using namespace std; //vaikuttaa vain main ():in sisällä
    
    int luku ( 42 ); // luku, jota tietokone "ajattele"
    bool oikein = false; // oliko käyttäjän arvaus oikein vai ei
    
    
    cout << "Ajattelen jotain lukua väliltä 1...100. Arvaatko sen?\n";
    while (!oikein){
        cout << "Anna arvauksesi: ";
        int arvaus ( 0 );
        cin >> arvaus;
        
        if (arvaus < luku){
            cout << "Liian pieni!";
        }
        
        else if (arvaus > luku){
            cout << "Liian suuri!";
        }
        
        else {
            cout << "Oikein!";
            oikein = true;
        }
        cout << "\n";
    }
}