#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// Define a class for items
class Item
{
private:
  string clue; // The clue for the item
  string name; // The name of the item
public:
  // Constructor that takes a clue and a name as parameters and initializes the private members
  Item(string clue, string name)
  {
    this->clue = clue;
    this->name = name;
  }
  // Getter method that returns the clue of the item
  string getClue() const
  {
    return clue;
  }
  // Getter method that returns the name of the item
  string getName() const
  {
    return name;
  }
};

#endif