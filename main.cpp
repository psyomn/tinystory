/**
*  @author Simon (psyomn) Symeonidis
*  @file
*  @section
*  This part is the main part of the program. It is responsible to 
*  read the story file and pass the contents to the parser.
*/

// The special tags to take care of are >, ", #
// The rest should be relatively easy

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Classes
#include "FileHandler.cpp"

int main(){
  FileHandler f;
  f.setFilename("text.txt");
  // --== Initialization ==--
  ifstream read;
  string str;
  string str2;
  
  cout << "Add";

  read.open("text.txt");
  while (!read.eof()){
    getline(read, str2);
    str2+= "\n"; 
    str += str2;
  }
  
  cout << str;
}
