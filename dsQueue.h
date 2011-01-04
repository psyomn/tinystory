/**
* @auth psyomn
* A simple queue DS
*/

#ifndef _DSQUEUE_H_
#define _DSQUEUE_H_

#include "Node.h"

template < class T > 
class Queue {
public:
  Queue<T>();      /** Main Constructor */
  ~Queue<T>();     /** Destructor */
  bool empty();    /** Check to see if DS is empty */
  int getSize();   /** Get the current size of the queue*/
  void push(T);    /** Insert a data element to the queue  */
  T pop();         /** Remove/retrieve an item */
  // Additional Functions
  void print();
private:
  Node<T>* pFront; /** The head of the Queue */
  Node<T>* pBack;  /** The tail of the Queue */
  int size;        /** Current size of the queue */
};

#endif
