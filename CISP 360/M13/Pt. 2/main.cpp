#include "ItemToPurchase.h"
#include "ShoppingCart.h"

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
    string name;
    int counter = 0;
    cout << "Name:  ";
    getline(cin, name);
    ShoppingCart cart(name);
    cart.addItem(itemInput(counter));
    cout << endl;
    cart.addItem(itemInput(counter));
    cout << endl;
    cart.addItem(itemInput(counter));
    cart.printCart();
}
