//
//  while.cpp
//  while
//
//  Created by Heejeong Han on 9.10.2023.
//

#include "while.hpp"
#include <iostream>

int main (){
    int n ( 5 );
    
    while (n >= 0) {
        std::cout << n << "....";
        n = n - 1; //이 공식이 없으면 순서대로 숫자가 줄어들지 않음
    }
    
    std::cout << "LIFTOFF!!!\n";
}


