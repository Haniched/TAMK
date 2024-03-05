#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int lines (ifstream &in){
    int linenum = 0;
    string line;
    while (std::getline(in, line)){
        ++linenum;
    }
    in.clear();
    in.seekg(0, std::ios::beg);
    return linenum;
}

int sums (ifstream &in){
    string line;
    int totalsum = 0;
    while (std::getline(in, line)){
        istringstream input(line);
        int num, sum = 0;

        while (input >> num){
            sum += num;
        }

        totalsum += sum;
    }
    return totalsum;
}

int main (){
    string filename;
    cout << "Name of the File: ";
    cin >> filename;
    ifstream in (filename);

    int totalline = lines(in);
    double totalsum = sums(in);
    int average = totalsum / totalline;
    cout << "\nFile's lines: " << totalline
        << "\nSum of all numbers: " << totalsum 
        << "\nAvarage of numbers: " << average << endl;
    return 0;
}