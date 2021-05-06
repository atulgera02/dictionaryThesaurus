#pragma once

//Definition of Dictionary class

//An efficient container for a dictionary in c++ is the map(string, string)

#include <iostream>
#include <map>
#include <string>

class Dictionary{
  private:
    //The key is the word in the dictionary
    //The value is the definition
    std::map<std::string, std::string> dictionary;
  
  public:
    //NOTE: The default constructor of this dictionary will create an empty map.
    //No dynamic memory is required, therefore no Big Three (assignment operator, dtor, copy ctor)  

    //REQUIRES: A unique word and a definition.
    //MODIFIES: this dictionary
    //EFFECTS: Add a word and its meaning to the dictionary. Returns no output 
    void addWord(const std::string word, const std::string definition);

    //REQUIRES: a word
    //MODIFIES: nothing
    //EFFECTS: Look up the meaning of a word from the dictionary. 
    //Returns the value (string) of a given key (string)
    std::string lookupWord(const std::string word);

    //REQUIRES: a word
    //MODIFIES: nothing --> const
    //EFFECTS: returns if the word (key) exists in the dictionary (map).
    bool existsInDictionary(const std::string word) const;
};