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
#include "dsQueue.cpp"

// Main program

int main(){
  //Init
  //  FileHandler f("theStory.txt");
  Queue<string> q;

  q.push("ASDF");
  q.push("QWER");
  q.push("1234");
  q.push("0987");
  q.push("derp");
  q.push("herp");

  q.print();

//  cout << q.pop() << endl;

  //Body
  // cout << f.getContents();

  return 0; // Yay, nothing broke
}
