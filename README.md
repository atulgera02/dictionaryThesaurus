# dictionaryThesaurus

A dictionary with the features of adding a word and looking up a word.
A thesaurus with the features of adding a synonym and looking up a synonym.

# To compile:
make main.exe

./main.exe INPUT_FILENAME

Output will be sent to cout

# Design process
I created a class for the dictionary and a class for the thesaurus. 

To model the dictionary, I chose a map of type <string, string> where the key is the word and the value is its definition.

To model the thesaurus, I chose a map of type <string, set string > where the key is the word and the set gaurantees unique synonyms. 

If there are any issues compiling, please let me know at atulgera@umich.edu.
Thank you.


