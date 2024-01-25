// V11_1 Roomaniset numerot 
/* Roomaniset luvut
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1 000
*/

#include <iostream>
#include <string>
#include <map>

std::map <char,int> romanum{
    {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
};

int roomaan (const std::string& roma){
    int summa;

    for (int i = roma.length()-1; i >= 0; i--){
        if(i > 0 && romanum.at(roma[i]) > romanum.at(roma[i-1])){
            summa+= romanum.at(roma[i])-romanum.at(roma[i-1]); 
            i--;
        }
        else{summa+= romanum.at(roma[i]);}
       
    }
    return summa;
}

int main (){

    std::string roma; 
    std::cout << "Roomalainen luku, jonka desimaaliarvon haluat tietää? ";
    std::cin >> roma;
    std::cout << "Desimaalimuodossa roomalainen luku " << roma << " on " << roomaan (roma) << '\n';

    return 0;
}

// compile code : g++ -std=c++11 이시발것왜이지랄임맨날