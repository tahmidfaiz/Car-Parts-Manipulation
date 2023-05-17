//==========================================================
//
// Title:      Project-2 Part Pretenders
// Course:     CSC 1100
// Author:     Tahmid Faiz
// Date:       27 April 2021
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

//==========================================================
// Globals
//==========================================================
const int ARRAY_SIZE = 100;
const string INPUT_FILE_NAME = "CarParts.txt";
const int COLM = 20;
//==========================================================

//==========================================================
// addPart
//==========================================================
void addPart(string parts[], int &partCount)
{

  // Declare variables
  string part;

  // Test whether room to add part
  if (partCount == ARRAY_SIZE)
    cout << "No room to add part at this time." << endl;
  else
  {

    // Prompt for and get part
    cout << "Enter the part to add: ";
    cin >> part;

    // Add part
    parts[partCount] = part;
    partCount = partCount + 1;
    cout << "Part '" << part << "' added to list."
      << endl;

  }
    // Declare variables
    string value;
    int spot;

    // Loop to test each value
    for (int i = 1; i < partCount; i++)
    {
      // Loop to find spot to place value
      value = parts[i];
      spot = i - 1;
      while (spot >= 0 && parts[spot] > value)
      {
        parts[spot + 1] = parts[spot];
        spot = spot - 1;
      }

      // Place value in spot
      parts[spot + 1] = value;

    }

    // Print sorted message
    cout << endl << "Parts sorted." << endl;

}

//==========================================================
// binarySearchParts
//==========================================================
int binarySearchParts(
  string parts[], int arraySize, string key)
{

  // Declare variables
  int min = 0;
  int index;
  int max = arraySize - 1;

  // Loop to find key
  while (min <= max)
  {

    // Get midpoint of array
    index = (min + max) / 2;

    // Test if key found
    if (parts[index] == key)  // Guess is right on
      return index;
    else if (parts[index] < key)  // Guess is too low
      min = index + 1;
    else
      max = index - 1;

  }

  // Return index
  return -1;

}

//==========================================================
// deletePart
//==========================================================
void deletePart(string parts[], int &partCount)
{
    //Set variable
    int index;
    //Ask user for which part they wish to delete
    cout << "Enter index of part to delete: ";
    cin >> index;
  // Test whether there is space to add part
  if (index < 0 or index > partCount)
    cout << "Error: invalid index of " << index << endl;
  else
  {
    // Delete part
      for (int i = index; i < partCount - 1; i++){
      parts[i] = parts[i + 1];
      }
    //Prints deleted message
     
    cout << "Part at index '" << index
      << "' deleted from list." << endl;
    partCount = partCount - 1;

  }

}

//==========================================================
// listParts
//==========================================================
void listParts(string parts[], int arraySize)
{
 // Prints the "Index" and "Parts" headers
    cout << endl;
    cout << left << setw(COLM) << "Index" <<  left << setw(COLM) << "Parts" << endl;
    // Loop to list parts and uses "setw" and "left" to allign the text.
    for (int i = 0; i < arraySize; i++){
    cout << left << setw(COLM) << i  << left << setw(COLM) << parts[i] << endl;
    }
    //Prints the total part counted including index 0.
    cout << "Part Count " << arraySize << endl;
}

//==========================================================
// menuOption
//==========================================================
int menuOption()
{

  // Declare variables
  int option;

  // Show menu and get option
  cout << "\nPart Pretenders Menu" << endl;
  cout << "1 - List car parts" << endl;
  cout << "2 - Search car parts" << endl;
  cout << "3 - Add car part" << endl;
  cout << "4 - Delete car part" << endl;
  cout << "9 - Exit" << endl;
  cout << "\nEnter an option: ";
//Reads user answer for the menu option.
  cin >> option;
  return option;

}
//==========================================================
// readParts
//==========================================================
int readParts(string parts[])
{
    //declare variable
    string line;
    int lineCount = 0;
    //Calls text file and opens
    ifstream inFile;
    inFile.open(INPUT_FILE_NAME);
    //Checks if txt files opens
    if (!inFile.is_open()){
    return -1;
    }
    else{
    //If file open then reads the txt file using getline function
            while (inFile.good()) {
                getline(inFile, line);
                parts[lineCount] = line;
                lineCount = lineCount + 1;
            }
    
        return lineCount;
}
    inFile.close();
}

//==========================================================
// searchParts
//==========================================================
void searchParts(string parts[], int arraySize)
{

  // Declare variables
  string key;
  int index;

//Asks user to select which part you want search
  cout << "\nEnter a part to search for (no spaces): ";
  cin >> key;
//call binarySearch function to search key.
  index = binarySearchParts(parts, arraySize, key);
  if (index != -1)
    cout << "'" << key << "' found at index "
    << index << "." << endl;
  else
    cout << "'" << key << "' NOT found." << endl;

}



//==========================================================
// main
//==========================================================
int main()
{

  // Declare variables
  string carParts[ARRAY_SIZE];
  int partCount=0;
  int option;
    //Calls function to store carParts
    readParts(carParts);
   

  // Show application header
  cout << "Welcome to Part Pretenders" << endl;
  cout << "--------------------------" << endl << endl;
    cout << "Reading lines from file " << INPUT_FILE_NAME << endl;
    
   //partCount reads the return value from the readParts function
    partCount = readParts(carParts);
    cout << partCount << "line(s) read from file " << INPUT_FILE_NAME << endl;

  // Loop to process options
  option = menuOption();
  while (option != 9)
  {

    // Handle option
    switch (option)
    {

      // List parts
    case 1:
      listParts(carParts, partCount);
      break;

      // Search parts
    case 2:
      searchParts(carParts, partCount);
      break;

      // Add part
    case 3:
      addPart(carParts, partCount);
      break;

      // Delete part
    case 4:
      deletePart(carParts, partCount);
      break;

      // Handle invalid option
    default:
      cout << endl << "Error: unknown option of '" << option
        << "'." << endl;

    }

    // Get next option
    option = menuOption();

  }

  // Show application close
  cout << "\nEnd of Part Pretenders" << endl;

}


