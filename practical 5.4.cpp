#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream &out) {
    out << "₹";
    return out;
}

int main() {
    string name[5] = {"A", "B", "C", "D", "E"};
    int marks[5] = {85, 92, 76, 88, 69};
    double fee[5] = {10000, 12000, 9000, 11000, 9500};

    cout << left << setw(10) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fee" << endl;

    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < 5; i++) {
        cout << left << setw(10) << name[i]
             << setw(10) << marks[i]
             << currency << setw(15) << fixed << setprecision(2) << fee[i]
             << endl;
    }

    return 0;
}