#ifndef ROOMLIST_H
#define ROOMLIST_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "RoomNode.h"
// Define a class for linked list
class RoomList
{
private:
  RoomNode *head; // Pointer to the head of the list
  RoomNode *tail; // Pointer to the tail of the list
public:
  // Default constructor that sets the head and tail pointers to null
  RoomList() : head(nullptr), tail(nullptr) {}

  // Destructor that deletes all the nodes in the list
  ~RoomList()
  {
    RoomNode *current = head;
    while (current != nullptr)
    {
      RoomNode *next = current->getNext();
      delete current;
      current = next;
    }
  }

  // Insert a node at the end of the list
  void insertNode(string roomName, string description, Item *item, Treasure *treasure)
  {
    RoomNode *newNode = new RoomNode(roomName, description, item, treasure);
    if (head == nullptr)
    { // If the list is empty
      head = newNode;
      tail = newNode;
    }
    else
    { // If the list is not empty
      tail->setNext(newNode);
      newNode->setPrev(tail);
      tail = newNode;
    }
  }

  // Insert a hidden node after a given room name in the list
  void insertHidden(string hiddenRoomName, string description, Item *item, Treasure *treasure, string roomName)
  {
    RoomNode *newNode = new RoomNode(hiddenRoomName, description, item, treasure);
    RoomNode *temp = head;

    while (temp->getRoomName() != roomName && temp != nullptr)
      temp = temp->getNext(); // Set temp to the node with the given room name (library)

    if (temp->getHidden() == nullptr)
    { // If there is no hidden node after temp
      temp->setHidden(newNode);
      newNode->setPrev(temp);
    }
    else
    { // If there is already a hidden node after temp
      newNode->setNext(temp->getHidden());
      temp->getHidden()->setPrev(newNode);
      temp->setHidden(newNode);
      newNode->setPrev(temp);
    }
  }

  // Get the head pointer of the list
  RoomNode *getHead() const
  {
    return head;
  }
};

#endif