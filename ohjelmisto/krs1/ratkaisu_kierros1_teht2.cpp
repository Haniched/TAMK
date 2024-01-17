#include <iostream>
using namespace std;

void swap1 (int &yksi, int &kaks){
    int temp;
    temp = yksi;
    yksi = kaks;
    kaks = temp;
}

void swap2 (int *kolm, int *nelj){
    int temp;
    temp = *kolm;
    *kolm = *nelj;
    *nelj = temp;
}

int main (){
    int yksi = 1;
    int kaks = 2;
    cout << "yksi = " << yksi << ", kaksi = " << kaks << " ennen swap:1:ia." << endl;
    swap1 (yksi,kaks);
    cout << "yksi = " << yksi << ", kaksi = " << kaks << " jälkeen swap:1:in." << endl;
    
    int kolm = 3;
    int nelj = 4;
    cout << "kolme = " << kolm << ", neljä = " << nelj << " ennen swap:2:ia." << endl;
    swap2 (&kolm,&nelj);
    cout << "kolme = " << kolm << ", neljä = " << nelj << " jälkeen swap:2:in." << endl;
    return 0;
}