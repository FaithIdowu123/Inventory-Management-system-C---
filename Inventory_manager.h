#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <list>   // list container
#include "Item.h" // Item class

class Inventory_Manager {
    private:
        bool running = true;   // controls main program loop
        list<Item> Inventory;  // stores all inventory items
    public:
        void start();          // starts the program
        void addToInventory(); // add item
        void listInventory();  // display items
        void searchInventory();// search for item
        void updateItem();     // update item details
        void removeItem();     // remove item
        void saveInventory();  // save to file
        void loadInventory();  // load from file
        string convertToLower(string &text); // make text lowercase
};

#endif