#include <iostream>
#include <vector>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }

    double add(double a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    float subtract(float a, float b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    float multiply(float a, float b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "Division by zero error\n";
            return 0;
        }
        return a / b;
    }

    int sumArray(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        return sum;
    }

    float sumArray(float arr[], int n) {
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        return sum;
    }
};

int main() {
    Calculator c;

    cout << c.add(10, 20) << endl;
    cout << c.add(5.5f, 2.3f) << endl;
    cout << c.add(10, 5.5) << endl;
    cout << c.add(7.5, 3) << endl;

    cout << c.subtract(10, 5) << endl;
    cout << c.multiply(3, 4) << endl;

    cout << c.divide(10, 2) << endl;
    cout << c.divide(10, 0) << endl;

    int arr1[] = {1, 2, 3, 4, 5};
    float arr2[] = {1.5, 2.5, 3.5};

    cout << c.sumArray(arr1, 5) << endl;
    cout << c.sumArray(arr2, 3) << endl;

    return 0;
}