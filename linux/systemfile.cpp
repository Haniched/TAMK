#include <iostream>   // cin, cout
#include <fcntl.h>    // creat
#include <unistd.h>   // write, close
#include <errno.h>    // errno
#include <cstring>    // strerror
#include <cstdlib>    // exit

int main() {
    // 1. Kysy käyttäjältä tavu (char) ja lue se
    char byte;
    std::cout << "Anna tavu (merkki): ";
    std::cin >> byte;

    // 2. Luo tiedosto "output.bin" käyttäen creat()-systeemikomentoa
    int fd = creat("output.bin", 0644);  // 0644 antaa oikeudet lukea ja kirjoittaa omistajalle
    if (fd == -1) {
        perror("Tiedoston luonti epäonnistui");
        std::exit(EXIT_FAILURE);  // Lopeta ohjelma virhetilanteessa
    }

    // 3. Kirjoita tavu tiedostoon käyttäen write()-systeemikomentoa
    ssize_t written = write(fd, &byte, 1);  // Kirjoita 1 tavu
    if (written == -1) {
        perror("Kirjoitus epäonnistui");
        close(fd);  // Sulje tiedosto ennen poistumista
        std::exit(EXIT_FAILURE);  // Lopeta ohjelma virhetilanteessa
    }

    // 4. Sulje tiedosto käyttäen close()-systeemikomentoa
    if (close(fd) == -1) {
        perror("Tiedoston sulkeminen epäonnistui");
        std::exit(EXIT_FAILURE);  // Lopeta ohjelma virhetilanteessa
    }

    std::cout << "Tavu on kirjoitettu tiedostoon 'output.bin' onnistuneesti." << std::endl;
    return 0;
}
