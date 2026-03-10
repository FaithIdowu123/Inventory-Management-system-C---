#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(string name, float price, int quantity) {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
};

string Item::getName() {
    string itemName = this->name;
    return itemName;
};

float Item::getPrice() {
    return this->price;
};

int Item::getQuantity() {
    return this->quantity;
}

void Item::updateName(string name) {
    this->name = name;
};

void Item::updatePrice(float price) {
    this->price = price;
};

void Item::updateQuantity(int quantity) {
    this->quantity = quantity;
};

void Item::display() {
    cout << "Name: " << this->name << ", Price: $" << this->price << ", Quantity: " << this->quantity 
    <<". " << "Total: " << this->price * this->quantity << endl;
}



