#include <iostream>
#include <fstream>
#include <string>
#include "functions.cpp"
using namespace std;


// Define a main function

int main()
{
  ifstream saveFile1("save1.txt", ios::in | ios::out);
  ifstream saveFile2("save2.txt", ios::in | ios::out);
  ifstream saveFile3("save3.txt", ios::in | ios::out);

  if (saveFile1 || saveFile2 || saveFile3)
  {

    int choice;
    cout << "There are save file(s) in the memory." << endl;
    cout << "Do you want to load the save file(s)?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter your choice (1-2)\n$ ";
    cin >> choice;
    cin.ignore();

    while (choice != 1 && choice != 2)
    {
      cout << "Invalid choice. Please enter again.\n$ ";
      cin.ignore();
      cin >> choice;
    }

    if (choice == 1)
    {
      cout << "\nWhich game progress do you want to pick?" << endl;
      cout << "1. Game Progress 1" << endl;
      cout << "2. Game Progress 2" << endl;
      cout << "3. Game Progress 3" << endl;

      int choice;
      cout << "Enter your choice (1-3).\n$ ";
      cin >> choice;
      cin.ignore();

      while (choice != 1 && choice != 2 && choice != 3)
      {
        cout << "Invalid choice. Please enter again.\n$ ";
        cin >> choice;
        cin.ignore();
      }

      if (choice == 1)
      {
        if (saveFile1)
        {
          cout << "Loading Game Progress 1..." << endl;
          Game(choice);
        }
        else
        {
          cout << "There is no save file in this slot." << endl;
        }
      }
      else if (choice == 2)
      {
        if (saveFile2)
        {
          cout << "Loading Game Progress 2..." << endl;
          Game(choice);
        }
        else
        {
          cout << "There is no save file in this slot." << endl;
        }
      }
      else if (choice == 3)
      {
        if (saveFile3)
        {
          cout << "Loading Game Progress 3..." << endl;
          Game(choice);
        }
        else
        {
          cout << "There is no save file in this slot." << endl;
        }
      }
    }
    else if (choice == 2)
    {
      cout << "Starting a new game..." << endl;
      Game();
    }
  }
  else
  {
    Game();
  }

  // system("cls");
  return 0;
}