#ifndef FILEHANDLER_CXX
#define FILEHANDLER_CXX

#include "FileHandler.hxx"

/** Default constructor with no filename set. Default filename
then is story.txt */
FileHandler::FileHandler() : 
  mFilename("story.txt"){}

/** \param fname the filename that will be opened. If name is
not set, then story.txt will be used. */
FileHandler::FileHandler(std::string fname="story.txt") :
  mFilename(fname){}

/** Default constructor */
FileHandler::~FileHandler(){
  mFilename.clear();
}

/** Read contents from a file. \param mFilename must be set */
std::string FileHandler::read(){
  std::ifstream ifs;
  int fsize; // file size
  char* buff;

  ifs.open(mFilename.c_str());

  if(ifs){
    ifs.seekg(0,std::ios::end);
    fsize = ifs.tellg();
    ifs.seekg(0,std::ios::beg);
    buff = new char[fsize];
    ifs.read(buff,fsize);
    ifs.close();
  } else {
    buff = (char*) "[FAIL]";
    std::cout << "Warning - failure opening file : " << mFilename << std::endl; 
  }
  return buff; 
}

/** Function to write to a file. \param buff is the
buffer to write out. */
void FileHandler::write(std::string buff){
  std::ofstream ofs; 
  ofs.open(mFilename.c_str()); 
  ofs << buff; 
  ofs.close();
}

#endif

