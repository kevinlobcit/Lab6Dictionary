//
// Created by Owntrolf on 2018-11-02.
//

#include "dictionary.hpp"

dictionary::dictionary(std::string location){
    loc = location; //location of the text file
    fillDict();
}

dictionary::~dictionary(){

}

//Fills the dictionary map with data from the provided textfile
void dictionary::fillDict() {
    bool newWord = true;
    std::string word = "";
    std::string def = "";

    std::string readIn = "";
    std::ifstream fDict(loc);
    if(fDict.is_open())
    {
        while(getline(fDict, readIn))
        {
            if(newWord) //will be a new word if newWord is true
            {
                word = readIn;
                newWord = false;
            }
            else //will be a definition if newWord is false
            {
                def = readIn;
                dMap.insert(make_pair(word, def));
                newWord = true;
            }
        }

        fDict.close();

    }
    else
    {
        std::cout << "Unable to open file\n";
    }

}

//The menu of the dictionary that keeps repeating until exited by entering 4
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

//prints the entire dictionary
void dictionary::printDict() {
    for(dIterator = dMap.begin(); dIterator != dMap.end(); dIterator++)
    {
        std::cout << dIterator->first << " - " << dIterator->second << "\n" << std::endl;
    }
}

//finds definition of a select word
void dictionary::findDef() {
    std::string toFind;

    std::cout << "Enter the word's definition you want to find" << std::endl;
    std::cin >> toFind;
    dIterator = dMap.find(toFind);
    if(dIterator != dMap.end())
    {
        std::cout << dIterator->first << " - " << dIterator->second << "\n" << std::endl;
    } else {
        std::cout << "The word doesn't exist" << std::endl;
    }
}

//Allows user to enter a new word into the map and the text file
void dictionary::newWord() {
    std::string newWord;
    std::string def;
    do {
        std::cout << "Enter the new word: ";
        std::cin >> newWord;
        dIterator = dMap.find(newWord);
        if(dIterator == dMap.end()) // not found in dictionary
        {
            std::cout << "Enter the definition for the word" << std::endl;
            std::cin.ignore();
            getline(std::cin, def);
            dMap.insert(make_pair(newWord,def)); //adding into text file

            std::ofstream fDict; //writing to text file
            fDict.open(loc, std::ios_base::app);
            fDict << newWord << "\n" << def << "\n";
            fDict.close();
        }
        else
        {
            std::cout << "This word already exists, please enter a new word" << std::endl;
        }
    } while(dIterator != dMap.end());

}

void dictionary::exit() {

}


