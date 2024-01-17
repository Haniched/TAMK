#include <iostream>
using namespace std;

int main (){
    int val = 7;
    int *valpt;
    valpt = &val;
    
    // c.
    cout << "muuttuja val = " << val << endl
         << "muuttuja valpt = " << valpt << endl;

    cout << "muuttuja &val = " << &val << endl
         << "muuttuja &valpt = " << &valpt << endl;

    // d.
    cout << "muuttuja *&val = " << *&val << endl
         << "muuttuja &*valpt = " << &*valpt << endl;

    // e.
    cout << "sizeof(val) = " << sizeof(val) << endl
         << "sizeof(valpt) = " << sizeof(valpt) << endl;

    // g.
    int *valpt2;
    valpt2 = nullptr;

    // h.
    cout << "muuttuja valpt2 = " << valpt2 << endl;

}