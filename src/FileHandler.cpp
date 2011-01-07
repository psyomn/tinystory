#ifndef _FILEHANDLER_CPP_
#define _FILEHANDLER_CPP_
/**
* @author Simon (psyomn) Symeonidis
* This is the actual implementation of the class
* 
* (Note/Todo : safeness of class - make sure processFile
* cannot be executed if no fileName given)
*/
#include "FileHandler.h"
// Constructor
FileHandler::FileHandler(){
  string s;

  cout << "You have not specified a filename. Give a filename:";
  cin >> s;
  fileName = s;
}

FileHandler::FileHandler(string fname){
  fileName = fname;
}

FileHandler::~FileHandler(){
  fileName = "";
}

void FileHandler::setFilename(string f){
  fileName = f;
}

string FileHandler::getContents(){
  return processFile();
}

string FileHandler::processFile(){
  ifstream read;
  string str;
  string str2;

  read.open(fileName.c_str());
  while(!read.eof()){
    getline(read, str2);
    str2 += "\n";
    str += str2;
  }
  
  read.close();
  return str;
}

void FileHandler::clear(){
  contents.clear(); // Clear the string safely. Save space. Save trees.
}

void FileHandler::writeFile(string fname, string contents){
  ofstream out;
  out.open(fname.c_str()); // Open a file for writing
  out.write(contents.c_str(), contents.length());
  out.close(); // Close the file when done
}

#endif
