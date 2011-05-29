#ifndef TAGPARSER_CXX
#define TAGPARSER_CXX

#include "TagParser.hxx" 

std::string TagParser::mIdent = "  ";

/** Default constructor. Set param pTokens to zero. */
TagParser::TagParser() : 
  pTokens(0), 
  mStoryname(""),
  mOutputJS(""){}

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
   o #TITLE <set of words> #ENDTITLE
   o #BLOB <int>
   o #GOTO <int>
*/
void TagParser::parse(){ 
  std::vector<std::string>::const_iterator it;
  std::string tempBlob = ""; 
  std::string blobID = ""; 
  std::string gotoID = ""; 
  std::string prevgtid = "";
  std::string authorName = "";
  std::string tmplabel = ""; 
  FileHandler fh("story.js");

  // Begin the Javascript stuff
  mOutputJS = ""; 
  mOutputJS += "/** All the story stored as the array."; 
  mOutputJS += "\nThese are globals and should not be tampered with */\n";
  mOutputJS += "var storyArray = new Array(); \n";
  mOutputJS += "var choiceArray = new Array(); \n";

  // End the beginning

  for (it = pTokens->begin(); it != pTokens->end(); ++it){
    if ( !it->compare("#TITLE") ) {
      ++it;
      mStoryname = "";
      
      while (it->compare("#ENDTITLE")){
        mStoryname += *it + " ";
        ++it;
      }
      
      mOutputJS += "var titleOfStory = \"" + mStoryname + "\";\n";
    } else if ( !it->compare("#BLOB") ) {
      ++it; 
      std::cout << "BLOB detected with id : " << *it << std::endl;

      // If new blob id, then it means we have to dump
      // The previously accumulated data
      if (blobID != "") {
        mOutputJS += generateStoryHTML(tempBlob, blobID);
      }

      tempBlob = "";
      blobID = *it; 
    } else if ( !it->compare("#GOTO") ) {
      ++it;
      std::cout << "GOTO detected with id : " <<  *it << std::endl;
      gotoID = *it; 
      tmplabel = "";

      ++it; 
      while ( it->compare("#ENDGOTO") ) {
        tmplabel += *it + " ";
        ++it;
      }

      std::cout << std::endl;

      mOutputJS += generateChoiceHTML(tmplabel,blobID,gotoID,prevgtid);
      prevgtid = blobID;
    } else if ( !it->compare("#AUTHOR") ) {
      std::cout << "Detected Author Tag" << std::endl;
      ++it;
      while( it->compare("#ENDAUTHOR") ) {
        authorName += *it + " ";  // Store whatever the author name is 
        ++it;
      }
      mOutputJS += "var authorOfStory = \"" + authorName + "\";\n";
    } else {
      std::cout << "Blob token : " << *it << std::endl;
      tempBlob += *it + " ";
    }
  }

  mOutputJS += generateStoryHTML(tempBlob, blobID);
  mOutputJS += mIdent + "choiceArray[" + blobID + "] = \"\";";

  // Print the resulting file for 
  std::cout << mOutputJS << std::endl;
  fh.write(mOutputJS);
}

/** Routine to clean up code from the parsing routine */
std::string TagParser::generateChoiceHTML(std::string label, std::string id, std::string gtid, std::string previous_gtid){
  std::string tmp = "";
  if (previous_gtid != id) 
    tmp += mIdent + "choiceArray[" + id + "] = \"\"; \n";
  tmp += mIdent; // Ident for easier debugging
  tmp += "choiceArray[" + id + "] += \"";
  tmp += "<input class=\'block button\' type=\'button\' value=\'";
  tmp += label + "\' ";
  tmp += "onClick=\'javascript:swap(" + gtid + ");\'";
  tmp += " />";
  tmp +=  "\";\n";
  return tmp;
}

/** Routine to clean up code from the parsing routine */
std::string TagParser::generateStoryHTML(std::string blob, std::string id){
  std::string tmp = "";
  tmp += "storyArray[" + id + "] = \"<p> ";  
  tmp += blob + "</p> \"; \n";
  return tmp;
}

#endif 

