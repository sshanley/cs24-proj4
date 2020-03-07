#ifndef BAG4_H
#define BAG4_H
#include "word.h"
#include "file.h"
#include <string>

//Sean Shanley 3/7/2020
//
// YOU CAN INCLUDE OTHER HEADER FILES HERE IF NEEDED
// DO NOT ADD THE FOLLOWING HEADERS:
// 1. <vector>, 2. <queue>, 3. <deque>, 4. <stack>,
// 5. <map>, 6. <algorithm>, 7. <set>, 8. <utility>
// In summary do not use any built-in data structures
// other than arrays. Also, do not use any built-in
// algorithms related to sorting and searching
// you are allowed to use the header files: <cstring>, <string>
// you can use the string manipulation functions
// provided by those header files if needed



class Bag{

  dnode<Word>* container;
  dnode<Word>* tail;
  int count = 0;

  // It will be useful to maintain this array in lexicographically
  // increasing order of words stored in the objects
  // i.e the Word object for "apple" is stored at a lower index
  // than the Word object for "zoo"
  // ADD NEW MEMBER VARIABLES HERE IF NEEDED

  

public:

  // the below function is used to print the contents of
  // container array (declared at line 40)  in the format <WORD::COUNT>
  Bag(){container = NULL; tail = NULL;}
  ~Bag();
  //~Bag();
  void print_words(std::string name); 
  // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED
  dnode<Word>* has_word(std::string name); //return pointer of word with the phrase, NULL if not there
  void insert_word(std::string phrase,std::string file);
  void searchcount(std::string phrase, int thresh); // return files in word with at least as much count as thresh
  void searchunion(std::string word1, std::string word2); // return files in alph order that have at least one of these words
};


#endif
