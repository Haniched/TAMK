//
//  main.cpp
//  Float
//
//  Created by Heejeong Han on 10.10.2023.
//

#include <iostream>
#include <iomanip> // input output manipulation

int main () {
   float r ( 0.0 );
   float a ( 0.0 );
   float pi ( 3.14159265359 );
   
   std::cout << "Anna kolmion kanta metreina ";
   std::cin >> r;
   
   a = pi * r * r;
   std::cout << "Ympyran ala on " << std::setprecision (12) << a << " a*2\n";
}
