#ifndef LOG_CXX
#define LOG_CXX

#include "Log.hxx" 

Log* Log::pInst = 0; // Set pointer as zero before anything 

/** Create the singleton with filename only */
Log* Log::Inst( std::string filename ) {
  if (pInst == 0) {
    pInst = new Log(filename); 
  }
  return pInst; 
}

/** Create the singleton with path and filename */
Log* Log::Inst( std::string filename, std::string path ) {
  if (pInst == 0) {
    pInst = new Log(filename,path); 
  }
  return pInst; 
}

/** Default constructor */
Log::Log(std::string fname) : mName(fname) {
  mFile.open(mName.c_str()); 
}

/** Constructor with filename and path */
Log::Log(std::string path, std::string fname) : 
  mName(fname),
  mPath(path){
  mFile.open(std::string(mPath + mName).c_str()); 
}

Log::~Log(){
  mFile.close(); 
}

/** Helper function to give logs unix timestamps */
std::string Log::getTime(){
 return "DERP"; 
}

/** This will be used in order to generate filenames in the format
of DD_MM_YYYY */
std::string Log::getDate(){
 return "DERP"; 
}

/** Log the the message using this routine */
void Log::logMessage(std::string str){
  mFile << str;  
}

#endif 

