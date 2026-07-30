#include <bits/stdc++.h>
using namespace std;

int main() {
    string word, text;
    getline(cin, word);
    getline(cin, text);

    for (char& c : word) {
        c = tolower((unsigned char)c);
    }
    for (char& c : text) {
        c = tolower((unsigned char)c);
    }
    word = " " + word + " ";
    text = " " + text + " ";

    int cnt = 0;
    int firstPos = -1;
    int start = 0;
    while (true) {
        int pos = text.find(word, start);

        if (pos == string::npos) {
            break;
        }

        if (firstPos == -1) {
            firstPos = pos;
        }

        cnt++;
        start = pos + 1;
    }

    if (cnt == 0) {
        cout << -1;
    } else {
        cout << cnt << ' ' << firstPos;
    }
}