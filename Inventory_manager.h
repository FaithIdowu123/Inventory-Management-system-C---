#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <list>
#include "Item.h"

class Inventory_Manager {
    private:
        bool running = true;
        list<Item> Inventory;
    public:
        void start();
        void addToInventory();
        void listInventory();
        void searchInventory();
        void updateItem();
        void removeItem();
        void saveInventory();
        void loadInventory();
        string convertToLower(string &text);
};


#endif