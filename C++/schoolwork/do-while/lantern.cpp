// lyhty ja hakku

#include <iostream>

int main () {

  using namespace std;

  cout << "Olet laskeutumassa vanhaan kaivokseen";
  cout << "Varusteina sinulla on vain lyhty ja hakku. \n";

  bool jatkuu ( true );
  bool lyhty ( false ); // true = lyhty on, false =
  bool hakku ( false );
  bool laskeudu ( false );

  do {

    cout << "Komennot: "

    << "1) Ota lyhty "
    << "2) Pudota lyhty "
    << "3) Ota hakku "
    << "4) Pudota hakku "
    << "5) Aloita laskutuminen "
    << "6) Loteta\n";

    cout << "Anna komento: ";
    int komento;
    cin >> komento;

    switch (komento) {

      case 0:

        cout << "Ok, pelataan taas toiste!";
        jatkuu = false;
        break;

      case 1:

        if (lyhty) {
          cout << "Sinulla on se jo. ";
        }

        else {
          lyhty = true;
          cout << "Lyhty otettu. ";
        }
        break;

      case 2:

        if (lyhty) {
          lyhty = false;
          cout << "Lyhty pudotettu. ";

        }

        else {
          cout << "Sinulla ei ole sitä.";
        }
        break;

      case 3:
        if (hakku) {
          cout << "Sinulla on se jo. ";
        }

        else {
          hakku = true;
          cout << "Hakku otettu. ";
        }
        break;

      case 4:
        if (hakku) {
          hakku = false;
          cout << "Hakku pudotettu. ";
        }

        else {
          cout << "Sinulla ei ole sitä.";
        }
        break;

      case 5:
        if (lyhty && hakku){
          laskeudu = true;
          jatkuu = false;
        }

        else {
          cout << "Tarvitset sekä lyhdyn että hakun. ";
        }
        break;

      case 6:
        cout << "Sinulla on: ";
        
        if (!lyhty && !hakku) {
          cout << "ei mitään";
        }

        else {
          if (lyhty){
            cout << "lyhty ";
          }

          if (hakku) {
            cout << "hakku ";
          }
        }

      default:
        cout << "Tuntematon komento!";
        break;
    }

    cout << "\n\n";

  } while (jatkuu);
  
    if (laskeudu) {
    cout << "Aloitetaan laskeutuminen...\n";
    }
}