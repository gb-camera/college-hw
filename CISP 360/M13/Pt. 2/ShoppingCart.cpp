#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
}
ShoppingCart::ShoppingCart(string name) {
    customerName = name;
}
string ShoppingCart::getCustomerName() const {
    return customerName;
}
void ShoppingCart::addItem(ItemToPurchase a) {
    cartItems.push_back(a);
}
void ShoppingCart::removeItem(string a) {
    for(size_t i = 0; i < cartItems.size(); i++) {
        if(cartItems.at(i).getName() == a) {
            cartItems.erase(cartItems.begin() + i);
        }
        else {
            cout << "Item not found in cart. Nothing removed." << endl;
        }
    }
}
void ShoppingCart::changeQuantity(string a, int b) {
    for(size_t i = 0; i < cartItems.size(); i++) {
        if(cartItems.at(i).getName() == a) {
            cartItems.at(i).setQuantity(b);
        }
        else {
            cout << "Item not found in cart. Nothing modified." << endl;
        }
    }
}
double ShoppingCart::getTotalCost() {
    double total = 0.0;
    for(size_t i = 0; i < cartItems.size(); i++) {
        total += (cartItems.at(i).getQuantity() * cartItems.at(i).getPrice());
    }
    return total;
}
void ShoppingCart::printCart() {
    cout << getCustomerName() << "'s Shopping Cart" << endl;
    cout << endl;
    for(size_t i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).printItemCost();
    }
    cout << fixed << setprecision(2) << endl << "Total: $" << getTotalCost();
}