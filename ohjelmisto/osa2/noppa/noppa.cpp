#include "noppa.h"
using namespace std;

noppa::noppa (int aLukumaara) {
    noppa::setLuku(aLukumaara);
    noppa::heitaNoppaa();
}

void noppa::heitaNoppaa() {
    srand(time(0));
    for (int i = 0; i < lukumaara; i++){
        num[i] = rand() % 6 + 1;
    }
}

int noppa::getLuku() {
    return lukumaara;
}

void noppa::setLuku(int aLukumaara) {
    // cout << "Noppien maara: ";
    // cin >> aLukumaara;
    lukumaara = aLukumaara;
}

void noppa::kerroViimeisenHeitonLukema() {
    int sum = 0;
    for (int i = 0; i < lukumaara; i++){
        cout << "Noppa" << i+1 << ": " << num[i] << ", ";
        sum += num[i]; 
    }
    cout << "yhteensa " << sum << endl;
}

