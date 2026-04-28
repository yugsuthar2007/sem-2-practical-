#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    string name;
    int accountID;
    double balance;
    vector<string> transactions;

    void addTransaction(string t) {
        if (transactions.size() == 3)
            transactions.erase(transactions.begin());
        transactions.push_back(t);
    }

public:
    Account(string n, int id, double bal = 0) {
        name = n;
        accountID = id;
        balance = (bal >= 0) ? bal : 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction("Deposited: " + to_string(amount));
        } else {
            cout << "Invalid deposit amount\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount\n";
        } else if (amount > balance) {
            cout << "Insufficient balance\n";
        } else {
            balance -= amount;
            addTransaction("Withdrawn: " + to_string(amount));
        }
    }

    void applyInterest(double rate) {
        if (rate > 0) {
            double interest = balance * rate / 100;
            balance += interest;
            addTransaction("Interest added: " + to_string(interest));
        }
    }

    string getStatus() {
        return (balance > 0) ? "Active" : "Inactive";
    }

    void display() {
        cout << "\nAccount ID: " << accountID
             << "\nName: " << name
             << "\nBalance: " << balance
             << "\nStatus: " << getStatus()
             << "\nRecent Transactions:\n";

        for (auto &t : transactions) {
            cout << "- " << t << endl;
        }
    }
};

int main() {
    vector<Account> accounts;

    accounts.push_back(Account("Alice", 101, 1000));
    accounts.push_back(Account("Bob", 102));
    accounts.push_back(Account("Charlie", 103, 500));

    for (auto &acc : accounts) {
        acc.deposit(500);
        acc.deposit(200);
        acc.withdraw(300);
        acc.withdraw(2000); // invalid withdrawal
        acc.applyInterest(5);
    }

    for (auto &acc : accounts) {
        acc.display();
    }

    return 0;
}