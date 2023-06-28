#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// Define a class for nodes of Linked List
// Node as base class
template <class T>
class Node
{
protected:
  T *next;   // Pointer to the next node
  T *prev;   // Pointer to the previous node
  T *hidden; // Pointer to a hidden node

public:
  // Default constructor that sets all pointers to null
  Node()
  {
    this->next = nullptr;
    this->prev = nullptr;
    this->hidden = nullptr;
  }

  // Getter method that returns the pointer to the next node
  T *getNext() const
  {
    return next;
  }

  // Getter method that returns the pointer to the previous node
  T *getPrev() const
  {
    return prev;
  }

  // Getter method that returns the pointer to the hidden node
  T *getHidden() const
  {
    return hidden;
  }

  // Setter method that sets the pointer to the next node
  void setNext(T *next)
  {
    this->next = next;
  }

  // Setter method that sets the pointer to the previous node
  void setPrev(T *prev)
  {
    this->prev = prev;
  }

  // Setter method that sets the pointer to the hidden node
  void setHidden(T *hidden)
  {
    this->hidden = hidden;
  }
};

#endif