#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator += (const Complex &c) {
        real += c.real;
        imag += c.imag;
        return *this;
    }

    Complex operator *= (const Complex &c) {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        real = r;
        imag = i;
        return *this;
    }

    double magnitude() {
        return sqrt(real * real + imag * imag);
    }

    double phase() {
        return atan2(imag, real);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2), c3(2, -1);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    sum.display();
    diff.display();

    c1 += c2;
    c1.display();

    c2 *= c3;
    c2.display();

    vector<Complex> arr = {Complex(1, 1), Complex(2, 2), Complex(3, 3)};

    Complex total(0, 0);
    for (auto &x : arr)
        total += x;

    cout << "Batch Sum: ";
    total.display();

    cout << "Magnitude: " << total.magnitude() << endl;
    cout << "Phase: " << total.phase() << endl;

    return 0;
}