#ifndef FILEHANDLER_HXX
#define FILEHANDLER_HXX

#include <fstream>
#include <string>
#include <iostream> 

/** Simple class that handles 
\author psyomn 
*/
class FileHandler {
public: 
  FileHandler();
  FileHandler(std::string);
  virtual ~FileHandler();
  std::string read();
  void write(std::string);
private: 
  std::string mFilename; /** Filename to open */

};

#endif

