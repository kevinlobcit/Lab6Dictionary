//
// Created by Owntrolf on 2018-11-02.
//

#ifndef LAB6DICTIONARY_DICTIONARY_HPP
#define LAB6DICTIONARY_DICTIONARY_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class dictionary {
private:
    std::map<std::string, std::string> dictionary;
    std::map<std::string, std::string>::iterator dIterator;



public:
    void printDict();
    void findDef();
    void newWord();
    void exit();


};


#endif //LAB6DICTIONARY_DICTIONARY_HPP
