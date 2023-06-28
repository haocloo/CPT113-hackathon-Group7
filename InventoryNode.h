#ifndef INVENTORYNODE_H
#define INVENTORYNODE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Item.h"
#include "Node.h"


// InventoryNode as derived class of Node
class InventoryNode : public Node<InventoryNode>
{
private:
  Item *item; // Pointer to the item in the node
public:
  // Constructor that takes an item as parameter and initializes the private member and calls the base class constructor
  InventoryNode(Item *item) : Node(), item(item) {}

  // Getter method that returns the pointer to the item in the node
  Item *getItem() const
  {
    return item;
  }
};

#endif