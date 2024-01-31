#include <iostream>

using namespace std;

int min(int x, int y); 
int min(int x, int y, int z); 
int min(int x, int y, int z, int w); 
 
int main (){
    cout << min(3,6) << '\n' << min(32,6,14) << '\n' << min(53,72,23,22) << endl;
    return 0;
}

int min (int x, int y){
    if (x < y){
        return x;
    } else {
        return y;
    } 
}

int min (int x, int y, int z){
    int xy = min (x,y);
    return min (xy, z);
}

int min (int x, int y, int z, int w){
    int xy = min (x,y);
    int zw = min (z,w);
    return min (xy, zw);
}