#include <iostream>

#include "FileHandler.hxx"
#include "Tokenizer.hxx"
#include "TagParser.hxx"
#include "Log.hxx"

int main(int argc, char** argv){
  Tokenizer tok;
  TagParser tag;
  Log::Inst()->logMessage("-------------------------------------------------------"); 
  Log::Inst()->logMessage("TinyStory v 1.2 started!"); 
  if(argc<=1){
    std::cout << "Using default reading file (sample.txt)" << std::endl;
    tok.tokenizeStory("sample.txt");
  }
  else {
    std::cout << "Using specified file : " << argv[1] << std::endl;
    tok.tokenizeStory(argv[1]); 
  }
  tok.print();
  std::cout << std::endl;
  
  std::cout << (tok.getPointerToTokens());
  
  tag.setTokens(tok.getPointerToTokens());
  tag.parse();

  Log::Inst()->logMessage("Tinystory ended execution");
  Log::Inst()->logMessage("-------------------------------------------------------"); 
  return 0;
}
