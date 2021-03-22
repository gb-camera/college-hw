#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};
void readInventory(vector<Item>& v) {
    ifstream f("inventory.txt");
    if(!f) {
        cout << "Error opening file." << endl;
        return;
    }
    string n;
    int q;
    double p;
    while(f >> n >> q >> p) {
        v.push_back(Item{n, q, p});
    }
}
double getTotalValue(const vector<Item>& v) {
    double sum = 0;
    for(size_t i = 0; i < v.size(); i++) {
        sum += v[i].quantity * v[i].price;
    }
    return sum;
}

int main() {
    vector<Item> v;
    readInventory(v);
    cout << "Total value: " << getTotalValue(v) << endl;
    return 0;
}