#include <iostream>
#include <string>
using namespace std;

int main() {
    string para;
    getline(cin, para);

    string words[500];
    int freq[500] = {0};
    int count = 0;

    string temp = "";

    for (int i = 0; i <= para.length(); i++) {
        char c = para[i];

        if (c == ' ' || c == '\0') {
            if (temp != "") {
                for (int j = 0; j < temp.length(); j++) {
                    temp[j] = tolower(temp[j]);
                }

                bool found = false;

                for (int k = 0; k < count; k++) {
                    if (words[k] == temp) {
                        freq[k]++;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    words[count] = temp;
                    freq[count] = 1;
                    count++;
                }

                temp = "";
            }
        } else {
            if (isalpha(c))
                temp += tolower(c);
        }
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < count; i++) {
        cout << words[i] << " : " << freq[i] << endl;
    }

    return 0;
}