#include <iostream>
#include "Item.h"

using namespace std;

// Constructor to initialize an item
Item::Item(string name, float price, int quantity) {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
};

string Item::getName() {
    string itemName = this->name;
    return itemName; // return item name
};

float Item::getPrice() {
    return this->price; // return item price
};

int Item::getQuantity() {
    return this->quantity; // return item quantity
}

// Update item name
void Item::updateName(string name) {
    this->name = name;
};

// Update item price
void Item::updatePrice(float price) {
    this->price = price;
};

// Update item quantity
void Item::updateQuantity(int quantity) {
    this->quantity = quantity;
};

// Display item information
void Item::display() {
    cout << "Name: " << this->name << ", Price: $" << this->price << ", Quantity: " << this->quantity 
    << ". " << "Total Cost: $" << this->price * this->quantity << endl;
}
