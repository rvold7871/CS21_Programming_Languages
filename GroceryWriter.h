#ifndef GROCERYWRITER_H
#define GROCERYWRITER_H
#include "GroceryData.h"

/*
 * File name:    GroceryWriter.h
 * Developer:    Ryan Vold
 * Date:         December 13, 2024
 * Purpose:      Declares the GroceryData class that serves as the main
				 interaction point and driver of the application. This
				 class is responsible for displaying data provided by
				 the GroceryData class and driving the program as a
				 whole.
*/

class GroceryWriter {
public:
	// Display user menu
	void displayMenu();

	// Get user selection
	int getUserChoice();
	
	// Display quanitty of searched item
	void writeItemQuantity();

	// Write items and their corresponding quantities
	void writeInventory();

	// Write items and their corresponding quantities via histogram
	void writeHisto();

	// Main runner
	void runProgram();

private:
	GroceryData groceries;
};

#endif