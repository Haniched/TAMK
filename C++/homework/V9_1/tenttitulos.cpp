// V9_1 Tentintulokset

#include <iostream>

void rivi (){
    std::cout << "\n";
}

void tallenta (int tulos[], int maara){
    for (int i = 0; i < maara; i++){
        std::cout << "Anna tallennettava tenttitulos: ";
        std::cin >> tulos[i];
    }
}

int main (){
    int maara = 10;
    int tulos[maara];
    float sum_tulos;
    float keskiarvo;

    tallenta (tulos,maara);
    rivi();
    for (maara = 0; maara < 10; maara++){
        std::cout << "Tenttitulos " << maara+1 << " on: " << tulos[maara] << "\n"; 
    }

    for (maara = 0; maara < 10; maara++){
        sum_tulos = sum_tulos + tulos[maara];
    }
    
    keskiarvo = sum_tulos / maara;
    std::cout << "Tenttitulosten keskiarvo on: " << keskiarvo;

    return 0;
}