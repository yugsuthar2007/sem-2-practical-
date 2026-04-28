#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    map<string, int> freq;

    string word;
    stringstream ss(sentence);

    while (ss >> word) {
        freq[word]++;
    }

    cout << "Word Frequencies:\n";

    for (map<string, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}