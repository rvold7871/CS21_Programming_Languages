#include <iostream>
#include "GroceryData.h"
#include "GroceryWriter.h"

/*
 * File name:    Main.cpp
 * Developer:    Ryan Vold
 * Date:         December 13, 2024
 * Purpose:      Creates the GroceryWriter object and calls its runProgram
				 function which drives the entire program
*/

using namespace std;

int main() {
	// Create groceryWriter object to run and control program
	GroceryWriter groceryWriter;
	groceryWriter.runProgram();

	return 0;
}