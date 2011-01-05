/**
* @author: Simon (psyomn) Symeonidis
* 
*/
#ifndef _TINYSTORYENGINE_H_
#define _TINYSTORYENGINE_H_

class TinyStoryEngine {
public:
  TinyStoryEngine();       /** Main constructor. Since no filename is specified, the constructor will take care of prompting the user with a filename */
  TinyStoryEngine(string); /** Constructor with a given filename */
  ~TinyStoryEngine();      /** Main destructor  */

private:

};

#endif
