#include <iostream>
#include <list>
#include "Item.h"
#include "Inventory_manager.h"
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Main program loop and menu
void Inventory_Manager::start() {
    cout << "Welcome to the Inventory Manager" << endl;

    while (this->running == true) {
        cout << "" << endl;
        int option = 0;

        // Display menu
        cout << "What would you like to do:" << endl;
        cout << "  1. Add to the inventory" << endl;
        cout << "  2. List all items in the inventory" << endl;
        cout << "  3. Search inventory by Name" << endl;
        cout << "  4. Update an item in the inventory" << endl;
        cout << "  5. Remove from the inventory" << endl;
        cout << "  6. Save inventory" << endl;
        cout << "  7. Load inventory" << endl;
        cout << "  8. Stop the program\n" << endl;

        cout << "Enter your option here: ";
        cin >> option;

        cout << "" << endl;

        if (option == 1) {
            cout << "Fill out the following:" << endl;
            addToInventory();
        }

        else if (option == 2) {
            if (!Inventory.empty()) {
                cout << "This is a list of all the items in the inventory:" << endl;
                listInventory();
            }
            else{
                cout << "Sorry, the Inventory is empty" << endl;
            }
        }

        else if (option == 3) {
            searchInventory();
        }

        else if (option == 4) {
            updateItem();
        }

        else if (option == 5) {
            removeItem();
        }

        else if (option == 6) {
            saveInventory();
        }

        else if (option == 7) {
            loadInventory();
        }

        else if (option == 8) {
            cout << "See you later!" << endl;
            running = false; // stop program
        }

        else {
            cout << "Please give a valid choice!";
        }
    }
}

// Add a new item to the inventory
void Inventory_Manager::addToInventory() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name;
    float price;
    int quantity;

    cout << "Name: ";
    cin >> name; 

    cout << "Price: ";
    cin >> price; 

    cout << "Quantity: ";
    cin >> quantity; 

    this->Inventory.push_back(Item(name, price, quantity));

    // Display the item that was added
    this->Inventory.front().display();

    cout << name << " was successfully added!" << endl;
}

// Display all items in inventory
void Inventory_Manager::listInventory() {
    int i = 0;
    for (Item &item : this->Inventory) {
        i++;
        cout << i << ". ";
        item.display();
    }
    cout << "" << endl;
}

// Search inventory by item name
void Inventory_Manager::searchInventory() {
    list<Item> results;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string name;
    cout << "What is the name of the item you are looking for: ";
    cin >> name;

    name = convertToLower(name); // make search case insensitive

    for (Item &item : this->Inventory) {
        string itemName = item.getName();
        itemName = convertToLower(itemName);

        if (itemName.find(name) != string::npos || itemName.find(name) != string::npos) {
            results.push_back(item);
        }
    }

    if (results.empty()) {
        cout << "Oops, item not found" << endl;
    }
    else {
        cout << "Found " << this->Inventory.size() << "item/items" <<endl;

        int i = 0;
        for (Item &item : results) {
            i++;
            cout << i << ". ";
            item.display();
        }
    }
}

// Update an existing item
void Inventory_Manager::updateItem() {
    int option;
    int choice;

    cout << "Choose the item you wish to change(By Number): " << endl;
    listInventory();

    cout << "0" << ". " << "Cancel" << endl;
    
    cout << "Choice: ";
    cin >> choice;

    if (!choice == 0){
        auto it = this->Inventory.begin();
        advance(it, choice-1); // move iterator to selected item

        cout << "" << endl;

        cout << "What to do you wish to change: " << endl;
        cout << "  1. Name" << endl << "  2. Price" << endl << "  3. Quantity\n" << endl;

        cout << "0" << ". " << "Cancel" << endl;

        cout << "Option: ";
        cin >> option;

        if (!option == 0){
            cout << "" << endl;

            if (option == 1){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string newName;

                cout << "What would uou like to change the name to: ";
                getline(cin, newName);

                it->updateName(newName);

                cout << "Item Successfully updated" << endl;
            }

            else if (option == 2){
                float newPrice;

                cout << "What would uou like to change the price to: ";
                cin >> newPrice;

                it->updatePrice(newPrice);

                cout << "Item Successfully updated" << endl;
            }

            else if (option == 3){
                int newQuantity;

                cout << "What would uou like to change the quantity to: ";
                cin >> newQuantity;

                it->updateQuantity(newQuantity);

                cout << "Item Successfully updated" << endl;
            }
        }
    }
}

// Remove an item from inventory
void Inventory_Manager::removeItem() {
    int choice;

    cout << "Choose the item you wish to remove(By Number): " << endl;
    listInventory();

    cout << "0" << ". " << "Cancel" << endl;
    
    cout << "Choice: ";
    cin >> choice;

    if (!choice == 0) {
        auto it = this->Inventory.begin();
        advance(it, choice-1);

        this->Inventory.erase(it);

        cout << "" << endl;
        cout << "Item Successfully removed" << endl;
    }
}

// Save inventory to CSV file
void Inventory_Manager::saveInventory() {
    string file;

    cout << "What is the name of the file you would like to save the inventory to: ";
    cin >> file;

    string path = "data/" + file;

    ofstream outFile(path);

    if (!outFile) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    outFile << "Name,Price,Quantity\n";

    for (Item &item : this->Inventory) {
        outFile << item.getName() << "," << item.getPrice() << "," << item.getQuantity() << "\n";
    }

    outFile.close();

    cout << "Inventory saved successfully" << endl;
}

// Load inventory from CSV file
void Inventory_Manager::loadInventory() {
    string file;

    cout << "What is the name of the file you would like to load: ";
    cin >> file;

    string path = "data/" + file;

    ifstream inFile(path);

    if (!inFile) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string line;

    getline(inFile, line); // skip header line

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);

        string name, priceStr, quantityStr;

        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, quantityStr);

        float price = stof(priceStr);
        int quantity = stoi(quantityStr);

        this->Inventory.push_back(Item(name, price, quantity));
    }

    cout << "Inventory loaded successfully" << endl;
}

// Convert a string to lowercase
string Inventory_Manager::convertToLower(string &text) {
    for (char &c : text) {
        c = tolower(c);
    }

    return text;
}