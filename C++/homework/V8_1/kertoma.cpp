// V8_1 kertomalasku

#include <iostream>

void rivi (){
    std::cout << "\n";
}

long kertoma(int num, long kertoma = 1){
    for (int i = 1; i <= num; ++i) {
        kertoma *= i;
    }
    return kertoma;
}

int main (){
    int num;

    std::cout << "Anna kokonaisluku välille 0 - 16";
    rivi();
    std::cin >> num;

    if (num < 0){
        std::cout << "Virhetilanne";
    }
    
    else if (num == 0){
        kertoma(0) == 1;
    }

    else {
    std::cout << "Luvun " << num << " kertoma on " << kertoma(num);
    rivi();
    }
    return 0;
}