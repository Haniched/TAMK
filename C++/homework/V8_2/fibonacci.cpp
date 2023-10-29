// V8_2 Fibonacci

#include <iostream>
#include <string>

void rivi (){
    std::cout << "\n";
}

void tulosta (std::string s){
    std::cout << s;
}

int sarja (int luku){
    int ens = 0, toka = 1, ans;
    for (int krt = 1; krt <= luku; ++krt){
        ans = ens+toka;
        ens = toka;
        toka = ans;
    }
    return ens;
}

int main (){
    int luku;
    tulosta ("Anna fibonaccin lukujen maara: ");
    std::cin >> luku;
    rivi();
    std::cout << "Fibonnacci Sarja :  ";
    for (int krt = 0; krt < luku; ++krt){
        std::cout << sarja(krt);
        if (krt < luku -1) {
            std::cout << " ";
        }
    }
    rivi();
    return 0;
}