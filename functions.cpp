#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "RoomList.h"
#include "RoomNode.h"
#include "InventoryList.h"
#include "Item.h"
// #include "InventoryNode.h"
// #include "Node.h"

string Title_Case(string str)
{

  for (int i = 0; i < str.length(); i++)
  {
    str[i] = tolower(str[i]);
  }

  char First_capital = static_cast<int>(str[0]) - 32;
  string newStr;
  newStr = First_capital;

  for (int i = 1; i < str.size(); i++)
  {
    if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z')
    {
      char capital = str[i] - ('a' - 'A');
      newStr += capital;
      continue;
    }
    else
      newStr = newStr + str[i];
  }

  return newStr;
}

// Define a function to save the game
void saveGame(int slot, RoomList rooms, RoomNode *current, InventoryList inventory, Item *hand, bool hasBag)
{
  // Save the current room
  ofstream file("save" + to_string(slot) + ".txt");

  // Save the bag state
  if (hasBag)
    file << "0" << endl;
  else
    file << "1" << endl;

  // Save the rooms' state
  RoomNode *temp1 = rooms.getHead()->getNext()->getNext();

  // InventoryNode *invItems = inventory.getHead();
  while (temp1 != nullptr)
  {
    if (temp1->getItem() != nullptr)
    {                      // If the room has an item
      file << "1" << endl; // Write 1 to indicate the item is present in room
      // file << "1 " << temp1->getItem()->getName() << endl; // Write 1 to indicate the item is present
      temp1 = temp1->getNext();
    }
    else
    { // If the room does not have an item
      // if (hasBag)
      // {
      if (temp1->getRoomName() == "Dining Room")
      {
        if (inventory.existsNode("Water") == true || (hand != nullptr && hand->getName() == "Water"))
        {
          file << "01" << endl; // Write 01 to indicate the item is absent in room and has not been used
        }
        else
        {
          file << "00" << endl; // Write 00 to indicate the item is absent in room and has been used
        }
      }
      else if (temp1->getRoomName() == "Garden")
      {
        if (inventory.existsNode("Box") == true || hand->getName() == "Box")
        {
          file << "01" << endl; // Write 01 to indicate the item is absent in room and has not been used
        }
        else
        {
          file << "00" << endl; // Write 00 to indicate the item is absent in room and has been used
        }
      }
      else
      {
        file << "0" << endl;
      }
      temp1 = temp1->getNext();
    }
  }


  RoomNode *temp2 = rooms.getHead()->getNext()->getNext()->getNext()->getNext()->getNext()->getHidden();
  while (temp2 != nullptr )
  {
        cout << temp2->getRoomName() << endl;

    if (temp2->getItem() != nullptr)
    {                      // If the room has an item
      file << "1" << endl; // Write 1 to indicate the item is present in room
      // file << "1 " << temp1->getItem()->getName() << endl; // Write 1 to indicate the item is present
      temp2 = temp2->getNext();
    }
    else
    { // If the room does not have an item
      if (temp2->getRoomName() == "Secret Room 1")
      {
        if (inventory.existsNode("Card1") == true)
        {
          file << "01" << endl; // Write 01 to indicate the item is absent in room and has not been used
        }
        else
        {
          file << "00" << endl; // Write 00 to indicate the item is absent in room and has been used
        }
      }
      else if (temp2->getRoomName() == "Secret Room 2")
      {
        if (inventory.existsNode("Card2") == true)
        {
          file << "01" << endl; // Write 01 to indicate the item is absent in room and has not been used
        }
        else
        {
          file << "00" << endl; // Write 00 to indicate the item is absent in room and has been used
        }
      }
      else if (temp2->getRoomName() == "Secret Room 3")
      {
        if (inventory.existsNode("Card3") == true)
        {
          file << "01" << endl; // Write 01 to indicate the item is absent in room and has not been used
        }
        else
        {
          file << "00" << endl; // Write 00 to indicate the item is absent in room and has been used
        }
      }else{
        file << "0" << endl;
      }
      temp2 = temp2->getNext();
    }
  }


  // Save the current room
  file << current->getRoomName() << endl; // Write the name of the current room

  // Save the inventory list
  // file << inventory.getSize() << endl;
  // InventoryNode *temp2 = inventory.getHead();
  // while (temp2 != nullptr)
  // {
  //   file << temp2->getItem()->getName() << endl; // Write the name of each item in the inventory
  //   temp2 = temp2->getNext();
  // }

  file.close(); // Close the file
}

// Define a function to load the game
bool loadGame(int slot, RoomList &rooms, RoomNode *&current, InventoryList &inventory, Item *&hand, bool &hasBag)
{
  ifstream file("save" + to_string(slot) + ".txt");
  string line;
  
    // reset item in room
  RoomNode *temp1 = rooms.getHead()->getNext();

  // Load hasBag state
  file >> line;
  if (line == "0")
  {
    temp1->resetItem();
    hasBag = true;
  }
  else
  {
    hasBag = false;
  }

  temp1 = rooms.getHead()->getNext()->getNext();

  while (temp1 != nullptr)
  {
    file >> line;
    // getline(file, line); // skip bag
    // line = line[0];
    if (line == "0" || line == "01")
    {
      if (hasBag)
      {
        inventory.insertNode(temp1->getItem()); // Insert the item to the inventory list
        temp1->resetItem();                     // Reset the item in the room if it is absent
      }
      else
      {
        if (hand == nullptr)
        {
          hand = temp1->getItem();
          temp1->resetItem();
        }
        continue;
      }
    }
    else if (line == "00")
    {
      hand = nullptr;
      temp1->resetItem(); // Reset the item in the room if it is absent
    }
    temp1 = temp1->getNext();
  }

  RoomNode *temp2 = rooms.getHead()->getNext()->getNext()->getNext()->getNext()->getNext()->getHidden();



  while (temp2 != nullptr)
  {

    file >> line;

    if (line == "0" || line == "01")
    {
        inventory.insertNode(temp2->getItem()); // Insert the item to the inventory list
        temp2->resetItem();                     // Reset the item in the room if it is absent
    }
    else if (line == "00")
    { 
      if(temp2->getRoomName() == "Secret Room 1"){
        inventory.insertNode(new Item("a keycard with a number 1 in a circle", "Keycard1"));
      }
      else if(temp2->getRoomName() == "Secret Room 2"){
        inventory.insertNode(new Item("a keycard with a number 2 in a circle", "Keycard2"));
      }
      else if(temp2->getRoomName() == "Secret Room 3"){
        inventory.insertNode(new Item("a keycard with a number 3 in a circle", "Keycard3"));
      }
      temp2->resetItem(); // Reset the item in the room if it is absent
    }
    temp2 = temp2->getNext();
  }

  getline(file, line); // consume endline
  getline(file, line); // Load current room

  if (line == "Secret Room 1" || line == "Secret Room 2" || line == "Secret Room 3" || line == "Final Secret Room")
  {
    temp2 = rooms.getHead()->getNext()->getNext()->getNext()->getNext()->getNext()->getHidden();
    while (temp2 != nullptr)
    {
      if (temp2->getRoomName() == line)
      {
        current = temp2; // Set the current room pointer to the matching room name
        break;
      }
      temp2 = temp2->getNext();
    }
  }
  else
  {
    temp1 = rooms.getHead();
    while (temp1 != nullptr)
    {
      if (temp1->getRoomName() == line)
      {
        current = temp1; // Set the current room pointer to the matching room name
        break;
      }
      temp1 = temp1->getNext();
    }
  }


  file.close(); // Close the file

  return true; // Return true to indicate successful loading
}

// Define a function to check whethere the save file is empty
bool isFileEmpty(const string &filename)
{
  ifstream file(filename);
  return file.peek() == ifstream::traits_type::eof();
}

// Define a function to loop the game
void gameloop(string &input, bool &gameover, RoomList &rooms, RoomNode *&current, InventoryList &inventory, Item *&hand, bool &hasBag)
{

  // Start the game loop
  while (!gameover)
  {
    cout << "\n------------------ " << current->getRoomName() << " ------------------" << endl;
    cout << current->getDescription() << endl;
    // Print the current room's clue
    if (current->getItem() != nullptr)
    {
      cout << "> There is " << current->getItem()->getClue() << "." << endl;
    }
    else
    {
      cout << "> There is nothing else in this room." << endl;
    }

    // Check if there is a treasure in the current room
    if (current->getTreasure() != nullptr)
    {
      // Print the treasure's message
      cout << current->getTreasure()->getMessage() << endl;

      // Check if the user has the required items and password to unlock the treasure
      if (inventory.existsNode(current->getTreasure()->getRequirement1()) &&
          inventory.existsNode(current->getTreasure()->getRequirement2()))
      {
        // Ask the player to enter the password
        int choice;
        do
        {
          cout << "Do you know the password??? (Y/N)	";
          cin >> choice;
        } while (toupper(choice) != 'Y' && toupper(choice) != 'N');

        while (toupper(choice) != 'N')
        {
          int password;
          do
          {
            cout << "What is the password???	";
            cin >> password;
          } while (password < 0 || password > 999999);

          if (current->getTreasure()->getPassword() == password)
          {
            // Print the winning message and end the game
            cout << "Correct password!" << endl;
            cout << "You use the " << current->getTreasure()->getRequirement1() << " and " << current->getTreasure()->getRequirement2() << " to open the chest and find the treasure!" << endl;
            cout << "Congratulations, you win!" << endl;
            gameover = true;
            break;
          }
          else
          {
            cout << "Wrong password." << endl;
            do
            {
              cout << "Do you want to try again?	(Y/N)";
              cin >> choice;
            } while (toupper(choice) != 'Y' && toupper(choice) != 'N');
          }
        }
        if (toupper(choice) == 'Y')
          break;
      }
      else
      {
        // Print a hint message
        cout << "You need something to open it..." << endl;
      }
    }

    // Prompt the user for input
    cout << "\nChoose actions: next, prev, pick, use, inv, quit" << endl;
    cout << "Enter your action\n$ ";
    //    getline(cin, input);
    cin >> input;
    // Convert the user's input to uppercase
    for (int i = 0; i < input.length(); i++)
    {
      input[i] = toupper(input[i]);
    }
    // Process the user's input
    if (input == "NEXT")
    {
      if (current->getRoomName() != "Secret Room 1" && current->getRoomName() != "Secret Room 2" &&
          current->getRoomName() != "Secret Room 3" && current->getRoomName() != "Final Secret Room")
      {
        // Move to the next room if possible
        if (current->getNext() != nullptr)
        {
          current = current->getNext();
        }
        else
        {
          cout << "There is no next room." << endl;
        }
      }
      else
      {
        if (current->getRoomName() != "Final Secret Room")
        {
          cout << "Answer the question on the card to get to the next room." << endl;
        }
        else
        {
          cout << "Ouch! You hit the wall." << endl;
        }
      }
    }
    else if (input == "GO")
    {
      // Move to the next secret room if possible
      if ((current->getRoomName() == "Secret Room 1" && inventory.existsNode("Keycard1")) ||
          (current->getRoomName() == "Secret Room 2" && inventory.existsNode("Keycard2")) ||
          (current->getRoomName() == "Secret Room 3" && inventory.existsNode("Keycard3")))
      {
        current = current->getNext();
      }
      else
      {
        cout << "Nothing happens..." << endl;
      }
    }
    else if (input == "PREV")
    {
      // Move to the previous room if possible
      if (current->getPrev() != nullptr)
      {
        current = current->getPrev();
      }
      else
      {
        cout << "Ouch! You hit the wall." << endl;
      }
    }
    else if (input == "OPEN_SESAME!")
    {
      // Move to the hidden room if possible
      if (current->getHidden() != nullptr)
      {
        if (inventory.existsNode("Secret Key"))
          current = current->getHidden();
        else
          cout << "You need something to get into hidden room." << endl;
      }
      else
      {
        cout << "Stop spitting gibberish!" << endl;
      }
    }
    else if (input == "PICK")
    {
      // Pick up the item in the current room if possible
      if (current->getItem() != nullptr)
      {
        InventoryNode *temp = nullptr;
        if (current->getItem()->getName() == "Bag")
        {
          hasBag = true;
          cout << "With a bag, you can hold more items." << endl;
          temp = inventory.getHead();
          current->resetItem();
          if (hand != nullptr)
          {
            inventory.insertNode(hand);
            hand = nullptr;
          }
        }
        else
        {
          if (hasBag)
          {
            cout << "You picked up the " << current->getItem()->getName() << "." << endl;
            inventory.insertNode(current->getItem());
            current->resetItem();
          }
          else
          {
            if (hand == nullptr)
            {
              cout << "You picked up the " << current->getItem()->getName() << "." << endl;
              hand = current->getItem();
              current->resetItem();
            }
            else
            {
              cout << "You already have something in your hand." << endl;
              cout << "To hold more items, you need a bag." << endl;
            }
          }
        }
      }
      else
      {
        cout << "There is nothing to pick up." << endl;
      }
    }
    else if (input == "USE")
    {
      // Use an item in the current room if possible
      string name;
      if (hasBag)
      {
        inventory.printList();
        cout << "Select item:\n$ ";
        cin.ignore();
        getline(cin, name);
      }
      else
      {
        if (hand != nullptr)
        {
          cout << "You have " << hand->getName() << " in your hand." << endl;
          cout << "Do you want to use it? (Y/N) ";
          char choice;
          cin >> choice;
          if (toupper(choice) == 'Y')
          {
            name = hand->getName();

          }
          else
          {
            continue;
          }
        }
        else
        {
          cout << "You have nothing in your hand." << endl;
          continue;
        }
      }

      if (inventory.existsNode(Title_Case(name)) || name == "0" || (hand != nullptr && hand->getName() == name))
      {
        for (int i = 0; i < name.length(); i++)
          {
            name[i] = toupper(name[i]);
          }

        if (name != "0")
          cout << "You used the " << name << "." << endl;

        // Check if the item is a riddle book
        if (name == "RIDDLE BOOK")
        {
          // Ask the user a riddle and check the answer
          string answer;
          cout << "The book says: \"I have keys, but no locks and space, but no rooms. You can enter, but can't go outside. What am I?\"" << endl;
          cout << "What is your answer? ";
          cin >> answer;
          for (int i = 0; i < answer.length(); i++)
          {
            answer[i] = toupper(answer[i]);
          }
          if (answer == "KEYBOARD")
          {
            // Print a congratulatory message and a hint
            cout << "That is correct!" << endl;
            cout << "The book also says: \"The first three code for the treasure is 123.\"" << endl;
          }
          else
          {
            // Print a wrong message and a hint
            cout << "That is wrong." << endl;
            cout << "The book also says: \"Think of something you use to type.\"" << endl;
          }
        }
        // Check if the item is a flashlight
        if (name == "FLASHLIGHT")
        {
          // Print a message and a hint
          cout << "The flashlight turns on for a few seconds, then dies." << endl;
          cout << "You see a faint star symbol on the wall." << endl;
        }
        // Check if the item is a map
        if (name == "MAP")
        {
          // Print a message and a hint
          cout << "The map shows the layout of the mansion and some markings." << endl;
          cout << "You see that there is a treasure in the Treasure Room." << endl;
        }
        // Check if the item is a knife
        if (name == "KNIFE")
        {
          // Print a message and a hint
          cout << "The knife has a sharp blade that can cut through anything." << endl;
          cout << "You wonder if it can be used to open something..." << endl;
        }
        // Check if the item is water
        if (name == "WATER")
        {
          // Print a message and a hint
          cout << "The water is refreshing and quenches your thirst." << endl;
          cout << "You feel more energized and alert." << endl;
          if (hasBag)
          {
            inventory.deleteNode(Title_Case(name));
          }
          else
          {
            hand = nullptr;
          }
        }
        if (name == "STAR KEY" || name == "STAR PUZZLE" || name == "SECRET KEY" || name == "KEYCARD1" || name == "KEYCARD2" || name == "KEYCARD3")
        {
          // Print a message and a hint
          cout << "These exquisite items radiate a captivating luminosity." << endl;
          cout << "You contemplate their potential to grant access to hidden realms." << endl;
        }
        if (name == "BOX")
        {
          // Print a message about the requirement and a hint
          if (inventory.existsNode("Knife"))
          {
            cout << "You use the Knife to open it!" << endl;
            cout << "The box is surprisingly lightweight and seems to be of high quality." << endl;
            cout << "You notice a small piece of paper with something written on it." << endl;
            inventory.insertNode(new Item("A paper with something written on it", "Paper"));
            inventory.deleteNode(Title_Case(name));
          }
          else
          {
            // Print a hint message
            cout << "You need something to open it..." << endl;
          }
        }
        if (name == "PAPER")
        {
          // Print a message and a hint
          if (inventory.existsNode("Flashlight"))
          {
            cout << "You use the Flashlight to see the word on the paper!" << endl;
            cout << "The last three code for the treasure is 888." << endl;
          }
          else
          {
            // Print a hint message
            cout << "You need something to see clearly..." << endl;
          }
        }
        if (name == "DIARY")
        {
          // Print a message and a hint
          cout << "As you open the dusty diary, you find faded handwritten pages." << endl;
          cout << "You read a page that mentions a hidden room behind a bookshelf in the library." << endl;
          cout << "It says that a special action and a special key are required to open the hidden door." << endl;
        }

        if (name == "TELESCOPE")
        {
          // Print a message and a hint
          cout << "You look through the telescope and see a constellation resembling a star." << endl;
          cout << "It might be a clue to the location of the star-shaped lock." << endl;
        }

        if (name == "SILVER CROSS")
        {
          // Print a message and a hint
          cout << "The silver cross feels cool to the touch and emits a faint glow." << endl;
          cout << "Open_Sesame! are written on it.";
          cout << "You wonder if it has any significance..." << endl;
        }

        if (name == "CARD1")
        {
          // Print a message and a hint
          cout << "\nTo enter the next secret room, you need to answer the question." << endl;
          cout << "Question 1: John's father has five sons named Alan, Blan, Clan and Dlan. What did he call his fifth son?" << endl;
          cout << "Hint: Name with only one word." << endl;
          cout << "What is the answer?\n$ ";
          string guess;
          cin >> guess;
          for (int i = 0; i < guess.length(); i++)
          {
            guess[i] = toupper(guess[i]);
          }
          if (guess == "JOHN")
          {
            // Move to the next secret room if correct answer entered
            cout << "Correct answer! ^O^" << endl;
            cout << "Answer: The name of the fifth son is John. \n"
                 << "The sentence states, 'John's father has five sons,' implying that John is one of the sons." << endl;
            cout << "Well done, intrepid explorers! You've proven your skills. \n"
                 << "But the journey is far from over. \n"
                 << "Prepare yourselves for what lies beyond this door." << endl;
            inventory.deleteNode("Card1");
            inventory.insertNode(new Item("a keycard with a number 1 in a circle", "Keycard1"));
            current = current->getNext();
          }
          else
          {
            cout << "Wrong answer!!!" << endl;
          }
        }
        if (name == "CARD2")
        {
          // Print a message and a hint
          cout << "\nTo enter the next secret room, you need to answer the question." << endl;
          cout << "Question 2: What is directly in the middle of Australia?" << endl;
          cout << "Hint: One letter only." << endl;
          cout << "What is the answer?\n$ ";
          string guess;
          cin >> guess;
          for (int i = 0; i < guess.length(); i++)
          {
            guess[i] = toupper(guess[i]);
          }
          if (guess == "R")
          {
            // Move to the next secret room if correct answer entered
            cout << "Correct answer! ^O^" << endl;
            cout << "Answer: The letter 'R' is the central letter in the word 'Australia'." << endl;
            cout << "Impressive... you have surpassed the second trial. \n"
                 << "But can you navigate the depths of the unknown that lie ahead? \n"
                 << "Enter, if you dare. ^_~ " << endl;
            inventory.deleteNode("Card2");
            inventory.insertNode(new Item("a keycard with a number 2 in a circle", "Keycard2"));
            current = current->getNext();
          }
          else
          {
            cout << "Wrong answer!!!" << endl;
          }
        }
        if (name == "CARD3")
        {
          // Print a message and a hint
          cout << "\nTo enter the next secret room, you need to answer the question." << endl;
          cout << "Question 3: On average, how many books can you put in an empty backpack?" << endl;
          cout << "Hint: One digit number only (0 - 9 / zero - nine). " << endl;
          cout << "What is the answer?\n$ ";
          string guess;
          cin >> guess;
          for (int i = 0; i < guess.length(); i++)
          {
            guess[i] = toupper(guess[i]);
          }
          if (guess == "ONE" || guess == "1")
          {
            // Move to the next secret room if correct answer entered
            cout << "Correct answer! ^O^" << endl;
            cout << "Answer: One. After that, it isn't empty." << endl;
            cout << "You've unlocked the secrets of the previous room, but there's more to discover. \n"
                 << "Step into the next chapter of this enigmatic puzzle and unlock the mysteries that await." << endl;
            inventory.deleteNode("Card3");
            inventory.insertNode(new Item("a keycard with a number 3 in a circle", "Keycard3"));
            current = current->getNext();
          }
          else
          {
            cout << "Wrong answer!!!" << endl;
          }
        }
        if (name == "0")
        {
          cout << "You cancel the 'use' action." << endl;
          continue;
        }
        // Delete the item from the inventory after use
        // inventory.deleteNode(name);
      }
      else
      {
        cout << "You don't have this item." << endl;
      }
    }
    else if (input == "INV")
    {
      if (hasBag)
      {
        inventory.printList();
      }
      else
      {
        if(hand != nullptr){
          cout << "You have " << hand->getName() << " in your hand." << endl;
        }else{
          cout << "You don't have a bag." << endl;
        }
      }
    }
    else if (input == "QUIT")
    {
      // Quit the game
      cout << "\nY = yes\nN = no\nB = back to game\n"
           << endl;
      cout << "Do you wish to have your game saved? (Y/N/B)\n$ ";
      char choice;
      cin >> choice;
      while (toupper(choice) != 'Y' && toupper(choice) != 'N' && toupper(choice) != 'B')
      {
        cout << "Invalid input. Please try again." << endl;
        cin >> choice;
      }
      if (toupper(choice) == 'Y')
      {
        cout << "\nWhich slot do you wish to save to? (1/2/3 or B)\n$ ";
        char slot;
        cin >> slot;
        while (slot != '1' && slot != '2' && slot != '3' && toupper(slot) != 'B')
        {
          cout << "\nInvalid slot. Please try again.\n$ ";
          cin.ignore();
          cin >> slot;
        }
        if (toupper(slot) == 'B')
        {
          cout << "\nYou continue your adventure." << endl;
          continue;
        }
        if (!isFileEmpty("save" + to_string(static_cast<int>(slot - '0')) + ".txt"))
        {
          cout << "Are you sure you want to overwrite the previous save? (Y/N)" << endl;
          char choice;
          cin >> choice;
          while (toupper(choice) != 'Y' && toupper(choice) != 'N')
          {

            cout << "Invalid input. Please try again." << endl;
            cin.ignore();
            cin >> choice;
          }
          cout << "Your progress is saved to slot " << slot << endl;
          saveGame(static_cast<int>(slot - '0'), rooms, current, inventory, hand, hasBag);
        }
        else
        {
          cout << "Your progress is saved to slot " << slot << endl;
          saveGame(static_cast<int>(slot - '0'), rooms, current, inventory, hand, hasBag);
        }
        cout << "Your game has been saved." << endl;
        gameover = true;
      }
      else if (toupper(choice) == 'N')
      {
        cout << "You quit the game." << endl;
        gameover = true;
      }
      else
      {
        cout << "\nYou continue your adventure." << endl;
      }
    }
    else
    {
      // Invalid acton
      cout << "There is no such action." << endl;
    }
  }
}

// Define a function to set up the game
void Game(int choice = 0)
{
  // Create a linked list of rooms
  RoomList rooms;

  // Insert items and treasures into the rooms
  rooms.insertNode(
      "Entrance",
      "You stand at the entrance of a mysterious castle. The heavy wooden door creaks as you push it open.",
      nullptr,
      nullptr);

  rooms.insertNode(
      "Lobby",
      "You find yourself in the grand lobby of an old haunted mansion. \n"
      "The flickering chandelier casts eerie shadows on the walls.\n"
      "In the corner, you notice a sturdy canvas bag with ample space.",
      new Item("a sturdy canvas bag with ample space", "Bag"),
      nullptr);

  rooms.insertNode(
      "Dining Room",
      "You step into a grand dining room, once filled with lively conversation. \n"
      "The table is covered in a thick layer of dust, but a bottle of water catches your eye.",
      new Item("a bottle of water", "Water"),
      nullptr);

  rooms.insertNode(
      "Kitchen",
      "You find yourself in a spacious kitchen, the air filled with the aroma of long-forgotten recipes. \n"
      "Among the utensils, you spot a knife with a sharp blade.",
      new Item("a knife with a sharp blade", "Knife"),
      nullptr);

  rooms.insertNode(
      "Ballroom",
      "You enter a magnificent ballroom with faded grandeur. \n"
      "Moonlight filters through the stained glass windows, illuminating an open book on a pedestal. \n"
      "It appears to be a map with some markings.",
      new Item("a map with some markings", "Map"),
      nullptr);

  rooms.insertNode(
      "Library",
      "You enter a dimly lit library, filled with rows of ancient books. \n"
      "As you browse through the shelves, you notice a book with a riddle.",
      new Item("a book with a riddle", "Riddle Book"),
      nullptr);

  rooms.insertNode(
      "Attic",
      "You climb up a creaky staircase, reaching the attic. The room is filled with old trunks and forgotten memories. \n"
      "Among the scattered items, you find a dusty diary.",
      new Item("a dusty diary", "Diary"),
      nullptr);

  rooms.insertNode(
      "Tower",
      "You arrive at the top of the tower. The wind howls, and you can see the vast expanse of the surrounding landscape. \n"
      "In the corner, there is a telescope with crystal-clear lenses.",
      new Item("a telescope with crystal-clear lenses", "Telescope"),
      nullptr);

  rooms.insertNode(
      "Garden",
      "You find yourself in a serene garden, vibrant with colorful flowers and the soothing sound of a trickling fountain. \n"
      "Among the blossoms, you spot a box with a complex knot.",
      new Item("a box with a complex knot", "Box"),
      nullptr);

  rooms.insertNode(
      "Crypt",
      "You find yourself in a dimly lit crypt, the air heavy with a musty scent. Among the ancient tombstones, you spot a silver cross."
      "On the silver cross, there are some words.",
      new Item("a silver cross", "Silver Cross"),
      nullptr);

  rooms.insertNode(
      "Cellar",
      "You step into a gloomy cellar, filled with dusty barrels and cobwebs. \n"
      "On a dusty table, you spot an old and small key.",
      new Item("a small key", "Secret Key"),
      nullptr);

  rooms.insertNode(
      "Study",
      "You enter a mysterious study, with bookshelves stacked high with leather-bound tomes. \n"
      "A crackling fireplace warms the room. As you approach the desk, you see a puzzle piece with a star shape.",
      new Item("a puzzle piece with a star shape", "Star Puzzle"),
      nullptr);

  rooms.insertNode(
      "Treasure Room",
      "You discover a hidden treasure room, glittering with precious jewels and golden artifacts. \n"
      "Among the riches, you spot an old, worn-out flashlight with low battery.",
      new Item("a flashlight with low battery", "Flashlight"),
      new Treasure("You found the treasure chest! But it's locked with a star-shaped lock...", "Star Key", "Star Puzzle", 123888));

  // Insert hidden rooms
  rooms.insertHidden(
      "Final Secret Room",
      "You enter the last secret room, shrouded in darkness. \n"
      "As your eyes adjust, you notice a key with a star symbol on a dusty shelf. \n"
      "It seems to be the key to a hidden treasure chest.",
      new Item("a key with a star symbol", "Star Key"),
      nullptr,
      "Library");

  rooms.insertHidden(
      "Secret Room 3",
      "You enter a hidden secret room, you notice another card on a dusty table. It seems to be the clue to the next secret room.",
      new Item("a card with a question", "Card3"),
      nullptr,
      "Library");
  rooms.insertHidden(
      "Secret Room 2",
      "You enter a hidden secret room, you notice a card on a dusty table again. It seems to be the clue to the next secret room.",
      new Item("a card with a question", "Card2"),
      nullptr,
      "Library");
  rooms.insertHidden(
      "Secret Room 1",
      "You enter a hidden secret room, you notice a card on a dusty table. It seems to be the clue to the next secret room.",
      new Item("a card with a question", "Card1"),
      nullptr,
      "Library");

  // Create a pointer to the current room
  RoomNode *current = rooms.getHead();
  // Create a variable to store the user's input
  string input;
  // Create a variable to store the user's item
  InventoryList inventory;
  // Create a variable to store the game status
  bool gameover = false;
  // Create a variable to store the an item if bag is not picked up
  Item *hand = nullptr;
  // Create a variable to store bag status
  bool hasBag = false;

  // Print the welcome message
  cout << "Welcome to the treasure hunt game!" << endl;
  cout << "You are in a dark mansion with many rooms." << endl;
  cout << "Goal : Find the treasure hidden in one of the rooms." << endl;
  cout << endl;
  cout << "Commands: Actions " << endl;
  cout << "'next'  : move to previous room" << endl;
  cout << "'prev'  : move to next room" << endl;
  cout << "'pick'  : pick up an item in a room" << endl;
  cout << "'use'   : use an item in a room" << endl;
  cout << "'inv'   : check your inventory" << endl;
  cout << "'quit'  : quit the game" << endl;
  cout << endl;
  cout << "Good luck!" << endl;

  if (choice)
  {
    // Load the game
    loadGame(choice, rooms, current, inventory, hand, hasBag);
  }

  // Start the game
  gameloop(input, gameover, rooms, current, inventory, hand, hasBag);
}