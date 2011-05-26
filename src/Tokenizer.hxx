#ifndef TOKENIZER_HXX
#define TOKENIZER_HXX

#include <iostream>
#include <string>
#include <vector> 
#include <sstream>

#include "FileHandler.hxx"

/** Class which takes care of tokenizing strings. The delimiter is whitespace. 
The tokens are stored as a vector of strings. */
class Tokenizer {
public:
  Tokenizer();
  ~Tokenizer();
  void tokenize(std::string&);
  void tokenizeStory(std::string);
  void print() const; 
  const std::vector<std::string> getTokens() const;
  std::vector<std::string>* getPointerToTokens();
private: 
  std::vector<std::string> mTokens; /** Tokens from a string stored as a vector */
};

#endif 

