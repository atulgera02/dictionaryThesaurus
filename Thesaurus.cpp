#include <map>
#include <iostream>
#include <string>
#include <set>
#include "Thesaurus.h"
#include "Dictionary.h"


//REQUIRES: a valid dictionary
//MODIFIES: the member vaiable dict.
//EFFECTS: creates a dictionary for the thesaurus to check if words are present in this dict.
Thesaurus::Thesaurus(Dictionary & dict_in)
: dict(dict_in) {}

//REQUIRES: a word and its synonym;
//MODIFIES: this thesaurus, returns nothing. Maintains communtativity and transitivity
//EFFECTS: adds a synonym to the vector of synonyms for a given word
void Thesaurus::addSynonym(const std::string word, const std::string synonym){
  //check that both the word and the synonym exist in the dictionary.
  if(!(dict.existsInDictionary(word))) return;
  if(!(dict.existsInDictionary(synonym))) return;

  //add the synonym to this words vector.
  thesaurus[word].insert(synonym);

  //Commutativity: Add the word to this synonym's vector
  thesaurus[synonym].insert(word);

}

//REQUIRES: a word
//MODIFIES: read-only
//EFFECTS: Look up the meaning of a word from the dictionary. 
//Returns the value (vector<string>) of a given key (string)
std::string Thesaurus::lookupSynonyms(const std::string word){
  if(!(dict.existsInDictionary(word))) return "This word is not present in the dictionary.";

  std::string output;

  //transitivity: include the synonyms of each synonym when outputting. 
  for(std::string synonym : thesaurus[word]){
    output+=synonym + ",";
    for(std::string transitive : thesaurus[synonym]){
      output += transitive + ",";
    }
  }
  return output;
}
