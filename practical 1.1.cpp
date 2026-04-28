#include <iostream>
#include <vector>
using namespace std;

class Wallet {
private:
    int walletID;
    string userName;
    double balance;
    bool isFrozen;
    vector<string> transactions;

    void addTransaction(string t) {
        if (transactions.size() == 5)
            transactions.erase(transactions.begin()); 
        transactions.push_back(t);
    }

public:
    Wallet(int id, string name) {
        walletID = id;
        userName = name;
        balance = 0;
        isFrozen = false;
    }

    void loadMoney(double amount) {
        if (isFrozen) {
            cout << "Wallet is frozen. Cannot load money.\n";
            return;
        }

        double cashback = amount * 0.05; 
        balance += amount + cashback;

        addTransaction("Loaded: " + to_string(amount));
        cout << "Money loaded with cashback! New balance: " << balance << endl;
    }

    void transferMoney(Wallet &receiver, double amount) {
        if (isFrozen) {
            cout << "Wallet is frozen. Cannot transfer.\n";
            return;
        }

        if (balance < amount) {
            cout << "Error: Insufficient balance!\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        addTransaction("Sent: " + to_string(amount));
        receiver.addTransaction("Received: " + to_string(amount));

        cout << "Transfer successful!\n";
    }

    void freezeWallet() {
        isFrozen = true;
        cout << "Wallet frozen.\n";
    }

    void unfreezeWallet() {
        isFrozen = false;
        cout << "Wallet unfrozen.\n";
    }

    void display() {
        cout << "\nWallet ID: " << walletID << endl;
        cout << "User: " << userName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Status: " << (isFrozen ? "Frozen" : "Active") << endl;

        cout << "Last Transactions:\n";
        for (string t : transactions)
            cout << "- " << t << endl;
    }
};

int main() {
    Wallet w1(1, "Alice");
    Wallet w2(2, "Bob");

    w1.loadMoney(1000);
    w1.transferMoney(w2, 300);
    w1.transferMoney(w2, 800); 

    w1.freezeWallet();
    w1.loadMoney(500); 

    w1.unfreezeWallet();
    w1.loadMoney(500);

    w1.display();
    w2.display();

    return 0;
}