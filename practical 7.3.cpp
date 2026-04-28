#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    double c;

public:
    Celsius(double temp = 0) {
        c = temp;
    }

    operator Fahrenheit();

    double get() {
        return c;
    }
};

class Fahrenheit {
private:
    double f;

public:
    Fahrenheit(double temp = 0) {
        f = temp;
    }

    operator Celsius() {
        return Celsius((f - 32) * 5.0 / 9.0);
    }

    double get() {
        return f;
    }

    bool operator==(const Fahrenheit &other) {
        return f == other.f;
    }

    void display() {
        cout << f << " F" << endl;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((c * 9.0 / 5.0) + 32);
}

int main() {
    Celsius c1(25);
    Fahrenheit f1 = c1;

    cout << "Celsius to Fahrenheit: ";
    f1.display();

    Celsius c2 = f1;
    cout << "Fahrenheit to Celsius: " << c2.get() << " C" << endl;

    queue<Fahrenheit> q;
    q.push(Fahrenheit(98.6));
    q.push(Fahrenheit(100));
    q.push(f1);

    cout << "\nQueue Processing:\n";
    while (!q.empty()) {
        q.front().display();
        q.pop();
    }

    Fahrenheit a(100), b(100);

    if (a == b)
        cout << "Equal Temperatures\n";

    return 0;
}