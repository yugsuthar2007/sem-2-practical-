#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Error: File cannot be opened\n";
        return 0;
    }

    int lines = 0, words = 0, characters = 0;

    string line;

    while (getline(file, line)) {
        lines++;

        int i = 0;
        bool inWord = false;

        while (i < line.length()) {
            characters++;

            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }

            i++;
        }
    }

    file.close();

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << characters << endl;

    return 0;
}