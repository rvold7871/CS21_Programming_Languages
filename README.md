# CS21_Programming_Languages
## Project Summary
This project involved creating a program that ingests a data file that simulates the daily items sold by a grocery store and allows a user to report on the data by means of a text-based interface. The program currently has four main functions:
1. Search for an individual item and return its quantity for that day
2. Display all items purchased and their quantities in a basic two-column table
3. Display all items purchased and their quantities as a histogram, with each "*" representing one quantity
4. Archive the data ingested in the file into a file called frequency.dat

## What Went Well
One of the basic principles of good programming is writing reusable code that can be plugged into different places and perform a specific task. I believe I was able to create methods and functions that fit together well to make the main function very basic. I believe that, by breaking the prompt down into smaller chunks, I was able to build them and then fit them all together toward the end of the project. I also think I built effective input validation to ensure good values are received and processed.

## Enhancements
If given the time, I would ensure adequate error handling was in place, since input validation can only go so far in allowing a program to run regardless of the input. There are no try/catch blocks in my current version which could be improved to include such error handling. Luckily, the program is basic enough to not require this as of now, but if additional features and functionality were introduced, error handling would be much more of a requirement.

## What Was Challenging
As with most of my other projects, I found the most challenging aspect of this project to be program achitecture. Performing the initial evaluation and approach to breaking down the solution into separate components that all have a unique task separate from the others is a skill I am actively developing. Once these components were identified, architecting each one uniquely was also challenging.

## Transferrable Skills
Despite being one of my biggest areas of needed improvement, I think the most transferable skill I improved is the ability to analyze a request for functionality and break it down into smaller, discrete parts and then creating those parts to work together. Over the duration of the course I also gained small yet useful approaches to do common things, such as creating a string of char c of n length or clearing cin with a new prompt for input. These snippets of logic and functionality can be used virtually anywhere.

## Maintainability / Readability / Adaptability
To make this solution maintainable, I utilized two classes, one to handle data and the other to handle user interaction and data output. The GroceryData class handles the ingestion of the data file and the creation of the map that stores the information ,and the archiving of the data. The GroceryWriter class displays the user menu and utilizes methods on the GroceryData class to get and display data in the form requested by the user. With this approach, not only is it easy to add additional methods to GroceryWriter to do various other things, but also to extend, enhance, and troublshoot existing functionality without risk of breaking the entire program. I also included many in-line comments to explain my rationale and train of thought as I built the program.
