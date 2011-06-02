#include <iostream>

#include "FileHandler.hxx"
#include "Tokenizer.hxx"
#include "TagParser.hxx"
#include "Log.hxx"

int main(){
  Tokenizer tok;
  TagParser tag;

  tok.tokenizeStory("sample.txt");
  tok.print();
  std::cout << std::endl;
  
  std::cout << (tok.getPointerToTokens());
  
  tag.setTokens(tok.getPointerToTokens());
  tag.parse();

  return 0;
}
