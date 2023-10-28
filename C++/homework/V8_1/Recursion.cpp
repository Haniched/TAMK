#include <iostream>
#include <string>

void rivi (){
    std::cout << "\n";
}

int kertoma(int num){
    if (num > 0){
        return num * (num -1);
    }
    else {
        return 0;
    }
}

int main (){
    int kertoma;
    int num;

    std::cout << "Anna kokonaisluku välille 0 - 16" << rivi();
    std::cin >> num;

    int tulos = kertoma;
    std::cout << "Luvun " << num << " kertoma on " << tulos;
}