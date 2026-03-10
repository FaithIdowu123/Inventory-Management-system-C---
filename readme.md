# Inventory Manager (C++)

## Description
This program is a simple inventory management system written in C++. It allows a user to store and manage a collection of items in an inventory. Each item contains information such as its name, price, and quantity. The program provides several features that allow the user to add items, view the current inventory, update item details, remove items, and search for items, save the current inventory to a csv file and load the inventory from a csv file. The goal of this project is to practice object oriented programming, working with lists, user input handling, and file storage in C++.

## Purpose
The purpose of this project is to demonstrate the use of C++ programming concepts such as classes, lists, functions, and file input and output. It also helps practice structuring a program into smaller reusable functions and managing data using a container like a list. This program can be used as a basic foundation for larger inventory or database systems.

## Features
The program allows the user to add new items to the inventory by entering a name, price, and quantity.
It displays all items currently stored in the inventory in a numbered list.
It allows the user to update an item’s name, price, or quantity.
It allows the user to remove items from the inventory by selecting their position in the list.
It allows searching for items by name.
The program can save the inventory data to a file so it can be used again later.
The program can read inventory data from a file when it starts.

## How the Program Works
The program uses a class called Item to represent each product in the inventory. The Item class stores the name, price, and quantity of the item and provides functions to display or update the data.

All items are stored in a list container. This allows the program to dynamically add or remove items without needing to manage memory manually. Each item in the list represents one object of the Item class.

The program uses several functions to manage the inventory. These functions include adding items, listing items, updating items, removing items, searching for items, and saving or loading the inventory from a file.

When the program runs, the user is presented with a menu that allows them to choose what action they want to perform. Based on the user’s selection, the program calls the corresponding function.

## Video Showcase
[Youtube-Video]()

## Technologies Used
- Visual Studio
- C++ programming language
- Standard Template Library list container
- File input and output using file streams
- String handling and basic input validation

## How to Compile the Program
To compile the program using a C++ compiler such as g++, open a terminal in the project folder and run the compile command for the source files. This will generate an executable file that can be run to start the program. You can also use contorl + shift + B to complie the code.

## How to Run the Program
After compiling the program, run the generated executable file. The program will start in the terminal and display a menu with available actions. The user can select options to add items, update items, remove items, view the inventory, or exit the program.

### Example Workflow
1. The user starts the program.
2. The user chooses to add an item and enters the name, price, and quantity.
3. The item is stored in the inventory list.
4. The user can view the inventory to see all stored items.
5. The user can update the details of an item or remove it if necessary.
6. When finished, the user can save the inventory to a file.

# Resources used
- [C++-Docs](https://en.cppreference.com/w/)
- [C++-Tutorial-videos](https://www.youtube.com/playlist?list=PLBlnK6fEyqRh6isJ01MBnbNpV3ZsktSyS)

## Future Improvements
Possible improvements for this program include adding better input validation to prevent invalid values, implementing sorting or filtering of items, adding a graphical user interface, improving file storage formats, and allowing the program to handle larger datasets more efficiently.


## Author
This project was created by Faith Oluwatise Idowu as part in C++.