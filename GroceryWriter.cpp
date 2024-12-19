#include "GroceryWriter.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

/*
 * File name:    GroceryWriter.cpp
 * Developer:    Ryan Vold
 * Date:         December 13, 2024
 * Purpose:      Defines the GroceryData class that serves as the main
				 interaction point and driver of the application. This
				 class is responsible for displaying data provided by
				 the GroceryData class and driving the program as a
				 whole.
*/

using namespace std;

// Generates a n length string of character c
string nCharString(size_t n, char c) {
	string charString = "";
	for (int i = 0; i < n; i++) {
		charString += c;
	}
	return charString;
}

// Used to ignore bad input and reprompt
void clearCin(string prompt) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << prompt;
}

void GroceryWriter::displayMenu() {
	// Header title
	cout << nCharString(41, '*') << endl;
	cout << nCharString(8, '*') << " Corner Grocer Main Menu " << nCharString(8, '*') << endl;
	cout << nCharString(41, '*') << endl;
	cout << endl;

	// List options
	cout << "1. Count Item Quantity" << endl;
	cout << "2. Print Items and Quantities" << endl;
	cout << "3. Print Items / Quantities Histogram" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
}

// Gets user selection 1 - 4
int GroceryWriter::getUserChoice() {
	cout << "Enter menu option 1 - 4: " << endl;
	int userChoice;
	bool invalidInput = true;	// Switch to flip when valid input is received

	while (invalidInput) {		// While input is still invalid, keep prompting
		if (!(cin >> userChoice)) {
			clearCin("Enter menu option 1 - 4: ");
		}
		else {
			if ((userChoice > 0) && (userChoice < 5)) {	// User choice must be 1 - 4
				invalidInput = false;					// Valid input
			}
			else {
				clearCin("Enter menu option 1 - 4: ");	// Clears cin and reprompts
			}
		}
	}
	return userChoice;
}

// Prompts the user for an item and returns its quantity
void GroceryWriter::writeItemQuantity() {
	string item;
	int quantity;

	cout << "Enter an item to search: " << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Clear buffer to avoid weird output
	getline(cin, item);

	if (!item.empty()) {	// If item is populated
		quantity = groceries.getGroceryItemCount(item);	// Retrieve count of item
	}
	else {
		quantity = 0;	// Otherwise, quantity is 0
	}

	cout << item << ": " << quantity << endl;
	cout << endl;
	system("pause");	// Wait for user...
	cout << endl;
	cout << endl;
}

void GroceryWriter::writeInventory() {
	// Get GroceryData map
	map<string, int>groceryList = groceries.getGroceryMap();

	// Find longest item in the list for item "column" width
	int colWidth = 0;
	for (const auto& item : groceryList) {
		if (item.first.size() > colWidth) {
			colWidth = item.first.size();
		}
	}
	
	// For each item in the list, print item: quantity
	for (const auto& item : groceryList) {
		cout << setw(colWidth) << item.first << ": " << item.second << endl;
	}
	system("pause");	// Wait for user...
	cout << endl;
	cout << endl;
}

void GroceryWriter::writeHisto() {
	// Get GroceryData map
	map<string, int>groceryList = groceries.getGroceryMap();

	// Find longest item in the list for item "column" width
	int colWidth = 0;
	for (const auto& item : groceryList) {
		if (item.first.size() > colWidth) {
			colWidth = item.first.size();
		}
	}

	// For each item, print a histogram representing quantity
	// Ex. item: ****
	for (const auto& item : groceryList) {
		cout << setw(colWidth) << item.first << ": " << nCharString(item.second, '*') << endl;
	}
	system("pause");	// Wait for user...
	cout << endl;
	cout << endl;
}

void GroceryWriter::runProgram() {
	// Ingest data file
	groceries.readFile("CS210_Project_Three_Input_File.txt");
	
	// Archive today's data
	groceries.archiveData();
	
	// While running remains true...
	bool running = true;
	while (running) {
		
		displayMenu(); // Present options

		// Get user choice
		int choice;
		choice = getUserChoice();

		switch (choice) {
			case 1:
				writeItemQuantity();
				break;
			case 2:
				writeInventory();
				break;
			case 3:
				writeHisto();
				break;
			case 4:
				running = false;
				break;
		}
	}
}