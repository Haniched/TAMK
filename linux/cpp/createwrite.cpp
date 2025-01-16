#include <iostream> // cin, cout
#include <fcntl.h> // creat
#include <unistd.h> // write, close
#include <errno.h> // errno

using namespace std;

int main() {

	char byte;
	cout << "BYTE: ";
	cin >> byte;
	
	int fd = creat("file.txt", 0644);
	if(fd == -1) {
		std::cout << std::strerror(errno) << std::endl;
		return 1;
	}
	
	ssize_t writefile = write(fd, &byte, 1);
	if (writefile == -1) {
		std::cout << std::strerror(errno) << std::endl;
		return 1;
	}
	
	int closefile = close(fd);
	if (closefile == -1) {
		std::cout << std::strerror(errno) << std::endl;
		return 1;
	}
	
	return 0;
}