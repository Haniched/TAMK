#include <iostream>
using namespace std;

void taul1 (int num []){

    for (int i = 0; i < 10; i++){
        cout << num [i] + 1 << ' ';
    }
}

void taul2 (int *num){
    for (int i = 0; i < 10; i++){
        cout << num[i]+1 << ' ';
    }
}

int main (){
    int num [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << "taulukko ennen aliohjelmakutsua 1: ";
    for (int i = 0; i < 10; i++){
        cout << num [i] << ' ';
    }
    cout << "\ntaulukko aliohjelmakutsun 1 jalkeen: "; 
    taul1 (num);

    cout << "\ntaulukko ennen aliohjelmakutsua 2: ";
    for (int i = 0; i < 10; i++){
        cout << num [i] << ' ';
    }
    cout << "\ntaulukko aliohjelmakutsun 2 jalkeen: ";
    taul2 (num);
    cout << endl;

}