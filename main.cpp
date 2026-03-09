#include <iostream>
#include <list>
#include "Item.h"

using namespace std;

int main() {
    cout << "Inventory Manager" << endl;
    list<Item> Inventory;
    bool start = true;

    while (start == true) {
        int option = 0;
        cout << "What would you like to do:" << endl;
        cout << "  1. Add to the inventory" << endl;
        cout << "  2. Remove from the inventory" << endl;
        cout << "  3. Update an item in the inventory" << endl;
        cout << "  4. List all items in the inventory" << endl;
        cout << "  5. Stop the program\n" << endl;

        cout << "Enter your option here: ";
        cin >> option;

        if (option == 1) {
            string name;
            int price;
            int quantity;
            cout << "Name: ";
            cin >> name; 
            cout << "Price: ";
            cin >> price; 
            cout << "Quantity: ";
            cin >> quantity; 
            Inventory.push_back(Item(name, price, quantity));
            start = false;
        }
    }
    return 0;
}