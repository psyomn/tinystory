/**
* @author Simon (psyomn) Symeonidis
* This is the actual implementation of the class
*/
#include "FileHandler.h"

// Constructor
FileHandler::FileHandler(){
 // TODO
}

FileHandler::FileHandler(string fname){
 // TODO
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

void FileHandler::init(){
  //TODO
}

string FileHandler::processFile(){

}
