/**
* @auth psyomn
* implementation of the queue 
*/

#ifndef _DSQUEUE_CPP_
#define _DSQUEUE_CPP_

#include <iostream>
using namespace std;

#include "dsQueue.h" // Header
#include "Node.h"    // Standard node class

template <class T> Queue<T>::Queue(){
  size   = 0;
  pFront = 0; // Head is null
  pBack  = 0; // Tail is null
}

template <class T> Queue<T>::~Queue(){
  // TODO!  
}

template <class T> bool Queue<T>::empty(){
  // The queue is empty
  if( !pFront && !pBack ) { return true; }
  // The queue is not empty
  else { return false; }
}

template <class T> int Queue<T>::getSize(){
  return size;
}

template <class T> void Queue<T>::push(T d){
  Node<T>* n = new Node<T>;
  n->dat = d;
  
  if ( empty() ){
    pFront = n; 
  }
  else{
    // case 1: pBack is NULL
    // case 2: pBack not NULL

    if ( !pBack ){ // if null
      pBack = n;
      pFront->pNext = pBack;
    }
    else {
      pBack->pNext = n; // Add the new node to the tail
      pBack = n;        // the tail is now the new node
    }
  }
  size++;
}

template <class T> T Queue<T>::pop(){
  T result;
  if (pFront){ // not null
    result = pFront->dat;
    if (pFront->pNext){
      Node<T>* p;
      p = pFront;
      pFront = pFront->pNext;
      delete p;
    }
    else{
      pFront = NULL;
    }
  }

  size--;
  return result;
}
template <class T> void Queue<T>::print(){
  Node<T>* p;
  p = pFront;
  int i = 0;

  while(p){ // while the node is not null
    cout << i << " " << p->dat << endl;
    i++;
    p = p->pNext; // set for the next iteration
  }
}
#endif
