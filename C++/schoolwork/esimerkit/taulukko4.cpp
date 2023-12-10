#include <iostream>
#include <array>

int main() {
	std::array<int, 12> paivat{
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	int summa{ 0 };
	for (size_t i{ 0 }; i < paivat.size(); i++) {
		std::cout << paivat.at(i) << " ";
		summa += paivat.at(i);
	}
	std::cout << "\n";

	summa = 0;
	// C++11: "range-based for loop"
	for (const int& luku : paivat) {
		std::cout << luku << " ";
		summa += luku;
	}
	std::cout << "\n";

	std::cout << "alkioiden summa = " << summa << "\n";
}
