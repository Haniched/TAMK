#include <iostream>
#include <thread>
#include <chrono>

void display_slowly (const std::string &text, int delay){
    for (const char &ch : text){
        std::cout << ch;
        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay)
        );
    }
}