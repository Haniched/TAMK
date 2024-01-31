#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
    string header, filename, name, Description;
    cout << "Name of your Website page: ";
    cin >> header;
    
    filename = header + ".html";
    
    ofstream write (filename);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter your name: ";
    getline (cin, name);

    cout << "Describe yourself: ";
    getline (cin, Description);

    if (write.is_open()) {
        write << "<html>\n<head>\n" << header 
        << "\n</head>\n<body>\n   <center>\n    <h1>" << name 
        << "</h1>\n   </center>\n   <hr />\n    " << Description
        << "\n   <hr />\n</body>\n</html>";
        // cout << "Your website file is ready. Open '" << filename << "' in web browser." << endl;
        write.close();
        std::string command = "open " + filename;
        system(command.c_str());
    } else {
        cerr << "ERROR: FILE UNDEFINED" << endl;
    }
    return 0;
}