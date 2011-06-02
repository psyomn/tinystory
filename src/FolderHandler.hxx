#ifndef FOLDERHANDLER_HXX
#define FOLDERHANDLER_HXX

#include <dirent.h>
#include <string> 

/** Small utility class that will wrap dirent calls, and provide an object oriented 
interface for all our needs */
class FolderHandler {
public:
  FolderHandler(std::string);
  ~FolderHandler(); 
  bool exists(); 
  void make(); 
private:
  std::string mName; 
};

#endif 

