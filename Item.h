#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item{
    private:
        string name;
        int price;
        int quantity;
    public:
        Item(string name, int price, int quantity);
        void updateName(string name);
        void updatePrice(int price);
        void updateQuantity(int quantity);
        void display();
};

#endif