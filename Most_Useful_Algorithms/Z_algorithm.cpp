#include <bits/stdc++.h>
using namespace std;

// interested readers can find more about Z-function here
// https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

// Function to compute Z-function for a given string
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;  // Current left and right boundaries of the Z-box

    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]); // If 'i' is within the current Z-box, copy value from its corresponding position in the Z-array
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++; // Expand Z-box to the right as long as characters match
        }

        if (i + z[i] > r) {
            l = i; // Update left boundary of Z-box
            r = i + z[i]; // Update right boundary of Z-box
        }
    }
    return z;
}

// Main function to find pattern occurrences in a given text
int main() {
    string text, pattern;
    cout << "Enter text : ";
    cin >> text;
    cout << "Enter pattern : ";
    cin >> pattern;

    // Concatenate pattern, delimiter '$', and text to form new string
    string s = pattern + '$' + text;

    // Compute Z-function for the new string
    vector<int> z = z_function(s);

    // Output indices where pattern is matched (0-based indexing)
    cout << "Pattern matched at indices (0-based) ";
    for (int i = 0; i < s.size(); i++) {
        if (z[i] == pattern.size())
            cout << i - pattern.size() - 1 << ' ';
    }
    return 0;
}
