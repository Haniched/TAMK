#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string in;
    while (true)
    {
        cout << "Please enter a number: ";
        getline(cin, in);
        std::stringstream s(in);
        if (s >> in)
            break;
        cout << "Invalid number, please try again\n";
     }
     return 0;
}