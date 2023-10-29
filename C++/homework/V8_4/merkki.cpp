// V8_4 Merkkien tulostaminen

#include <iostream>
#include <string>

using namespace std;

void rivi (){
    cout << "\n";
}

void vali (){
    char maara;
    if (maara == 1){
        cout << "     ";
    }
    else if (maara == 2){
        cout << "    ";
    }

} 

void merkkitulos (int maara, char merkki){
    for (int krt = 0; krt < maara; krt++){
        cout << merkki;
    }
}

int main(){
    int maara;
    char merkki;

    cout << "Montako merkkiä haluat?" << vali (maara);
    cin >> maara;
    cout << "Mikä merkki tulostetaan?" << vali (merkki);
    cin >> merkki;

rivi ();
merkkitulos(maara, merkki);

return 0;
}