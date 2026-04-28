#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accNo;
    string name;
    double balance;
    int transactions;

    static int totalAccounts;

public:
    Account(int a, string n, double b = 0) {
        accNo = a;
        name = n;
        balance = (b >= 0) ? b : 0;
        transactions = 0;
        totalAccounts++;
    }

    bool transfer(Account &to, double amount) {
        if (amount <= 0 || amount > balance)
            return false;

        balance -= amount;
        to.balance += amount;

        transactions++;
        to.transactions++;

        return true;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions++;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions++;
        }
    }

    void display() {
        cout << "Acc No: " << accNo
             << ", Name: " << name
             << ", Balance: " << balance
             << ", Transactions: " << transactions
             << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

int main() {
    vector<Account> acc;

    acc.push_back(Account(101, "A", 1000));
    acc.push_back(Account(102, "B", 2000));
    acc.push_back(Account(103, "C", 1500));
    acc.push_back(Account(104, "D", 3000));

    acc[0].transfer(acc[1], 300);
    acc[1].transfer(acc[2], 500);
    acc[3].transfer(acc[0], 1000);
    acc[2].transfer(acc[3], 200);

    for (auto &a : acc)
        a.display();

    cout << "Total Accounts: " << Account::getTotalAccounts() << endl;

    return 0;
}