#include <iostream>
#include <string>
using namespace std;

string process(string s) {
    char st[1000];
    int top = -1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#') {
            if (top != -1) {
                top--;
            }
        }
        else {
            top++;
            st[top] = s[i];
        }
    }

    string result = "";

    for (int i = 0; i <= top; i++) {
        result += st[i];
    }

    return result;
}

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (process(s) == process(t)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
