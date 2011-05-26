#ifndef TAGPARSER_HXX
#define TAGPARSER_HXX

#include <iostream>
#include <string>
#include <vector>

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
};

#endif

