#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int recursiveSum(vector<int> &arr, int n) {
    if (n <= 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(vector<int> &arr) {
    int sum = 0;
    for (int x : arr)
        sum += x;
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start1 = high_resolution_clock::now();
    int rSum = recursiveSum(arr, n);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    int iSum = iterativeSum(arr);
    auto end2 = high_resolution_clock::now();

    cout << "Recursive Sum: " << rSum << endl;
    cout << "Iterative Sum: " << iSum << endl;

    cout << "Recursive Time: "
         << duration_cast<nanoseconds>(end1 - start1).count()
         << " ns" << endl;

    cout << "Iterative Time: "
         << duration_cast<nanoseconds>(end2 - start2).count()
         << " ns" << endl;

    return 0;
}