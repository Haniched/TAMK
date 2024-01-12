#include <iostream>
using namespace std;

void swap (int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main (){
    int num [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "taulukko kaannettyna: ";
    
    int str = 0;
    int end = 9;
    
    while (str < end) {
        swap (num[str], num[end]);
        str++;
        end--;
    }

    for (int i = 0; i < 10; i++){
        cout << num [i] << ' ';
    }
    return 0;
}