#include <cerrno>
#include <stdio.h>
#include <iostream>

int main ( ) {

    FILE *f = fopen("no", "r");

    if (errno == ENOENT) {
        std::cout << "errno message: " <<
        std::strerror(errno) << 
        std::endl;
    } 
    
    if (f == NULL) {
        perror("perror message: ");
    } else {
        fclose(f);
    }

    return 0;
}