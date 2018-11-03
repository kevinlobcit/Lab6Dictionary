//
// Created by Owntrolf on 2018-11-02.
//

#include "dictionary.hpp"

dictionary::dictionary(std::string location){
    loc = location;
}

dictionary::~dictionary(){

}

void dictionary::menu() {
    int option = -1;
    while(option != 4)
    {
        std::cout << "1 - Print dictionary\n" <<
                     "2 - Find word definition\n" <<
                     "3 - Enter new word and definition\n" <<
                     "4 - Exit" << std::endl;
        std::cin >> option;
        switch(option){
            case 1: printDict();
                break;
            case 2: findDef();
                break;
            case 3: newWord();
                break;
            case 4: option = 4;
        }

    }
}

void dictionary::printDict() {
    bool newWord = true;
    std::string word = "";
    std::string def = "";

    std::string readIn = "";
    std::ifstream fDict(loc);
    if(fDict.is_open())
    {
        while(getline(fDict, readIn))
        {
            //std::cout << readIn << '\n';
            if(newWord)
            {
                word = readIn + '\n';
                newWord = false;
            }
            else
            {
                def = readIn + '\n';
                dMap.insert(make_pair(word, def));
                //std::cout << word << "||" << def << std::endl;
                newWord = true;
            }
        }

        fDict.close();

        for(dIterator = dMap.begin(); dIterator != dMap.end(); dIterator++)
        {
            std::cout<< dIterator->first << " - " << dIterator->second << std::endl;
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
    std::cout << "Enter the new word: ";
}

void dictionary::exit() {

}


