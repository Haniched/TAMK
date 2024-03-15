#include <iostream>
#include <cstdlib>

class noppa {
public:

    noppa(int aLukumaara);

    void heitaNoppaa();

    int getLuku();
    void setLuku(int aLukumaara);

    void kerroViimeisenHeitonLukema();
private:
    int num[10];
    int lukumaara = 1;
};