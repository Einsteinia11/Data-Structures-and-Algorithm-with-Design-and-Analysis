#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> memo;

bool isScramble(string s1, string s2) {
    // Check if the strings are equal
    if (s1 == s2) {
        return true;
    }

    // Check if the characters in the two strings are the same
    int count[26] = {0};
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    // Check previously memoized results
    string key = s1 + "#" + s2;
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    // Recursively check all possible splits
    for (int i = 1; i < n; i++) {
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
            (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
            // Memoize the result
            memo[key] = true;
            return true;
        }
    }

    // Memoize the result
    memo[key] = false;
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    bool result = isScramble(s1, s2);

    if (result) {
        cout << "Yes, " << s1 << " is a scrambled string of " << s2 << endl;
    } else {
        cout << "No, " << s1 << " is not a scrambled string of " << s2 << endl;
    }

    return 0;
}
