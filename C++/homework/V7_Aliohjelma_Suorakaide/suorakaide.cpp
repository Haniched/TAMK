#include <iostream>

void suorakaide (){

    int korkeus;
    int leveys;
    int pintaala;

    std::cout << "Anna suorakaiteen korkeus: ";
    std::cin >> korkeus;

    std::cout << "Anna suorakaiteen leveys: ";
    std::cin >> leveys;

    pintaala = korkeus*leveys;
    std::cout << "Laskettu pinta-ala on: " << pintaala;

}

int main (){
    suorakaide ();
    return 0;
}