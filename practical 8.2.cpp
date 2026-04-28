#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {
private:
    double value;

public:
    NegativeNumberException(double v) {
        value = v;
    }

    void message() {
        cout << "Error: Negative number not allowed -> " << value << endl;
    }
};

int main() {
    double n;

    for (int i = 0; i < 6; i++) {
        cin >> n;

        try {
            if (n < 0) {
                throw NegativeNumberException(n);
            }

            cout << "Square root: " << sqrt(n) << endl;
        }
        catch (NegativeNumberException &e) {
            e.message();
        }
    }

    return 0;
}