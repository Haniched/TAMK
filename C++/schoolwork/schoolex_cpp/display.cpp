#include <iostream>
#include <thread>
#include <chrono>

void display_slowly (const std::string &text, int delay){
    for (const char &ch : text){
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay)
        );
    }
}
/*int main (){
    display_slowly ("text will be displayed letter by letter but idk how to do it", 100);
    return 0;
}*/