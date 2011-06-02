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
   o #AUTHOR <name of auth> #ENDAUTHOR
   o #BLOB <int>
   o #GOTO <int> <label goes here> #ENDGOTO 
   
   First pass -> Parse the blobs
   Blobs are stored as strings, with the first element being [id] 
   Second pass -> Parse the gotos 

*/
void TagParser::parse(){ 
  std::vector<std::string>::const_iterator it; 
  std::string current_blob_id; 
  FileHandler fh("story.js"); // The output file. 
  
  mOutputJS.clear();  // Remove possible previous contents 

  try {
    if (!pTokens) throw "You have to set the token pointer before parsing."; 
    // As a rule of thumb, we proceed to the next iteration, each time a tag
    // has been found. Unless the tag is special, and has no arguments. 

    mOutputJS += parseCOMMENTS(); 

    for ( it=pTokens->begin(); it!=pTokens->end(); ++it){
      if (!it->compare("#BLOB")){
        ++it; // Need to store the next token as id
        current_blob_id = *it; 
        mOutputJS += parseBLOB(it); 
      } else if (!it->compare("#AUTHOR")){
        ++it;
        mOutputJS += parseAUTHOR(it); 
      } else if (!it->compare("#TITLE")){
        ++it; 
        mOutputJS += parseTITLE(it); 
      } else if (!it->compare("#GOTO")){
        ++it;
        mOutputJS += parseGOTO(it,current_blob_id);
      } else if (!it->compare("#END")){
        mOutputJS += parseEND(current_blob_id);  
      }
    }

    std::cout << "Js output contents : " << std::endl; 
    std::cout << mOutputJS  << std::endl;
    fh.write(mOutputJS); // Write out the contents 

  }
  catch(char* str){
    std::cout << str << std::endl; // print the error message 
  }
}

/** Routine to clean up code from the parsing routine 
// TODO see if this is needed when I'm done 
*/
std::string TagParser::generateChoiceHTML(std::string label, std::string id, std::string gtid){
  std::string tmp = "";
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

/** Routine to generate the Ending javascript/html */
std::string TagParser::parseEND(std::string id){
  std::string tmp = "";
  tmp += mIdent; // Ident for easier debugging
  tmp += "choiceArray[" + id + "] = \"";
  tmp +=  "\";\n";
  return tmp;
}

/** Read, and parse the GOTO Tags. This extracts the GOTO Id, and label, generates the html and returns it*/
std::string TagParser::parseGOTO(std::vector<std::string>::const_iterator it, std::string blob_id) {
  std::string str="";
  std::string gotoID = *it; 

  ++it; // We got the gotoid, so we continue, get the label 

  while (it->compare("#ENDGOTO")){
    str += *it + " "; 
    ++it; 
  }

  // Now generate the html. 
  str = generateChoiceHTML(str,blob_id,gotoID); 

  return str;
}

/** Parse the blob section (the paragraphs of a section of a story). This function takes in the 
iterator position at the blobid (one iteration after the #BLOB tag) \param it is the iterator
at a position after #BLOB tag */
std::string TagParser::parseBLOB(std::vector<std::string>::const_iterator it) { 
  std::string str = "";
  std::string id = *it; // First value of iterator is blobid
  ++it; // Ignore the id for the rest of the tokens now... 
  while (it->find('#') == std::string::npos){
    str += *it; 
    str += " "; 
    ++it; 
  }
  str = generateStoryHTML(str, id); 
  str += parseEND(id); // this makes sure that we don't get undefined messages again in javascript
  return str;
}

std::string TagParser::parseAUTHOR(std::vector<std::string>::const_iterator it){
  std::string str;
  str += "authorOfStory = \"";
  while ( it->compare("#ENDAUTHOR") ){
    str += *it + " "; 
    ++it;
  }
  str += "\";\n";
  return str;
}

std::string TagParser::parseTITLE(std::vector<std::string>::const_iterator it){
  std::string str;
  str += "titleOfStory = \"";
  while ( it->compare("#ENDTITLE") ){
    str += *it + " "; 
    ++it;
  }
  str += "\";\n";

  return str;
}
/** This function will be called for adding a commented header for the .js file 
to give a slight insight to peeping eyes. It also declares the array vars to 
be used. */
std::string TagParser::parseCOMMENTS() {
  std::string str;
  
  str += "/*\n";
  str += "  Generated with TinyStory version 1.1 \n"; 
  str += "  ------------------------------------ \n"; 
  str += "  What you will find in this file, is the very simple datastructure in javascript \n";
  str += "  which stores the story paragrahs, and the choices. \n\n"; 
  str += "  TinyStory author: psyomn@xenagoras.net - Send hate,love,praise! \n";
  str += "*/\n\n"; 

  str += "var storyArray = new Array();\n";
  str += "var choiceArray = new Array();\n";
  str += "var titleOfStory = \"\";\n";
  str += "var authorOfStory = \"\";\n\n";

  return str; 
}

#endif 


