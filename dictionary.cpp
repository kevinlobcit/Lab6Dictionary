//
// Created by Owntrolf on 2018-11-02.
//

#include "dictionary.hpp"

void dictionary::printDict() {


    bool newWord = true;
    std::string word = "";
    std::string def = "";

    std::string readIn = "";
    std::ifstream fDict;
    fDict.open("../dictionary.txt");
    if(fDict.is_open())
    {
        while(getline(fDict, readIn))
        {
            std::cout << readIn << '\n';
            if(newWord)
            {
                word = readIn;
                newWord = false;
            }
            else
            {
                def = readIn;
                //dictionary.insert(def, word);
                newWord = true;
            }
        }

        fDict.close();

        for(dIterator = dictionary.begin(); dIterator != dictionary.end(); dIterator++)
        {
            //std::cout<< dIterator->first << " - " << dIterator->second << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to open file\n";
    }

}

void dictionary::findDef() {

}

void dictionary::newWord() {

}

void dictionary::exit() {

}


