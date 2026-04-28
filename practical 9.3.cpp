#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    vector<int> input(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
        s.insert(input[i]);
    }

    cout << "Unique elements (using set iterator):\n";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> v(s.begin(), s.end());

    cout << "Converted to vector:\n";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    int duplicatesRemoved = n - s.size();
    cout << "Duplicates removed: " << duplicatesRemoved << endl;

    return 0;
}