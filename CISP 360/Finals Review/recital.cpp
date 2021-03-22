#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

void readInventory(vector<Item>& a) {
    ifstream in("Inventory.txt");
    if(!in) {
        cout << "Error opening file for input..." << endl;
    }
    Item input = {"", 0, 0.0};
    while(in >> input.name >> input.price >> input.quantity) {
        a.push_back(input);
        input = {"", 0, 0.0};
    }
}

double getTotalValue(const vector<Item>& a) {
    double sum = 0.0;
    for(size_t i = 0; i < a.size(); i++) {
        sum += a.at(i).quantity * a.at(i).price;
    }
    return sum;
}

int main() {
    vector<Item> items;
    readInventory(items);
    cout << "Total value of all items: $" << getTotalValue(items) << endl;
    return 0;
}