#include <iostream>
#include <unordered_map>
using namespace std;

// TrieNode class
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

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
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (!current->children[ch])
            {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    void remove(const string &word)
    {
        removeHelper(root, word, 0);
    }

private:
    TrieNode *root;

    // Helper function to recursively remove a word from the Trie
    bool removeHelper(TrieNode *node, const string &word, int index)
    {
        if (index == word.length())
        {
            // If we've reached the end of the word
            if (!node->isEndOfWord)
            {
                // The word doesn't exist in the Trie
                return false;
            }
            node->isEndOfWord = false;     // Mark the end of the word as false to delete it
            return node->children.empty(); // Return true if no other words share this prefix
        }

        char ch = word[index];
        if (!node->children[ch])
        {
            // The character doesn't exist in the Trie
            return false;
        }

        bool shouldDeleteChild = removeHelper(node->children[ch], word, index + 1);

        if (shouldDeleteChild)
        {
            // Delete the child node since it's no longer needed
            node->children.erase(ch);

            // Return true if this node has no other children and is not the end of another word
            return node->children.empty() && !node->isEndOfWord;
        }

        return false;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    cout << boolalpha;                    // To print true/false instead of 1/0
    cout << trie.search("app") << endl;   // Output: true
    cout << trie.search("apple") << endl; // Output: true

    trie.remove("app");
    cout << trie.search("app") << endl; // Output: false

    return 0;
}
