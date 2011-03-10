/**
*  @author Simon (psyomn) Symeonidis
*  @file
*/

#ifndef _TOKENIZER_CPP_
#define _TOKENIZER_CPP_

#include "Tokenizer.h"

Tokenizer::Tokenizer(){
  delim = ' ';
}

Tokenizer::Tokenizer(string input){
  int i;
  string tmp;
  bool next = false;

  tmp   = "";
  delim = ' ';
  
  for ( i=0; i<input.length(); i++ ){
    if ( input[i] != delim){
      tmp+=input[i];
    }
    else{ // Found a
      next = true;
    }
    if ( next == true && tmp != "") {
      tokens.push(tmp);
      tmp = "";
      next = false;
    }
  }
 
  // This simply means that there could be a case that the 
  // inputed string is entered and the last char is not a
  // DELIMITER. Which means that it will not be pushed 
  // inside the queue
  if (tmp != ""){
    tokens.push(tmp);
  }

  tokens.print();
}

Tokenizer::Tokenizer(string input, char d){
  delim = d;
}

void Tokenizer::tokenization(){
   
}

Queue<string> Tokenizer::getTokens(){
  return tokens;
}
#endif
