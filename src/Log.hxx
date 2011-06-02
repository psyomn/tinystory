#ifndef LOG_HXX
#define LOG_HXX

#include <string> 
#include <ctime>

/** This is a singleton class which aims to store logs to a file. */
class Log {
public:
  static Log* Inst(std::string); 
  void logMessage(std::string); 
  void init(); 
  ~Log(); 
private: 
  Log(std::string);
  static Log* pInst; /** The main instance of the class */
  std::string mName; 

  // Functions 
  std::string getTime();
  std::string getDate(); 
};

#endif 
