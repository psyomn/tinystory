#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Tokenizer.cpp"
#include "FileHandler.cpp"
int main(){
  FileHandler f("example.txt");
  Tokenizer tok(f.getContents()); 

  return 0;
}
