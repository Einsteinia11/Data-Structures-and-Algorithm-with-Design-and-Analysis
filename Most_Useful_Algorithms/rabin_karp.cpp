#include <iostream>
#include <string>
#include <cmath>
// string matching algorithm
using namespace std;

// Define a prime number for modulo operation to avoid integer overflow
const int prime = 101;

// Function to calculate the hash value for a given substring
int calculateHash(const string &str, int length)
{
    int hashValue = 0;
    for (int i = 0; i < length; i++)
    {
        hashValue += str[i] * pow(prime, i);
    }
    return hashValue;
}

// Function to implement the Rabin-Karp algorithm
void rabinKarpSearch(const string &text, const string &pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();
    int patternHash = calculateHash(pattern, patternLength);
    int textHash = calculateHash(text, patternLength);

    for (int i = 0; i <= textLength - patternLength; i++)
    {
        if (textHash == patternHash)
        {
            // Check character by character if there is a match
            bool match = true;
            for (int j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at position " << i << endl;
            }
        }
        // Calculate the hash value for the next substring in the text
        if (i < textLength - patternLength)
        {
            textHash = (textHash - text[i] * pow(prime, 0)) * prime + text[i + patternLength];
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Searching for pattern: " << pattern << " in text: " << text << endl;
    rabinKarpSearch(text, pattern);

    return 0;
}
