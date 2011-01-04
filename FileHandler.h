#ifndef _FILEHANDLER_H_
#define _FILEHANDLER_H_

/**
*  @author Simon (psyomn) Symeonidis
*  @file
*  This is a helper class to help access files.
*/

class FileHandler{
public:
  /** Plain Constructor*/
  FileHandler(); 
  
  /** Overloaded Constructor
  * @param fileName the filename of the file to open
  */
  FileHandler(string); 
  
  /** The destructor for this class */
  ~FileHandler();

  // Accessors and Mutators

  /** Mutator to set the filename */
  void setFilename(string);

  /** Accessor to retrieve the output */
  string getContents();

  // Functions

  /** Init Manually */
  void init();
private:
  string fileName;
  
  /** The actual method to process the files */
  string processFile();
};

#endif
