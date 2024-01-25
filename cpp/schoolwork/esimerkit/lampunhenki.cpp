#include <iostream>

void oi_lampun_henki() {
	static int kutsukertoja{ 0 };

	kutsukertoja += 1;

	if (kutsukertoja <= 3) {
		std::cout << "Niin? Toiveesi on lakini.\n";
	}
	else {
		std::cout << "Minua on kutsuttu jo " << kutsukertoja << " kertaa. ";
		std::cout << "Mitä nyt taas?!\n";
	}
}

int main() {
	for (int i{ 0 }; i < 20; i++) {
		oi_lampun_henki();
	}
}
