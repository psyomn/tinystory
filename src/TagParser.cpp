/**
* Implementation of the Tag Parser
*/


#ifndef _TAGPARSER_CPP_
#define _TAGPARSER_CPP_

#include "TagParser.h"

TagParser::TagParser(){

}

TagParser::TagParser(Tokenizer tok){
}

string TagParser::getHtml(){
  return html;
}

void TagParser::setHtml(string set){
  html = set;
}

void TagParser::addH(string str){
  html += str;
}

#endif
