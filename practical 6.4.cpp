#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;
    vector<string> history;

public:
    Account(int a = 0, double b = 0) {
        accNo = a;
        balance = (b >= 0) ? b : 0;
        history.push_back("Account Created");
    }

    virtual ~Account() {
        history.push_back("Account Closed");
    }

    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            history.push_back("Deposited " + to_string(amt));
        }
    }

    virtual void withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            history.push_back("Withdraw " + to_string(amt));
        }
    }

    void undoLast() {
        if (!history.empty()) {
            history.pop_back();
        }
    }

    void displayHistory() {
        for (auto &h : history)
            cout << h << endl;
    }

    virtual void display() {
        cout << "Acc No: " << accNo
             << ", Balance: " << balance << endl;
    }
};

class Savings : public Account {
private:
    double interestRate;

public:
    Savings(int a, double b, double r)
        : Account(a, b) {
        interestRate = r;
    }

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        history.push_back("Interest Added " + to_string(interest));
    }

    void display() override {
        cout << "Savings Account\n";
        Account::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class Current : public Account {
private:
    double overdraft;

public:
    Current(int a, double b, double o)
        : Account(a, b) {
        overdraft = o;
    }

    void withdraw(double amt) override {
        if (amt > 0 && amt <= balance + overdraft) {
            balance -= amt;
            history.push_back("Withdraw " + to_string(amt));
        }
    }

    void display() override {
        cout << "Current Account\n";
        Account::display();
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main() {
    Savings s(101, 1000, 5);
    Current c(102, 2000, 500);

    s.deposit(500);
    s.withdraw(200);
    s.applyInterest();

    c.deposit(1000);
    c.withdraw(2500);

    s.display();
    s.displayHistory();

    cout << endl;

    c.display();
    c.displayHistory();

    return 0;
}