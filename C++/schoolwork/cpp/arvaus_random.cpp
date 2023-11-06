#include <iostream>
#include <random>

int main() {
	using std::cout;
	using std::cin;

	std::random_device rd;
	std::default_random_engine moottori{ rd() };
	std::uniform_int_distribution aivo{ 1, 100 };  // HUOM! C++20!
	
	int luku{ aivo(moottori) };  // luku, jota tietokone "ajattelee"
	//cout << "Luku, jota ajattelen on " << luku << " (shh...)\n";
	bool oikein = false;  // oliko käyttäjän arvaus oikein vai ei
	int kpl{ 0 };  // montako arvausta on käytetty
	const int MAX_KPL = 10;  // näin monta arvausta enintään

	cout << "Ajattelen jotain lukua väliltä 1...100. Arvaatko sen?\n";
	while (!oikein) {
		cout << "Anna arvauksesi: ";
		int arvaus{ 0 };
		cin >> arvaus;

		if (arvaus < 1 || arvaus > 100) {
			cout << "Luvun pitää olla välillä 1...100.\n";
			continue;
		}

		kpl += 1;

		if (arvaus < luku) {
			cout << "Liian pieni!";
		}
		else if (arvaus > luku) {
			cout << "Liian suuri!";
		}
		else {
			cout << "Oikein!!!";
			oikein = true;
		}
		cout << "\n";

		if (!oikein) {
			cout << "Arvauksia jäljellä: " << MAX_KPL - kpl << "\n";
		}

		if (kpl == MAX_KPL) {
			cout << "Olet käyttänyt kaikki arvauksesi. Morjens!\n";
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
	cout << "\n";
}
