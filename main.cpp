//driver of the program

#include <iostream>
#include "Dictionary.h"
#include "Thesaurus.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

  //Create dictionary and thesaurus objects
  Dictionary dictionary;
  Thesaurus thesaurus(dictionary);

  //open the input file
  string input = argv[1];
  ifstream fin;
  fin.open(input);

  //Process the input file and apply the appropriate function to each line

  string functionName, word1, word2;
  while(getline(fin, functionName, ':')){

    //add a word and definition to the dictionary
    if(functionName == "addWord"){
      getline(fin,word1, ':');
      getline(fin, word2);
      dictionary.addWord(word1, word2);
    }
    //get definition
    else if(functionName == "lookupWord"){
      getline(fin, word1);
      cout<<word1<<":"<<dictionary.lookupWord(word1)<<endl;
    }
    //add a synonym to a given word
    else if(functionName == "addSynonym"){
      getline(fin,word1, ':');
      getline(fin, word2);
      thesaurus.addSynonym(word1,word2);
    } 
    //get all synonyms
    else{
      getline(fin, word1);
      cout<<word1<<":"<<thesaurus.lookupSynonyms(word1)<<endl;
    }
  }
  return 0;
}
