#ifndef TAGPARSER_CXX
#define TAGPARSER_CXX

#include "TagParser.hxx" 

/** Default constructor. Set param pTokens to zero. */
TagParser::TagParser() : 
  pTokens(0){}

/** \warning if this class is inherited, set to virtual, since
dealing with pointers. */
TagParser::~TagParser(){
}

/** Set the reference for the tokens */
void TagParser::setTokens(std::vector<std::string>* vectok) {
  pTokens = vectok;
}

/** Main function to parse the file info. 
 - Tags of interest
   o #BLOB <int>
   o #GOTO <int>
*/
void TagParser::parse(){ 
  std::vector<std::string>::const_iterator it;

  std::cout << pTokens << std::endl;

  for (it = pTokens->begin(); it != pTokens->end(); ++it){
    if ( !it->compare("#BLOB") ) {
      ++it; 
      std::cout << "BLOB detected with id : " << *it << std::endl;

    } else if ( !it->compare("#GOTO") ) {
      ++it;
      std::cout << "GOTO detected with id : " <<  *it << std::endl;
    } else {
      std::cout << "Blob token : " << *it << std::endl;
    }
  }
}

#endif 

