#include <iostream>
#include <vector>

void tulostaVektori (const std::vector<int>& alkiot){
    for (const int& alkio : alkiot){
        std::cout << alkio << ' ';
    }
    std::cout << '\n';
}

int main (){
    std::vector<int> luvut; 

    tulostaVektori (luvut);

    luvut.push_back(32);
    luvut.push_back(27);
    luvut.push_back(64);

    tulostaVektori (luvut);

    // lisätään vektorin alkuun uusi alkio
    luvut.insert(luvut.begin(), 42);
    tulostaVektori (luvut);

    // poistetaan alkio 27 
    luvut.erase(luvut.begin() +2);
    tulostaVektori (luvut);

    // tyhjennetään vectorin koko
    luvut.clear();
    tulostaVektori (luvut);
}