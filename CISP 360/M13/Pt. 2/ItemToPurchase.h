#ifndef ITEMSTOPURCHASE_H
#define ITEMSTOPURCHASE_H

#include <iostream>
#include <iomanip>
using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(string name, double price, int quantity);
        void setName(string a);
        void setPrice(double a);
        void setQuantity(int a);
        string getName() const;
        double getPrice() const;
        int getQuantity() const;
        void printItemCost();
    private:
        string itemName;
        double itemPrice;
        int itemQuantity;
};

#endif