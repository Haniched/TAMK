#include <iostream>
using namespace std;

// TV1

enum muoto {epa, kylk, suor, tasa, FALSE};

muoto kolmiollinen (int sivu[]){
    if (sivu[0] == 0 || sivu [1] == 0 || sivu [2] == 0){
        return FALSE;
    } else if ((sivu[0] == sivu[1] && sivu[0] > sivu[2]) || (sivu[1] == sivu[2] && sivu[1] > sivu[0]) || sivu[0] == sivu[2] && sivu[0] > sivu[1]){
        return kylk;
    } else if ((sivu[0] == sivu[1] && sivu[0] < sivu[2]) || (sivu[1] == sivu[2] && sivu[1] < sivu[0]) || (sivu[0] == sivu[2] && sivu[0] < sivu[1])){
        return suor;
    } else if (sivu[1] == sivu[2] == sivu[0]){
        return tasa;
    }
    return epa;
}

int main (){

    const int krt = 3;
    int sivu[krt];
    
    for (int i = 0; i < krt; i++){
        cout << "Anna " << i+1 << ". sivun pituus: ";
        cin >> sivu[i];
    }

    switch (kolmiollinen (sivu)){
        case 0: 
            cout << "Annetuista sivuista voidaan muodostaa kolmio." << endl;
            break;

        case 1:
            cout << "Annetuista sivuista voidaan muodostaa tasakylkinen kolmio." << endl;
            break;

        case 2: 
            cout << "Annetuista sivuista voidaan muodostaa suorakulmainen kolmio." << endl;
            break;

        case 3: 
            cout << "Annetuista sivuista voidaan muodostaa tasasivuinen kolmio." << endl;
            break;

        default:
            cerr << "Annetuista sivuista ei voi muodostaa kolmio." << endl;
            break;
    }
    return 0;
}

