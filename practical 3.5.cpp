#include <iostream>
#include <string>
using namespace std;

int superDigit(long long n) {
    if (n < 10)
        return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

int superDigit(string n, int k) {
    long long sum = 0;

    for (char c : n)
        sum += (c - '0');

    sum *= k;

    return superDigit(sum);
}

int main() {
    string n;
    int k;

    cin >> n >> k;

    cout << superDigit(n, k) << endl;

    return 0;
}