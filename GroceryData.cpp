/*
 * File name:   GroceryData.cpp
 * Developer:   Ryan Vold
 * Date:        December 13, 2024
 * Purpose:     Defines the GroceryData class implementation to
                read, quantify, manipulate, and backup data for
                the Corner Grocer app.
*/

#include "GroceryData.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
using namespace std;

void GroceryData::readFile(string groceryFileName) {
    ifstream groceryFile;   // Create input filestream
    string currItem;            // Current item
    groceryFile.open(groceryFileName);   // Open file
    
    if (!groceryFile.is_open()) {
        cout << "Error opening grocery file." << endl;
        return;
    }

    while (groceryFile >> currItem) {
        groceryItems[currItem]++;
    }
    
    if (!groceryFile.eof()) {
        cout << "Error occurred before reaching end of file.";
    }

    // Close file
    groceryFile.close();
}

int GroceryData::getGroceryItemCount(string groceryItem) {
    return groceryItems[groceryItem];
}

map<string, int>GroceryData::getGroceryMap() {
    return groceryItems;
}

void GroceryData::archiveData() {
    ofstream archive;               // Output file stream
    int colWidth = 0;               // Will store max column width
    archive.open("frequency.dat");  // Open file
    if (!archive.is_open()) {       // Handle opening errors
        cout << "Error opening frequency.dat." << endl;
        return;
    }
    for (const auto& item : groceryItems) {
        if (item.first.size() > colWidth) {
            colWidth = item.first.size();
        }
    }
    for (const auto& item : groceryItems) {
        archive << setw(colWidth) << item.first << ": " << item.second << endl;
    }
}