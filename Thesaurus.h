//An efficient container for a thesaurus is a map(string word, set<string> synonyms)

#pragma once

#include <map>
#include <iostream>
#include <string>
#include <set>
#include "Dictionary.h"

class Thesaurus{
  private:
    //The keys of the map are a word
    //The values of the map are set of synonyms.
    std::map<std::string, std::set<std::string> > thesaurus;
    Dictionary& dict;
  
  public:

    //REQUIRES: a valid dictionary
    //MODIFIES: the member vaiable dict.
    //EFFECTS: creates a dictionary for the thesaurus to check if words are present in this dict.
    Thesaurus(Dictionary & dict);

    //REQUIRES: a word and its synonym;
    //MODIFIES: this thesaurus, returns nothing
    //EFFECTS: adds a synonym to the vector of synonyms for a given word
    void addSynonym(const std::string word, const std::string synonym);

    //REQUIRES: a word
    //MODIFIES: read-only
    //EFFECTS: Look up the meaning of a word from the dictionary. 
    //Returns the value (set<string>) of a given key (string)
    std::string lookupSynonyms(const std::string word);
};