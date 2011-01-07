/** 
* @author: Simon (psyomn) Symeonidis
* This is the heart of the Engine. It takes care of going
* through each token, and parsing it appropriately. 
* It stores the output in a string, and later on passes it 
* to a FileHandler object for a writeout.
*/
#ifndef _TAGPARSER_H_
#define _TAGPARSER_H_


class TagParser {
public:
  /** Main constructor for the tag parser. */
  TagParser();
  /** 
  * Overloaded constructor for the Tag Parser
  * @param Tokenizer accepts a tokenizer object, and parses the elements 
  * from there.
  */
  TagParser(Tokenizer);
 
  // --== Accessors / Mutators ==--
  /** Used to retrieve the html which is generated
  * @return html string
  */
  string getHtml();
  /** 
  * Sets the given string as the html to output
  * @param str
  */ 
  void setHtml(string);
  /**
  * Appends the string to the current string
  */
  void addH(string);
private:
  string html;  
};

#endif
