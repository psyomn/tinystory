#include "Tokenizer.hxx"

/** Default constructor */
Tokenizer::Tokenizer()
{}

/** Default constructor */
Tokenizer::~Tokenizer()
{
  mTokens.clear();
}

/** Main tokenizing function. Does not store
null tokens. \param str is a reference to the 
string to tokenize */
void Tokenizer::tokenize(std::string& str)
{
  std::stringstream ss; 
  std::string tmp;

  ss.str(str + "  ");
  
  while(ss >> tmp)
  {
    mTokens.push_back(tmp);
  }
}

/** Function to tokenize the story \param fname 
is the name of the story-file to read and tokenize */
void Tokenizer::tokenizeStory(std::string fname)
{
  std::string tmp;
  FileHandler fh(fname); 
  tmp = fh.read();
  tokenize(tmp);
}

/** Return the tokens read only for whatever reason */
const std::vector<std::string> Tokenizer::getTokens() const 
{
  return mTokens;
}

/** This prints the vector. This is a debugging routine.  */
void Tokenizer::print() const 
{
  std::vector<std::string>::const_iterator it;

  for (it=mTokens.begin(); it!=mTokens.end(); ++it)
  {
    std::cout << *it << "."; 
  }
  std::cout << std::endl << &mTokens << std::endl;
}

/** Get a pointer to the vector containing the tokens */
std::vector<std::string>* Tokenizer::getPointerToTokens() 
{
  return &mTokens;
}


