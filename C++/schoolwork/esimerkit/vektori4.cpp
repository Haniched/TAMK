#include <iostream>
#include <vector>

int main() {
	std::vector<int> tulokset;

	int tulos{ 0 };
	do {
		std::cout << "Anna tulos: ";
		std::cin >> tulos;

		if (tulos > 0) {
			tulokset.push_back(tulos);
		}
	} while (tulos > 0);

	std::cout << "vektorissa on " << tulokset.size() << " alkiota.\n";

	int summa{ 0 };
	for (const int& luku : tulokset) {
		summa += luku;
	}

	std::cout << "tulosten summa = " << summa << "\n";

	summa = 0;
	for (size_t i{ 0 }; i < tulokset.size(); i++) {
		tulokset.at(i) *= 10;
		summa += tulokset.at(i);
	}

	std::cout << "tulosten summa 10x = " << summa << "\n";

	double keskiarvo{ double(summa) / tulokset.size() };
	std::cout << "tulosten keskiarvo = " << keskiarvo << "\n";
}
