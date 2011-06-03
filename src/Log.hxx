#ifndef LOG_HXX
#define LOG_HXX

#include <iostream>
#include <string> 
#include <ctime>
#include <fstream> 
#include <sstream> 

/** This is a singleton class which aims to store logs to a file. The log file
names are just named with the date DD_MM_YYYY.txt. If the file exists, the
new contents are appended. */
class Log {
public:
  static Log* Inst(); 
  void logMessage(std::string); 
  void init(); 
  ~Log(); 
private: 
  Log();
  static Log* pInst; /** The main instance of the class */
  std::string mName; /** The name of the folder to check */
  std::string mPath; /** The path to the log files */
  std::ofstream mFile; /** Store the file handle */

  // Functions 
  std::string getTime();
  std::string getDate(); 
};

#endif 
