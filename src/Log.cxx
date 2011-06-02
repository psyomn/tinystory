
#ifndef LOG_CXX
#define LOG_CXX

#include "Log.hxx" 

Log* Log::pInst = 0; // Set pointer as zero before anything 

Log* Log::Inst( std::string filename ) {
  if (pInst == 0) {
    pInst = new Log(filename); 
  }
  return pInst; 
}

Log::Log(std::string fname) : mName(fname) {

}

std::string Log::getTime(){
 return "DERP"; 
}

std::string Log::getDate(){
 return "DERP"; 
}

#endif 

