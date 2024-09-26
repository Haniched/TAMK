#include <iostream>   // cin, cout
#include <fcntl.h>    // open
#include <unistd.h>   // read, close
#include <errno.h>    // errno
using namespace std;

int main() {
    
    char buffer[10];

    int file = open("file.txt", O_RDONLY);
    if (file == -1) {
        std::cout << "Error occured during opening the file. " <<
        std::strerror(errno) << std::endl;
        return 1;
    }

    ssize_t readfile = read(file, buffer, sizeof(buffer));
    if (readfile == -1) {
        std::cout << "Error occured during reading the file. " <<
        std::strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "Read bytes: ";
    for (ssize_t i = 0; i < readfile; ++i){
        std::cout << buffer[i];
    }
    std::cout << std::endl;

    int closefile = close(file);
    if (closefile == -1) {
        std::cout << "Error occured during closing the file. " <<
        std::strerror(errno) << std::endl;
        return 1;
    }

    return 0;
}
