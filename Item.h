#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item{
    private:
        string name;
        float price;
        int quantity;
    public:
        Item(string name, float price, int quantity);
        string getName();
        float getPrice();
        int getQuantity();
        void updateName(string name);
        void updatePrice(float price);
        void updateQuantity(int quantity);
        void display();
        string getSaveFormat();
};

#endif