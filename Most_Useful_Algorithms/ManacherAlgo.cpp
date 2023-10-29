#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPalindromicSubstring(string s) {
    // Transform the string to make it uniform and handle even length palindromes.
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int N = t.size();
    vector<int> P(N, 0); // Radius array.
    int center = 0, rightBoundary = 0;

    for (int i = 0; i < N; i++) {
        // If i is within the right boundary of the current palindrome,
        // get the mirror index of i with respect to the center.
        int mirror = 2*center - i;

        // If i is within the boundary, try to use the information of the mirror palindrome.
        if (rightBoundary > i) {
            P[i] = min(rightBoundary - i, P[mirror]);
        }

        // Attempt to expand the palindrome centered at i.
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < N && b >= 0 && t[a] == t[b]) {
            P[i]++;
            a++;
            b--;
        }

        // If palindrome centered at i expands past the right boundary,
        // adjust the center and right boundary.
        if (i + P[i] > rightBoundary) {
            center = i;
            rightBoundary = i + P[i];
        }
    }

    // Find the maximum palindrome.
    int maxLen = 0, centerIndex = 0;
    for (int i = 0; i < N; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract the characters of the palindrome without added '#' characters.
    return s.substr((centerIndex - maxLen) / 2, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring of " << s << " is: " << longestPalindromicSubstring(s) << endl;
    return 0;
}
