#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main()
{
    string text, pattern;
    cout << "Enter text : ";
    cin >> text;
    cout << "Enter pattern : ";
    cin >> pattern;

    string s = pattern + '$' + text;
    vector<int> z = z_function(s);
    cout << "Pattern matched at indices (0-based) ";
    for (int i = 0; i < s.size(); i++)
    {
        if (z[i] == pattern.size())
            cout << i - pattern.size() - 1 << ' ';
    }
    return 0;
}
