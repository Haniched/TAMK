//
// Selvitetään, onko annettu vuosi karkausvuosi vai ei.
// Huomaa, että gregoriaaninen kalenteri tuli käyttöön 
// vuonna 1582, joten sitä edeltäviä vuosilukuja ei tällä
// menetelmällä voi tarkistaa.
//

#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;

    int vuosi = 2000;
    
    // Vuosi on karkausvuosi, jos vuosiluku on jaollinen neljällä. 
    // Sadalla jaollisista vuosiluvuista karkausvuosia ovat kuitenkin vain ne, 
    // jotka ovat jaollisia myös 400:lla. Esimerkiksi vuosi 1900 ei ollut 
    // karkausvuosi, mutta vuosi 2000 oli.
    
    // Olkoon: 
    // j4 = vuosi jaollinen neljällä
    // j100 = vuosi jaollinen sadalla
    // j400 = vuosi jaollinen 400:lla

    bool j4 = vuosi % 4 == 0;
    bool j100 = vuosi % 100 == 0;
    bool j400 = vuosi % 400 == 0;

    // Jotta vuosi olisi karkausvuosi, pitää olla: 
    // j4, mutta jos j100 niin sitten myös j400

    bool karkaus = false;  // true jos on karkausvuosi, muuten false
        
    // Loogisten operaatioiden totuustaulukot:
/*
    Looginen JA eli "AND":
    A      B      AND
    -------------------
    false  false  false
    false  true   false
    true   false  false
    true   true   true
  
    Looginen TAI eli "OR":
    A      B      OR
    -------------------
    false  false  false
    false  true   true
    true   false  true
    true   true   true
  
    Looginen EI eli "NOT"
    A      NOT
    -------------------
    false  true
    true   false    
*/

    // Loogisena lausekkeena: (j4 AND (NOT j100)) OR j400.
    // C++:lla ilmaistuna: (j4 && !j100) || j400
    cout << "\nLoogisena lausekkeena:" << endl;
    bool ehto1 = j4 && !j100;
    cout << "ehto1 = j4 && !j100 = " << boolalpha << ehto1 << endl;
    bool ehto2 = j400;
    cout << "ehto2 = j400 = " << boolalpha << ehto2 << endl;
    karkaus = ehto1 || ehto2;
    cout << "karkaus = ehto1 || ehto2 <==> " << boolalpha << ehto1 << " || " << ehto2 << endl; 

    // Esimerkiksi: vuodelle 1900 pätee j4, koska 1900 / 4 = 475 tasan. Eli j4 = true.
    // Vuodelle 1900 pätee myös j100, koska 1900 / 100 = 19 tasan. Eli j100 = true.
    // Piti olla "j4 AND (NOT j100)", mutta nyt on "true AND (NOT true)" eli "true AND false" eli false.
    // Joten ehto1 on false.
    // Vuodelle 1900 ei päde j400, koska 1900 / 400 ei mene tasan. Eli ehto2 = false.
    // Lausekkeen "ehto1 || ehto2" lopullinen arvo on siis "false OR false" eli false.
    // Tulos: 1900 ei ole karkausvuosi.
    
    // Vuosi 2000: j4 on true, koska 2000 / 4 = 500 tasan.
    // Myös j100 on true, koska 2000 / 100 = 20 tasan.
    // Näin ollen ehto1 = "true AND (NOT true)" on sama kuin "true AND false", eli false.
    // Vuodelle 2000 pätee kyllä j400, koska 2000 / 400 = 5 tasan. Eli ehto2 = true.
    // Lausekkeen "ehto1 || ehto2" lopullinen arvo on "false OR true" eli true.
    // Tulos: 2000 on karkausvuosi.
    
    cout << "lausekkeella: " << vuosi << ": " << boolalpha << karkaus << endl; 
            
    cout << "Vuosi " << vuosi;
    if (karkaus) {
        cout << " on";
    }
    else {
        cout << " ei ole";
    }
    cout << " karkausvuosi." << endl;
}
