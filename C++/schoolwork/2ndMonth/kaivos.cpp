#include <iostream>

int main() {
    using namespace std;

    cout << "Olet laskeutumassa kaivokseen. "
        << "Varusteina sinulla on lyhty ja hakku.\n";

    bool jatkuu{ true };  // vieläkö pelataan true/false
    bool lyhty{ false };  // onko lyhty vai ei
    bool hakku{ false };  // onko hakku vai ei
    bool laskeudu{ false };  // voiko laskeutua vai ei

    do {
        cout << "Komennot:\n"
            << "1) Ota lyhty  "
            << "2) Pudota lyhty  "
            << "3) Ota hakku  "
            << "4) Pudota hakku\n"
            << "5) Aloita laskeutuminen  "
            << "6) Inventaario  "
            << "0) Lopetus\n";

        cout << "Anna komento: ";
        int komento;
        cin >> komento;

        switch (komento) {
            case 0:
                cout << "OK, pelataan joskus toiste!";
                jatkuu = false;
                break;

            case 1:  // ota lyhty
                if (lyhty) {
                    cout << "Sinulla on se jo.";
                }
                else {
                    lyhty = true;
                    cout << "Lyhty otettu.";
                }
                break;

            case 2:  // pudota lyhty
                if (lyhty) {
                    lyhty = false;
                    cout << "Lyhty pudotettu.";
                }
                else {
                    cout << "Sinulla ei ole sitä.";
                }
                break;

            case 3:  // ota hakku
                if (hakku) {
                    cout << "Sinulla on se jo.";
                }
                else {
                    hakku = true;
                    cout << "Hakku otettu.";
                }
                break;

            case 4:  // pudota hakku
                if (hakku) {
                    hakku = false;
                    cout << "Hakku pudotettu.";
                }
                else {
                    cout << "Sinulla ei ole sitä.";
                }
                break;

            case 5:  // aloita laskeutuminen
                if (lyhty && hakku) {
                    laskeudu = true;
                    jatkuu = false;
                }
                break;

            case 6:  // inventaario, eli näytä esineet
                cout << "Sinulla on: ";
                if (!lyhty && !hakku) {
                    cout << "ei mitään";
                }
                else {  // on edes jotain
                    if (lyhty) {
                        cout << "lyhty ";
                    }
                    if (hakku) {
                        cout << "hakku ";
                    }
                }
                break;

            default:
                cout << "Tuntematon komento!";
                break;
        }

        cout << '\n';
    } while (jatkuu);

    if (laskeudu) {
        cout << "Aloitetaan laskeutuminen...";
    }
    else {
        cout << "Kiitos pelistä ja näkemiin!";
    }
}
