#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<string, vector<string>> dir;

    int choice;
    string folder, file;

    do {
        cout << "\n1. Add Folder\n2. Add File\n3. Display\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            cin >> folder;
            if (dir.find(folder) == dir.end()) {
                dir[folder] = vector<string>();
            }
        }

        else if (choice == 2) {
            cin >> folder >> file;
            dir[folder].push_back(file);
        }

        else if (choice == 3) {
            for (map<string, vector<string>>::iterator it = dir.begin(); it != dir.end(); it++) {
                cout << it->first << ":\n";
                for (vector<string>::iterator vit = it->second.begin(); vit != it->second.end(); vit++) {
                    cout << "  " << *vit << endl;
                }
            }
        }

    } while (choice != 0);

    return 0;
}