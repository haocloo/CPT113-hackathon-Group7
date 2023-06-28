#ifndef TREASURE_H
#define TREASURE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Define a class for treasure
class Treasure
{
private:
  string message;      // The message for the treasure
  string requirement1; // The first item required to unlock the treasure
  string requirement2; // The second item required to unlock the treasure
  int password;        // The password to access the treasure

public:
  // Constructor that takes a message, two requirements and a password as parameters and initializes the private members
  Treasure(string message, string requirement1, string requirement2, int password)
  {
    this->message = message;
    this->requirement1 = requirement1;
    this->requirement2 = requirement2;
    this->password = password;
  }
  
  // Getter method that returns the message of the treasure
  string getMessage() const
  {
    return message;
  }
  // Getter method that returns the first requirement of the treasure
  string getRequirement1() const
  {
    return requirement1;
  }
  // Getter method that returns the second requirement of the treasure
  string getRequirement2() const
  {
    return requirement2;
  }
  // Getter method that returns the password of the treasure
  int getPassword() const
  {
    return password;
  }
};

#endif
