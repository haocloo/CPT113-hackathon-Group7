#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "InventoryNode.h"

// Define a class for linked list
class InventoryList
{
private:
  InventoryNode *head; // Pointer to the head of the list
  InventoryNode *tail; // Pointer to the tail of the list
public:
  // Default constructor that sets the head and tail pointers to null
  InventoryList() : head(nullptr), tail(nullptr) {}

  // Destructor that deletes all the nodes in the list
  ~InventoryList()
  {
    InventoryNode *current = head;
    while (current != nullptr)
    {
      head = current->getNext();
      delete current;
      current = head;
    }
  }

  // Insert a node at the end of the list
  void insertNode(Item *item)
  {
    InventoryNode *newNode = new InventoryNode(item);
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

  // Delete a node from the list by item name
  void deleteNode(string name)
  {
    InventoryNode *temp = head;
    while (temp != nullptr)
    { // Traverse the list until finding the node with the item name
      if (temp->getItem()->getName() == name)
      {
        break;
      }
      temp = temp->getNext();
    }
    if (temp == nullptr)
    { // If the node is not found, do nothing
      return;
    }
    else
    { // If the node is found, delete it from the list
      if (temp == head && temp == tail)
      { // If the node is the only node in the list
        head = nullptr;
        tail = nullptr;
      }
      else if (temp == head)
      { // If the node is the head of the list
        head = head->getNext();
        head->setPrev(nullptr);
      }
      else if (temp == tail)
      { // If the node is the tail of the list
        tail = tail->getPrev();
        tail->setNext(nullptr);
      }
      else
      { // If the node is in the middle of the list
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
      }
      delete temp; // Free the memory of the node
    }
  }

  // Check if a node exists in the list by item name
  bool existsNode(string name)
  {
    InventoryNode *temp = head;
    while (temp != nullptr)
    { // Traverse the list until finding the node with the item name
      if (temp->getItem()->getName() == name)
      {
        return true; // Return true if found
      }
      temp = temp->getNext();
    }
    return false; // Return false if not found
  }

  // Print the list from head to tail
  void printList()
  {
    InventoryNode *temp = head;
    if (head == nullptr)
    { // If the list is empty
      cout << "There is nothing in your bag." << endl;
      return;
    }
    cout << "\n> Your bag contains: ";
    while (temp != nullptr)
    { // If the list is not empty
      cout << temp->getItem()->getName();
      if (temp->getNext() != nullptr)
      {
        cout << ", ";
      }
      temp = temp->getNext();
    }
    cout << endl;
  }

  // Get the head pointer of the list
  InventoryNode *getHead() const
  {
    return head;
  }
};

#endif