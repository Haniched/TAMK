#include <iostream>
#include <cstdlib>

int main() {
	using std::cout;
	using std::cin;

	srand(time(0));  // alustaa satunnaislukugeneraattorin koneen kellonajalla

	int luku{ 1 + (rand() % 100) };  // luku, jota tietokone "ajattelee"

	cout << "Ajattelen jotain lukua väliltä 1...100. Arvaatko sen?\n";

	int kpl{ 10 };  // montako arvausta on vielä jäljellä
	bool jatkuu{ true };  // määrittää milloin pelisilmukka päättyy
	while (jatkuu) {
		cout << "Anna arvauksesi: ";
		int arvaus;
		cin >> arvaus;

		if (arvaus < 1 || arvaus > 100) {
			cout << "Luku on välillä 1...100!\n";
			continue;
		}

		kpl -= 1;  // sama kuin "kpl = kpl - 1"
		cout << "Arvauksia jäljellä " << kpl << "\n";

		if (arvaus < luku) {
			cout << "Liian pieni!";
		}
		else if (arvaus > luku) {
			cout << "Liian suuri!";
		}
		else {
			cout << "Oikein!";
			jatkuu = false;
		}
		cout << "\n";

		if (kpl == 0) {
			cout << "Olet käyttänyt kaikki arvaukset. Peli päättyy.\n";
			jatkuu = false;
		}
	}

	cout << "Kiitos pelistä!\n";
}
