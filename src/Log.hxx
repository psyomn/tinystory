#ifndef LOG_HXX
#define LOG_HXX

#include <string> 
#include <ctime>
#include <fstream> 

/** This is a singleton class which aims to store logs to a file. */
class Log {
public:
  static Log* Inst(std::string); 
  static Log* Inst(std::string,std::string); 
  void logMessage(std::string); 
  void init(); 
  ~Log(); 
private: 
  Log(std::string);
  Log(std::string,std::string);
  static Log* pInst; /** The main instance of the class */
  std::string mName; /** The name of the folder to check */
  std::string mPath; /** The path to the log files */
  std::ofstream mFile; /** Store the file handle */

  // Functions 
  std::string getTime();
  std::string getDate(); 
};

#endif 
