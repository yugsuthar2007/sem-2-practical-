#include <iostream>
using namespace std;

class InsufficientFundsException {
private:
    double attempted;

public:
    InsufficientFundsException(double amt) {
        attempted = amt;
    }

    void show() {
        cout << "Insufficient Funds! Attempted Withdrawal: " << attempted << endl;
    }
};

class BankAccount {
private:
    double balance;
    string log[100];
    int idx;

    void record(string msg) {
        log[idx++] = msg;
    }

public:
    BankAccount(double b = 0) {
        balance = b;
        idx = 0;
        record("Account Created");
    }

    void deposit(double amt) {
        record("Enter deposit()");
        if (amt <= 0) {
            record("Invalid deposit");
            throw runtime_error("Invalid deposit amount");
        }
        balance += amt;
        record("Deposit success");
        record("Exit deposit()");
    }

    void withdraw(double amt) {
        record("Enter withdraw()");
        if (amt > balance) {
            record("Withdraw failed");
            throw InsufficientFundsException(amt);
        }
        balance -= amt;
        record("Withdraw success");
        record("Exit withdraw()");
    }

    double getBalance() {
        return balance;
    }

    void showLog() {
        cout << "\nTransaction Log:\n";
        for (int i = 0; i < idx; i++)
            cout << log[i] << endl;
    }
};

int main() {
    BankAccount acc(500);

    try {
        acc.deposit(200);
        acc.withdraw(300);
        acc.withdraw(1000);
    }
    catch (InsufficientFundsException &e) {
        e.show();
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }

    cout << "Final Balance: " << acc.getBalance() << endl;
    acc.showLog();

    return 0;
}