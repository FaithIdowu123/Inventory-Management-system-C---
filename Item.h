#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

// Represents a single inventory item
class Item{
    private:
        string name;   // item name
        float price;   // item price
        int quantity;  // item quantity

    public:
        Item(string name, float price, int quantity); // constructor

        string getName();      // return item name
        float getPrice();      // return item price
        int getQuantity();     // return item quantity

        void updateName(string name);       // update name
        void updatePrice(float price);      // update price
        void updateQuantity(int quantity);  // update quantity

        void display();        // display item info
        string getSaveFormat();// return format used for saving
};

#endif