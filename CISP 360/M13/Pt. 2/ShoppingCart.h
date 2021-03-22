#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <vector>

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(string name);
        string getCustomerName() const;
        void addItem(ItemToPurchase a);
        void removeItem(string a);
        void changeQuantity(string a, int b);
        double getTotalCost();
        void printCart();
    private:
        string customerName;
        vector<ItemToPurchase> cartItems;
};

#endif