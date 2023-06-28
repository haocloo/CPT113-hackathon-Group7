#ifndef ROOMNODE_H
#define ROOMNODE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Item.h"
#include "Treasure.h"
#include "Node.h"

// RoomNode as derived class of Node
class RoomNode : public Node<RoomNode>
{
private:
  string roomName;    // The name of the room
  string description; // The description of the room
  Item *item;         // Pointer to the item in the node
  Treasure *treasure; // Pointer to the treasure in the node
public:
  // Constructor that takes a room name, a description, an item and a treasure as parameters and initializes the private members and calls the base class constructor
  RoomNode(string roomName, string description, Item *item, Treasure *treasure) : Node()
  {
    this->roomName = roomName;
    this->description = description;
    this->item = item;
    this->treasure = treasure;
  }

  // Getter method that returns the pointer to the item in the node
  Item *getItem() const
  {
    return item;
  }

  // Getter method that returns the pointer to the treasure in the node
  Treasure *getTreasure() const
  {
    return treasure;
  }

  // Getter method that returns the name of the room
  string getRoomName() const
  {
    return roomName;
  }

  // Getter method that returns the description of the room
  string getDescription() const
  {
    return description;
  }

  // Setter method that sets the pointer to the item to null
  void resetItem()
  {
    this->item = nullptr;
  }
};

#endif
