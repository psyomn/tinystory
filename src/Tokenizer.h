/**
*  @author Simon (psyomn) Symeonidis
*  @file
*/

#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include "dsQueue.cpp"

class Tokenizer {
public:
  Tokenizer();               /** Simple constructor */
  Tokenizer(string);         /** Overloaded Constructor to accept a string on the fly*/
  Tokenizer(string, char); /** Overloaded Constructor to accept input, and special delimiter instead of whitespace */
  Queue<string> getTokens(); /** Return the tokens yielded */
private:
  void tokenization();       /** Handle the rought stuff here. All parsing is taken care of on here. */
  char delim;                /** The delimiter in between tokens */
  Queue<string> tokens;      /** Queue containing tokens */
};

#endif
