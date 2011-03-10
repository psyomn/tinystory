#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Tokenizer.cpp"
#include "FileHandler.cpp"
#include "TagParser.cpp"
#include "dsQueue.cpp"

int main(){
  //FileHandler f("example.txt");
  //Tokenizer tok(f.getContents()); 
  //f.writeFile("testtheclass.txt", "hello world!");
  //TagParser tp(tok);
  
  Queue<string> q;

  q.push("derp");
  q.push("1234");
  q.push("qwer");

  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  return 0;
}
