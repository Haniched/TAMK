#include <iostream>
#include <fstream>
using namespace std;

int main (){

    ofstream write ("teht1.txt");
    int SIZE = 1000000;
    bool allocatable;

    if (write.is_open()){
        while (!allocatable) {
            if (SIZE <= std::numeric_limits<std::size_t>::max()){
                allocatable = true;
                int *array_p = new int [SIZE];
                write << "Seuraaan kokoisia paikallisia taulukoita onnistui varata: " << SIZE/1000 << " kilotavua\n";
                delete [] array_p;
                array_p = nullptr;
                SIZE*=2;
            } else {
                allocatable = false;
                write << "Tilavaraus epäonnistui ensimmäisen kerran seuraavaan kokoon: " << SIZE/1000 << " kilotavua\n";
            }
        }
    } else {
        cerr << "File is not open." << endl;
    }
    return 0;
}

