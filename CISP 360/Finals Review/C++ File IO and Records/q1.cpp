#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};
void readInventory(vector<Item>& a) {
    ifstream ifs("Inventory.txt");
    if(!ifs) {
        cout << "Error opening file!";
        return;
    }
    Item toAdd = {"", 0, 0.0};
    while(ifs >> toAdd.name >> toAdd.quantity >> toAdd.price) {
        a.push_back(toAdd);
        toAdd = {"", 0, 0.0};
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
    cout << fixed << setprecision(2) << "Total value of all items: $" << getTotalValue(items) << endl;
    return 0;
}