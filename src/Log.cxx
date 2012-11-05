#include "Log.hxx" 

Log* Log::pInst = 0; // Set pointer as zero before anything 

/** Create the singleton with filename only */
Log* Log::Inst() {
  if (pInst == 0) {
    pInst = new Log(); 
  }
  return pInst; 
}

/** Default constructor */
Log::Log() : mName(std::string(getDate() + ".log")) {
}

Log::~Log(){
  mFile.close(); 
}

/** Helper function to give logs unix timestamps */
std::string Log::getTime(){
  std::string str;
  std::stringstream ss; 
  time_t raw; 

  ss.str(""); // Clear for whatever reason. 
  time ( &raw );
 
  ss << raw; 

  return ss.str(); 
}

/** This will be used in order to generate filenames in the format
of DD_MM_YYYY */
std::string Log::getDate(){
  std::string str;
  std::stringstream ss; 
  struct tm * cal; 
  time_t raw; 

  ss.str(""); // Clear for whatever reason. 
  time ( &raw );
  cal = localtime( &raw ); 

  ss << cal->tm_mday; 
  ss << "_"; 
  ss << (cal->tm_mon+1); 
  ss << "_"; 
  ss << (cal->tm_year+1900); 

  return ss.str(); 
}

/** Log the the message using this routine */
void Log::logMessage(std::string str){
  mFile.open(mName.c_str(), std::fstream::app); 
  if(mFile){ 
    mFile << getTime(); // Add unix timestamp as prefix
    mFile << "  |  "; 
    mFile << str;
    mFile << std::endl;
    mFile.close();
  } else {
    std::cout << "FATAL: Logging class cannot open needed file " << std::endl;
  }
}
