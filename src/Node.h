/**
* @auth psyomn
* This class is left totally public as security should be
* taken care of by the actual data structures. I'm doing 
* this to reduce code clutter.
*/
#ifndef _NODE_H_
#define _NODE_H_

template <class D>
class Node {
public:
  D dat;
  Node<D>* pNext;

  Node<D>(){
    pNext = 0; 
  }
  ~Node(){
    if(!pNext){ delete pNext; }
  }

};

#endif
