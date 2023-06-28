# Whispers of the Forgotten Castle 
![Game Map](pictures/main%20pic.png)
This picture shows the entire game map.

<br>

## Team Members (Group 7)
|No.|Name|Matrics ID|
|:-:|-|-|
|1|KOAY CHUN KEAT|164592|
|2|KHOO KAA HONG|164562|
|3|LOO CHI HAO|163703|

### [Link to the game demo video](https://www.google.com/)

<br><br>
<details>
<summary style = "font-size: 20px; font-weight: bold; cursor: pointer;">Description of the game</summary>

---
This is a treasure hunt game where you explore a dark mansion with many rooms. Your goal is to find the treasure hidden in the treasure room. You can move between rooms such as the lobby, the dining room, the kitchen, the ballroom, the library, the attic, the tower, the garden, the crypt, the cellar, and the study. You can also discover hidden rooms such as the secret room and the final secret room. You can pick up items such as a bag, a water bottle, a knife, a map, a riddle book, a diary, a telescope, a box, a silver cross, a secret key, a star puzzle, and a star key. You can use items to solve riddles, unlock hidden rooms, or open the treasure chest. The objective of the game is to obtain the star key and the star puzzle and enter the correct password to unlock the treasure chest and win the game.
</details>

<br><br>

<details>
<summary style = "font-size: 20px; font-weight: bold; cursor: pointer;">Features of the game</summary>

---
### 1) Move between rooms, pick up items, use items, and check your inventory

- The user can move between rooms using the commands next and prev. The current room pointer will point to the next or previous node in the room list, respectively. The user can also move to a hidden room using a special action and a special key, if available. The hidden room pointer will point to a node that is not part of the main room list.
- The user can pick up items using the command pick. The item pointer in the current room node will be set to null, and the item object will be inserted into the inventory list or the item in hand variable, depending on the bag status. The user can only pick up one item at a time without a bag.
- The user can use items using the command use. The user can select an item from their inventory list or their item in hand variable, and use it in the current room. The item object may have different effects depending on its name and the room's name, item, or treasure. For example, some items can help solve riddles, unlock hidden rooms, or open the treasure chest. Some items may also be deleted from the inventory list or the item in hand variable after use.
- The user can check their inventory using the command inv. The inventory list will print all the items that are stored in it. The user can also see what item they have in their hand, if any.

### 2) Solve riddles, unlock hidden rooms, and unlock the treasure chest with the necessary items

- The user can solve riddles using some items that contain clues or questions. For example, the riddle book contains a riddle that can be answered by typing the correct word. The card1, card2, and card3 contain questions that can be answered by typing the correct number. Solving riddles may reveal hints or passwords for the treasure chest or hidden rooms.
- The user can unlock hidden rooms using some items that act as keys or triggers. For example, the secret key can open a hidden door behind a bookshelf in the library. The star key can open a star-shaped lock in the treasure room. The keycard1, keycard2, and keycard3 can open doors to secret rooms that contain more clues and challenges.
- The user can unlock the treasure chest using two items that are required to open it: the star key and the star puzzle. The user also needs to enter a six-digit password that can be obtained by solving riddles or finding clues. Unlocking the treasure chest will end the game with a winning message.

### 3) Save and load your game progress using three slots

- The user can save their game progress using the command quit. The user will be asked if they want to save their game and which slot they want to save to. There are three slots available: 1, 2, and 3. The program will use file operations to write the game state to a text file named save1.txt, save2.txt, or save3.txt, respectively. The game state includes information such as hasBag status, item in room status, current room name, etc.
- The user can load their game progress from an existing save file at the start of the program. The program will check for existing save files and ask the user if they want to load them or start a new game. If the user chooses to load a saved game, they will be asked which slot they want to load from. The program will use file operations to read the game state from a text file named save1.txt, save2.txt, or save3.txt, respectively. The program will then set up the game according to the saved game state.
</details>

<br><br>

<details>
<summary style = "font-size: 20px; font-weight: bold; cursor: pointer;">How to play the game</summary>

---
First of all, there is a welcome message that shows that the game has started and the player is born in front of an entrance with nothing. Next, the player needs to enter their next action to start their exploration. After the entrance, each room will provide a new item for the player to help them know more about their location and how to proceed. At the same time, the player can make a `pick` action which can let the player get the item in hand first. However, when the player picks the item named Bag, an inventory system is activated for the player which allows them to hold a lot of items at the same time. Next, with the item in the player’s hand or the items in the Bag, the player can start to use the item they picked. After the player enters the `use` action, they are asked to enter the item name they want to use. However, the player can also enter a “0” to cancel the `use` action. After picking up a few items, the player can do an `inv` action to view all the items in the Bag. When the player wants to rest for a while or exit the game, they can input the `quit` action. At the moment the `quit` action is operating, the game system will ask whether the player wants to save their progress or not. Once the player saves the game progress, they will be able to load the game with the previous state. Let me tell you a secret: there is a hidden room among the rooms. With a special action, `Open_Sesame!`, the player will be allowed to enter the secret room with some requirements to open it. In the secret room, there are some questions to test the player. After the player finishes the test, they will automatically move to another secret room. Once they complete all the questions, they are free to move between the secret rooms. The game is very interesting and fun. Therefore, let us give it a try.
</details>

<br><br>

<details>
<summary style = "font-size: 20px; font-weight: bold; cursor: pointer;">Object-oriented concepts</summary>

---
The program uses several object-oriented concepts, such as classes, objects/composition, inheritance, polymorphism, and encapsulation. The program defines four classes: Room, Item, Treasure, and Node. Each class has its own attributes and methods that define its behavior and state. The program also creates objects from these classes and manipulates them using pointers and functions.

### Classes

- Room: This class represents a room in the mansion. It has attributes such as name, description, item, treasure, and hidden room. It also has methods to get and set these attributes, as well as to print the room information.

- Item: This class represents an item that can be found or used in the game. It has attributes such as clue and name. It also has methods to get and set these attributes, as well as to print the item information.

- Treasure: This class represents a treasure that can be unlocked in the game. It inherits from the Item class and adds new attributes such as requirement1, requirement2, password, and message. It also has methods to get and set these attributes, as well as to print the treasure information.

- Node: This class represents a node in a linked list. It has attributes such as item, room, next, and prev. It also has methods to get and set these attributes.

## Objects/Composition

The program creates objects from these classes using constructors and assignment operators. For example:

- Room *entrance = new Room("Entrance", "You stand at the entrance of a mysterious castle...");
- Item *bag = new Item("a sturdy canvas bag with ample space", "Bag");
- Treasure *treasure = new Treasure("You found the treasure chest...", "Star Key", "Star Puzzle", 123888);
- Node *node1 = new Node(entrance);
- Node *node2 = new Node(bag);

The program also manipulates these objects using pointers and functions. For example:

- current->getItem()->getName();
- inventory.insertNode(bag);
- rooms.insertHidden(treasure);
- node1->setNext(node2);

## Inheritance

The program uses inheritance to create a subclass from a superclass. For example:

- The Treasure class inherits from the Item class and adds new attributes and methods.
- The Treasure class can access the public and protected members of the Item class.
- The Treasure class can override the methods of the Item class to provide different functionality.

## Polymorphism

The program uses polymorphism to allow different types of objects to be treated in a similar way. For example:

- The Room class has a pointer to an Item object that can point to either an Item object or a Treasure object.
- The Room class can call the methods of the Item object without knowing its actual type at compile time.
- The Room class can use dynamic binding to invoke the correct method of the Item object at run time.

## Encapsulation

The program uses encapsulation to hide the implementation details of the classes from the outside world. For example:

- The Room class has private attributes such as name, description, item, treasure, and hidden room that can only be accessed by the methods of the class.
- The Room class has public methods such as getName(), getDescription(), getItem(), getTreasure(), getHidden(), setName(), setDescription(), setItem(), setTreasure(), setHidden(), and printRoom() that provide an interface for other classes or functions to interact with the Room object.
- The Room class does not expose its internal data structures or algorithms to other classes or functions.
- Similarly, the Item, Treasure, and Node classes also use encapsulation to protect their private attributes and provide public methods for accessing and modifying them.
- Encapsulation helps to achieve modularity, reusability, and maintainability of the code. It also prevents unwanted or accidental changes to the data or behavior of the objects.
- Encapsulation also allows the classes to change their implementation details without affecting the rest of the program, as long as the public interface remains consistent. This improves the flexibility and adaptability of the code.
</details>
<br><br>

<details>
<summary style = "font-size: 20px; font-weight: bold; cursor: pointer;">Linked List Implementation</summary>

---
The program uses two types of linked lists: a doubly linked list for the rooms and a singly linked list for the inventory. Each node in the room list contains a pointer to a room object, which has attributes such as name, description, item, treasure, and hidden room. Each node in the inventory list contains a pointer to an item object, which has attributes such as clue and name. The program also uses pointers to keep track of the current room and the item in hand.

### Room List

The room list is a doubly linked list that allows traversal in both directions. The list has a head and a tail pointer, and each node has a next and a prev pointer. The list also has methods to insert nodes at the end of the list or at a specific position based on the hidden room attribute. The list also has methods to delete nodes, reset items, check if a node exists, print the list, and get the head pointer.

### Inventory List

The inventory list is a singly linked list that allows traversal in one direction. The list has a head and a tail pointer, and each node has a next pointer. The list also has methods to insert nodes at the end of the list, delete nodes by item name, check if a node exists by item name, print the list, and get the head pointer.
</details>
<br><br>

<details>
<summary style = "font-size: 20px; font-weight: bold; cursor: pointer;">Screenshots of the game</summary>

---
pictures

</details>
<br><br>



<br><br>

# gameplay video (youtube link)
- video must match actual user experience
- highlight incomplete features if any

- feature of the game
- how to play
- how it works
- Game Flow