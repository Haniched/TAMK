#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

std::string ignoreCase(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main (int argc, char* argv[]){
    
    /*--- INKRAMENTTI 1 ---
    std::string orgStr, searchStr;

    std::cout << "Give a string to search from: ";
    std::getline (std::cin, orgStr);

    std::cout << "Give a string to search for: ";
    std::getline (std::cin, searchStr);

    size_t match = orgStr.find(searchStr);
    if (match != std::string::npos) {
        std::cout << searchStr << " found in " << orgStr << " position " << match << std::endl;
    } else {
        std::cout << searchStr << " NOT found in " << orgStr << std::endl; 
    }
    
    // argv TEST RUN
    // for (int i = 0; i < argc; i++){
    //     std::cout << "argv " << i << argv[i] << std::endl;
    // } */

    /*--- INKRAMENTTI 2, 3, 4 ---*/
    std::string file;
    std::string fileSearchStr;

    // check file
    // if (!in.is_open()) {
    //     std::cerr << "INVALID FILE" << std::endl;
    //     return 1;
    // }

    bool linenumbering;
    bool occurance;
    bool reverse;
    
    // if there is option selected
    if (argc == 4){
       file = argv [3];
       fileSearchStr = argv[2];

        for (int i = 2; i <= strlen(argv[1]); i++){
            if (argv [1][i] == 'i'){
                fileSearchStr = ignoreCase (argv[2]);
            } 
            
            if (argv [1][i] == 'l') {
                linenumbering = true;
            }

            if (argv [1][i] == 'o') {
                occurance = true;
            } 

            if (argv [1][i] == 'r') {
                reverse = true;
            } 
        }
    }

    // if there are no option selected
    else if (argc == 3) {
        file = argv [2];
        fileSearchStr = argv[1];
    }

    std::ifstream in (file);
    
    std::string line;
    
    int linenum = 1;
    int occurence = 0;

    while (getline(in,line)){
        linenum++;

        if (line.find(fileSearchStr) != std::string::npos) {
            
            if (line.find(fileSearchStr) == std::string::npos) {
                if (reverse) {
                    std::cout << line << std::endl;
                } else {continue;}
            }

            if (linenumbering){
                std::cout << linenum << ": ";
            }

            if (occurance) {
                occurence++;
            }
            
            std::cout << line << std::endl;

        } else {continue;}
        
    }

    // occurance output
    if (occurance) {
        std::cout << "Occurrences of lines containing " << '"' << fileSearchStr << '"' << ": " << occurence << std::endl;
    }
    

    return 0;
}