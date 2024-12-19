#ifndef GROCERYDATA_H
#define GROCERYDATA_H
#include <string>
#include <map>

/*
 * File name:    GroceryData.h
 * Developer:    Ryan Vold
 * Date:         December 13, 2024
 * Purpose:      Declares the GroceryData class to keep track of
				 grocery items and their quantities for Corner Grocer.
*/
using namespace std;

class GroceryData {
public:
	// Read the data file
	void readFile(string groceryFileName);

	// Count how many of an item
	int getGroceryItemCount(string item);

	map<string, int> getGroceryMap();

	// Writes to backup file
	void archiveData();

private:
	// Used to store key-value pairs of items and quantities
	map<string, int> groceryItems;
};

#endif