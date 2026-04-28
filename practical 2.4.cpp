#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "Default";
        price = 0;
        quantity = 0;
    }

    Item(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = (p >= 0) ? p : 0;
        quantity = (q >= 0) ? q : 0;
    }

    int getQuantity() { return quantity; }

    void restock(int q) {
        if (q > 0)
            quantity += q;
    }

    void sell(int q) {
        if (q <= 0) {
            cout << "Invalid quantity\n";
        } else if (q > quantity) {
            cout << "Not enough stock\n";
        } else {
            quantity -= q;
        }
    }

    void updatePrice(double p) {
        if (p >= 0)
            price = p;
    }

    void display() {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: " << price
             << ", Quantity: " << quantity << endl;
    }
};

int main() {
    vector<Item> items;

    items.push_back(Item(1, "Pen", 10, 20));
    items.push_back(Item(2, "Book", 50, 3));
    items.push_back(Item(3, "Bag", 500, 10));
    items.push_back(Item(4, "Pencil", 5, 2));
    items.push_back(Item(5, "Bottle", 100, 15));

    for (auto &i : items) {
        i.sell(2);
        i.restock(5);
    }

    cout << "\nAll Items:\n";
    for (auto &i : items) {
        i.display();
    }

    cout << "\nLow Stock Items (<5):\n";
    for (auto &i : items) {
        if (i.getQuantity() < 5)
            i.display();
    }

    sort(items.begin(), items.end(), [](Item a, Item b) {
        return a.getQuantity() > b.getQuantity();
    });

    cout << "\nSorted by Quantity:\n";
    for (auto &i : items) {
        i.display();
    }

    cout << "\nItem with Maximum Stock:\n";
    items[0].display();

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Loan {
private:
    int loanID;
    string name;
    double amount;
    double rate;
    int tenure;

public:
    Loan() {
        loanID = 0;
        name = "Default";
        amount = 0;
        rate = 0;
        tenure = 1;
    }

    Loan(int id, string n, double a, double r, int t) {
        loanID = id;
        name = n;
        amount = (a > 0) ? a : 0;
        rate = (r > 0) ? r : 0;
        tenure = (t > 0) ? t : 1;
    }

    double calculateEMI() {
        double monthlyRate = rate / (12 * 100);
        double emi = (amount * monthlyRate * pow(1 + monthlyRate, tenure)) /
                     (pow(1 + monthlyRate, tenure) - 1);
        return emi;
    }

    double totalRepayment() {
        return calculateEMI() * tenure;
    }

    void display() {
        cout << "Loan ID: " << loanID
             << ", Name: " << name
             << ", Amount: " << amount
             << ", Rate: " << rate
             << ", Tenure: " << tenure
             << ", EMI: " << calculateEMI()
             << ", Total: " << totalRepayment()
             << endl;
    }
};

int main() {
    vector<Loan> loans;

    loans.push_back(Loan(1, "A", 100000, 10, 12));
    loans.push_back(Loan(2, "B", 200000, 12, 24));
    loans.push_back(Loan(3, "C", 150000, 9, 18));
    loans.push_back(Loan(4, "D", 250000, 11, 36));

    cout << "\nLoan Details:\n";
    for (auto &l : loans) {
        l.display();
    }

    sort(loans.begin(), loans.end(), [](Loan a, Loan b) {
        return a.calculateEMI() > b.calculateEMI();
    });

    cout << "\n2nd Highest EMI:\n";
    loans[1].display();

    return 0;
}