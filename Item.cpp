#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(string name, int price, int quantity) {
    this->name = name;
    this->price = price;
    this->quantity = quantity;
};

void Item::updateName(string name) {
    this->name = name;
};

void Item::updatePrice(int price) {
    this->price = price;
};

void Item::updateQuantity(int quantity) {
    this->quantity = quantity;
};

void Item::display() {
    cout << "Name: " << this->name << ", Price: " << this->price << ", Quantity: " << this->quantity << endl;
}