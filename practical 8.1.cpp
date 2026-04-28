#include <iostream>
#include <limits>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter two integers: ";

        if (!(cin >> a >> b)) {
            throw runtime_error("Invalid input: non-integer value entered");
        }

        if (b == 0) {
            throw runtime_error("Error: Division by zero");
        }

        cout << "Result: " << (a / b) << endl;
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}