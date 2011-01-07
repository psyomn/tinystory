#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Tokenizer.cpp"
#include "FileHandler.cpp"
#include "TagParser.cpp"

int main(){
  FileHandler f("example.txt");
  Tokenizer tok(f.getContents()); 
  //f.writeFile("testtheclass.txt", "hello world!");
  TagParser tp(tok);
  return 0;
}
