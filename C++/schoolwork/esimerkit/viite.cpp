#include <iostream>

void viite(int& a, int& b) {
    a *= 2;
    b *= 2;
}

int main() {
    int x{ 23 };
    int y{ 46 };

    std::cout << "x = " << x << ' ';
    std::cout << "y = " << y << '\n';

    viite(x, y);

    std::cout << "x = " << x << ' ';
    std::cout << "y = " << y << '\n';
}