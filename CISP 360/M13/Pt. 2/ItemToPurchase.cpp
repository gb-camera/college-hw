#include "ItemToPurchase.h"
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string name, double price, int quantity) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quantity;
}
void ItemToPurchase::setName(string a) {
    itemName = a;
}
void ItemToPurchase::setPrice(double a) {
    itemPrice = a;
}
void ItemToPurchase::setQuantity(int a) {
    itemQuantity = a;
}
string ItemToPurchase::getName() const {
    return itemName;
}
double ItemToPurchase::getPrice() const {
    return itemPrice;
}
int ItemToPurchase::getQuantity() const {
    return itemQuantity;
}
void ItemToPurchase::printItemCost() {
    cout << fixed << setprecision(2) << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemPrice * itemQuantity) << endl;
}