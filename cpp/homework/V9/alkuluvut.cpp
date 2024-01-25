// V9_3 alkuluvut

#include <iostream>

bool tutkimus (int luku){
    if (luku <= 1) {
        return false;
    }
    for (int jako = 2; jako < luku; jako++){
        if (luku % jako == 0){
        return false;
        }

    }
    return true;
}

int main (){
    int luku;
    for (int luku = 0; luku <= 1000; luku++){
        if (tutkimus (luku)){
            std::cout << luku << " ";
        }
    }
}