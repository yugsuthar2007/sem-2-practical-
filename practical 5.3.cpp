#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;
    double price;
};

void addItem() {
    ofstream file("inventory.txt", ios::app);

    Item it;
    cout << "Enter name: ";
    cin >> it.name;
    cout << "Enter quantity: ";
    cin >> it.quantity;
    cout << "Enter price: ";
    cin >> it.price;

    file << it.name << " " << it.quantity << " " << it.price << endl;

    file.close();
}

void viewItems() {
    ifstream file("inventory.txt");

    if (!file) {
        cout << "File not found\n";
        return;
    }

    Item it;

    cout << "\nInventory List:\n";

    while (file >> it.name >> it.quantity >> it.price) {
        cout << "Name: " << it.name
             << ", Quantity: " << it.quantity
             << ", Price: " << it.price << endl;
    }

    file.close();
}

void searchItem() {
    ifstream file("inventory.txt");

    if (!file) {
        cout << "File not found\n";
        return;
    }

    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    Item it;
    bool found = false;

    while (file >> it.name >> it.quantity >> it.price) {
        if (it.name == searchName) {
            cout << "Found:\n";
            cout << "Name: " << it.name
                 << ", Quantity: " << it.quantity
                 << ", Price: " << it.price << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Item not found\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Item\n2. View Items\n3. Search Item\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            addItem();
        else if (choice == 2)
            viewItems();
        else if (choice == 3)
            searchItem();

    } while (choice != 0);

    return 0;
}