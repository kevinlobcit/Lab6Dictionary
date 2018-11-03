#include <iostream>
#include "dictionary.hpp"


int main() {

    dictionary dict = dictionary("../dictionary.txt");
    dict.menu();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}