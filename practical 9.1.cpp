#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> v1 = v;

    reverse(v1.begin(), v1.end());

    cout << "Using std::reverse:\n";
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector<int> v2 = v;

    vector<int>::iterator left = v2.begin();
    vector<int>::iterator right = v2.end() - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    cout << "Manual iterator reversal:\n";
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Reverse iteration:\n";
    for (vector<int>::reverse_iterator rit = v.begin(); rit != v.end(); rit++)
        cout << *rit << " ";
    cout << endl;

    return 0;
}