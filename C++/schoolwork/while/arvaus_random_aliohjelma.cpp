#include <iostream>
#include <random>
#include <string>

// Funktoiden prototyypit
void uusirivi ();
void tulosta (std::string s, bool rivinvaihto = false);
void tulosta (int n);
void alkutekstit ();

bool on_valilla (int luku, int pienin, int suurin);

const bool RIVI { true };

int main() {
	using std::cout;
	using std::cin;

	alkutekstit();

	std::random_device rd; // laitteiston / käyttöjärjestelmän satunnaislaite
	std::default_random_engine moottori{ rd() }; // tuottaa satunnaislukuja
	// em. satunnaislaitteen avulla

	// Jakauma joka tuottaa numrovälin arvot satunnaisesti mutta tasaisesti
	std::uniform_int_distribution aivo{ 1, 100 };  // HUOM! C++20!
	
	int luku{ aivo(moottori) };  // luku, jota tietokone "ajattelee"

	bool oikein = false;  // onko pelaajan arvaus oikein (true) vai ei (false)
	int kpl ( 0 );  // montako arvausta on käytetty
	const int MAX_KPL = 10;  // näin monta arvausta enintään

	cout << "Ajattelen jotain lukua väliltä 1...100. Arvaatko sen?\n";
	while (!oikein) { // niin kauan kuin vastaus ei ole oikein
		tulosta ("Anna arvauksesi: ");
		int arvaus{ 0 };
		cin >> arvaus;

		// tarkistetaan että arvaus on välillä 1-100
        if (!on_valilla(arvaus, 1, 100))
		if (arvaus < 1 || arvaus > 100) {
		    tulosta ("Arvaus pitää olla välillä 1...100.", RIVI);
			continue; // siirtyy seuraavalle kierokselle silmukassa
		}

		kpl += 1; // sama kuin kpl=kpl+1 
		tulosta ("Arvasit luvun ");
		tulosta (arvaus);
		uusirivi ();
		if (arvaus < luku) {
			tulosta ("Liian pieni!");
		}
		else if (arvaus > luku) {
			tulosta ("Liian suuri!");
		}
		else {
			tulosta ("Oikein!!!");
			oikein = true;
		}
		uusirivi ();

		if (!oikein) {
			tulosta ("Arvauksia jäljellä: ") 
			tulosta (MAX_KPL - kpl); 
			uusirivi();
		}

		if (kpl == MAX_KPL) {
			tulosta ("Olet käyttänyt kaikki arvauksesi", false);
			break;
		}
	}

	cout << "Kiitos pelistä! ";
	if (oikein) {
		cout << "Hienosti arvattu.";
	}
	else {
		cout << "Parempi onni ensi kerralla.";
	}
	uusirivi ();
}

// Tulostaa rivinvaihdon.
void uusirivi (){
	std::cout << "\n";
}

// Tulostaa merkkijonon ja mahdollisesti rivinvaihdon sen perään
void tulosta (std::string s, bool rivinvaihto){
	std::cout << s;
	if (rivinvaihto){
		uusirivi();
	}
}

void tulosta (int n){
	std::cout << n;
}

void alkutekstit (){
	tulosta("Ajattelen jotain lukua väliltä 1-100. Arvaatko sen?", true);
}

bool on_valilla (int luku, int pienin, int suurin){
    if (luku >= pienin && luku <= suurin){
        return true;
    }
    return false;
}