/**
* \mainpage TinyStory
* \section a Why TinyStory 
* This is a program which was developed in order for a friend to 
* write pretty stories in html. The idea is that the person writing
* the said story can simply run the program in the directory with 
* a specified text file, and then generate the story in a standalone
* html file, with interactivity provided with javascript.
* \section b Why did reinvent some things you could've just included?
* Well, I was doing this project mainly for practice. So you'll see
* a datastructure or some other things I could have included from 
* other libraries...
* \section c How much attention will you be giving this project?
* I'm going to complete it and have basic functionality, but 
* probably will not maintain it in the future, unless it acquires
* a reasonable 'big' userbase.
* \section d Can I help?
* I would love to work with more people. Give me a shout at my email
* listed.
* @author Simon (psyomn) Symeonidis lethaljellybean@gmail.com
* @file
* @section
* This part is the main part of the program. It is responsible to 
* read the story file and pass the contents to the parser.
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

  cout << "Made by : Simon Symeonidis" << endl;
  cout << "  You can send request, praise and hate here: lethaljellybean@gmail.com " <<endl;

  return 0; // Yay, nothing broke
}
