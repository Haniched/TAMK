// V7_2_Suorakaide

#include <iostream>
using namespace std;

int suorakaide (int korkeus, int leveys){
    return korkeus*leveys;
}   

int main (){

    int leveys, korkeus;

    cout << "Anna suorakaiteen korkeus: ";
    cin >> korkeus;

    cout << "Anna suorakaiteen leveys: ";
    cin >> leveys;

    cout << "Laskettu pinta-ala on: " << suorakaide (korkeus,leveys);

    return 0;
}