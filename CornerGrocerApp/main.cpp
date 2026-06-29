/*
 * Name: Esteban Garcia
 * Project: CS 210 Project Three - Corner Grocer
 * Description: This program reads grocery purchase records, counts item
 * frequencies, creates frequency.dat, and gives the user a menu to view results.
 */

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#include "CornerGrocer.h"

using namespace std;

void printMenu() {
  cout << endl;
  cout << "********************************" << endl;
  cout << "* Corner Grocer Tracking Menu  *" << endl;
  cout << "********************************" << endl;
  cout << "* 1. Search item frequency     *" << endl;
  cout << "* 2. Print frequency list      *" << endl;
  cout << "* 3. Print frequency histogram *" << endl;
  cout << "* 4. Exit                      *" << endl;
  cout << "********************************" << endl;
  cout << "Enter your choice: ";
}

int getMenuChoice() {
  int menuChoice = 0;

  while (true) {
    printMenu();

    if (cin >> menuChoice && menuChoice >= 1 && menuChoice <= 4) {
      return menuChoice;
    }

    // Clear bad input so the program does not get stuck in the menu loop.
    cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

void searchForItem(const CornerGrocer& t_cornerGrocer) {
  string itemName;

  cout << endl;
  cout << "Enter the item name to search for: ";
  cin >> itemName;

  cout << itemName << " was purchased "
       << t_cornerGrocer.getItemFrequency(itemName) << " time(s)." << endl;
}

void runProgram(CornerGrocer& t_cornerGrocer) {
  int menuChoice = 0;

  do {
    menuChoice = getMenuChoice();

    switch (menuChoice) {
      case 1:
        searchForItem(t_cornerGrocer);
        break;
      case 2:
        t_cornerGrocer.printFrequencyList();
        break;
      case 3:
        t_cornerGrocer.printHistogram();
        break;
      case 4:
        cout << "Exiting Corner Grocer tracking program." << endl;
        break;
      default:
        // This should not run because getMenuChoice validates the input first.
        cout << "Unexpected menu option." << endl;
        break;
    }
  } while (menuChoice != 4);
}

int main() {
  try {
    CornerGrocer cornerGrocer("CS210_Project_Three_Input_File.txt");

    cornerGrocer.loadItems();
    cornerGrocer.createBackupFile("frequency.dat");
    runProgram(cornerGrocer);
  } catch (const exception& e) {
    cerr << "Program error: " << e.what() << endl;
    return 1;
  }

  return 0;
}
