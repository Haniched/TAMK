#include <iostream>
#include <cmath>
using namespace std;

bool isPrime (int luku){
    if (luku <= 1){
        return false;
    }

    for (int i = 2; i < luku; ++i){
        if (luku % i == 0){
            return false;
        } 
    }
    return true;
}

void prime_all (double size){
    for (int i = 0; i < size; ++i){
        if (isPrime(i)){
            cout << i << ", " ;
        } else {
            continue;
        }
    }
}

void prime_half (double size){
    for (int i = 0; i < size/2; ++i){
        if (isPrime(i)){
            cout << i << ", " ;
        } else {
            continue;
        }
    }
}

void prime_sqrt (double size){
    for (int i = 0; i < sqrt(size); ++i){
        if (isPrime(i)){
            cout << i << ", " ;
        } else {
            continue;
        }
    }
}

int main (){
    
    cout << "Prime numbers 1-10000\n";
    prime_all (10000);
    cout << "\nPrime numbers half of those\n";
    prime_half (10000);
    cout << "\nand prime numbers of squared amount\n";
    prime_sqrt (10000);
    
    return 0;
}

