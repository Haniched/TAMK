#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Komentoriviargumentteja: ";
    int count = 0;
    for (int i = 1; i < argc; ++i) {
        count++;
    }
    std::cout << count << std::endl;
    std::cout << "Ja ne ovat: " << std::endl;
    for (int i = 1; i < argc; ++i) {
        std::cout << " " << argv[i] << std::endl;
    }
    return 0;
}

