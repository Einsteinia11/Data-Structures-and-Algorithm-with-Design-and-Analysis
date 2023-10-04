#include <iostream>
#include <unordered_map>
using namespace std;

// TrieNode class
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children; // Mapping from character to child TrieNode
    bool isEndOfWord;                         // Indicates whether this node marks the end of a word

    TrieNode()
    {
        isEndOfWord = false;
    }
};

// Trie class
class Trie
{
public:
    Trie()
    {
        root = new TrieNode(); // Initialize the root node
    }

    // Insert a word into the Trie
    void insert(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            { // Create a new node if the character doesn't exist
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch]; // Move to the next node
        }
        current->isEndOfWord = true; // Mark the end of the inserted word
    }

    // Search for a word in the Trie
    bool search(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            {
                return false; // Character not found in the Trie
            }
            current = current->children[ch]; // Move to the next node
        }
        return current->isEndOfWord; // Return true if the last node marks the end of a word
    }

private:
    TrieNode *root; // The root node of the Trie
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    cout << boolalpha;                     // To print true/false instead of 1/0
    cout << trie.search("app") << endl;    // Output: true
    cout << trie.search("apple") << endl;  // Output: true
    cout << trie.search("banana") << endl; // Output: false

    return 0;
}
