// for- loops Noppa peli

#include <iostream>
#include <cstdlib>

int main() {

     srand((unsigned) time(NULL));

    // Montako kertaa kukin silmaluku on tullut

        int n1 ( 0 );

        int n2 ( 0 );
        
        int n3 ( 0 );

        int n4 ( 0 );

        int n5 ( 0 );

        int n6 ( 0 );

    for (int i = 0; i < 10000; i++){

        int tulos ( 1 + (rand() % 6) );

        std::cout << tulos << " ";

        switch (tulos) {

            case 1: n1++; break;

            case 2: n2++; break;

            case 3: n3++; break;

            case 4: n4++; break;

            case 5: n5++; break;

            case 6: n6++; break;

            default: break;
        }
    }



std::cout 
    << n1 << " " 
    << n2 << " "
    << n3 << " "
    << n4 << " "
    << n5 << " "
    << n6 << " "
    << "\n";

std::cout << std::endl;

return 0;
}
