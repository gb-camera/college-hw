#include "ItemToPurchase.h"
ItemToPurchase itemInput(int &a) {
    string name;
    double price;
    int quantity;
    cout << "Enter the item name:" << endl;
    if(a != 0) {
        cin.ignore();
    }
    getline(cin, name);
    cout << "Enter the item price:" << endl;
    cin >> price;
    cout << "Enter the item quantity:" << endl;
    cin >> quantity;
    ItemToPurchase item(name, price, quantity);
    a++;
    return item;
}

int main() {
    ItemToPurchase item1, item2;
    int counter = 0;
    item1 = itemInput(counter);
    cout << endl;
    item2 = itemInput(counter);
    item1.printItemCost();
    item2.printItemCost();
    cout << endl << "Total: $" << (item1.getPrice() * item1.getQuantity()) + (item2.getPrice() * item2.getQuantity());
    return 0;
}
