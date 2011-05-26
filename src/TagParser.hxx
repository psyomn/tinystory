#ifndef TAGPARSER_HXX
#define TAGPARSER_HXX

#include <iostream>
#include <string>
#include <vector>

#include "FileHandler.hxx"

/** Takes care of generating the proper javascript for the story. 
\author psyomn 
\license gplv3 */
class TagParser {
public:
  TagParser();
  ~TagParser();
  void setTokens(std::vector<std::string>*);
  void parse(); 
private: 
  /** This is a pointer to the tokens that will be used. This
  assumes that the object holding the other tokens (in this case
  Tokenizer) will outlive this object - else you're going to get
  some very nasty memory errors. */
  const std::vector<std::string>* pTokens; 
  std::string mStoryname; /** Title of the story. */
  std::string mOutputJS; /** The JS to be written to a file */
  static std::string mIdent; /** Simply to set indentation in output files. */

  // Function shortcuts to generate html
  std::string generateChoiceHTML(std::string,std::string,std::string,std::string);
  std::string generateStoryHTML(std::string,std::string);
};

#endif

