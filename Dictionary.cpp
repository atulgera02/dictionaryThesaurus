//An efficient container for a dictionary in c++ is the map(string, string)

#include <iostream>
#include <map>
#include <string>
#include "Dictionary.h"

//REQUIRES: a word
//MODIFIES: read-only --> const
//EFFECTS: returns if the word (key) exists in the dictionary (map).
bool Dictionary::existsInDictionary(const std::string word) const{
  if(dictionary.count(word) > 0) return true;
  return false;
} 

//REQUIRES: A unique word and a definition.
//MODIFIES: this dictionary
//EFFECTS: Add a word and its meaning to the dictionary. Returns no output 
void Dictionary::addWord(const std::string word, const std::string definition){
  if(existsInDictionary(word)) return;
  dictionary[word] = definition;
}

//REQUIRES: a word
//MODIFIES: read-only
//EFFECTS: Look up the meaning of a word from the dictionary. 
//Returns the value (string) of a given key (string)
std::string Dictionary::lookupWord(const std::string word) {
  if(!existsInDictionary(word)) return "This word is not present in the dictionary.";
  return dictionary[word];
}