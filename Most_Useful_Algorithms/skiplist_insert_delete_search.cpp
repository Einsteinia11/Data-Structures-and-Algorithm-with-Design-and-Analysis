/* A Skip List is a data structure that allows for efficient searching, insertion, and deletion of elements with average-case time complexity similar to that of a balanced binary search tree. Skip Lists use multiple linked lists with different levels of granularity to achieve this efficiency.*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Node class for Skip List
class SkipListNode
{
public:
    int value;
    SkipListNode **forward; // Array of pointers to the next nodes at different levels

    SkipListNode(int val, int levels) : value(val)
    {
        forward = new SkipListNode *[levels];
        for (int i = 0; i < levels; ++i)
        {
            forward[i] = nullptr;
        }
    }

    ~SkipListNode()
    {
        delete[] forward;
    }
};

// Skip List class
class SkipList
{
public:
    SkipList(int maxLevels) : maxLevels_(maxLevels), currentLevels_(1)
    {
        head_ = new SkipListNode(INT_MIN, maxLevels_);
        tail_ = new SkipListNode(INT_MAX, maxLevels_);
        for (int i = 0; i < maxLevels_; ++i)
        {
            head_->forward[i] = tail_;
        }
        srand(time(nullptr)); // Seed for random level generation
    }

    ~SkipList()
    {
        delete head_;
        delete tail_;
    }

    // Search for a value in the Skip List
    bool search(int target)
    {
        SkipListNode *current = head_;
        for (int level = currentLevels_ - 1; level >= 0; --level)
        {
            while (current->forward[level]->value < target)
            {
                current = current->forward[level];
            }
        }
        current = current->forward[0]; // Move to the bottom level
        return (current->value == target);
    }

    // Insert a value into the Skip List
    void insert(int value)
    {
        SkipListNode *current = head_;
        SkipListNode *update[maxLevels_];
        for (int level = currentLevels_ - 1; level >= 0; --level)
        {
            while (current->forward[level]->value < value)
            {
                current = current->forward[level];
            }
            update[level] = current;
        }
        current = current->forward[0]; // Move to the bottom level

        // If the value is not already in the list, insert it
        if (current->value != value)
        {
            int newLevels = randomLevels();
            if (newLevels > currentLevels_)
            {
                for (int level = currentLevels_; level < newLevels; ++level)
                {
                    update[level] = head_;
                }
                currentLevels_ = newLevels;
            }
            current = new SkipListNode(value, newLevels);
            for (int level = 0; level < newLevels; ++level)
            {
                current->forward[level] = update[level]->forward[level];
                update[level]->forward[level] = current;
            }
        }
    }

    // Delete a value from the Skip List
    void remove(int value)
    {
        SkipListNode *current = head_;
        SkipListNode *update[maxLevels_];
        for (int level = currentLevels_ - 1; level >= 0; --level)
        {
            while (current->forward[level]->value < value)
            {
                current = current->forward[level];
            }
            update[level] = current;
        }
        current = current->forward[0]; // Move to the bottom level

        if (current->value == value)
        {
            for (int level = 0; level < currentLevels_; ++level)
            {
                if (update[level]->forward[level] != current)
                {
                    break; // No more references to the node
                }
                update[level]->forward[level] = current->forward[level];
            }
            delete current;

            // Update the current levels if necessary
            while (currentLevels_ > 1 && head_->forward[currentLevels_ - 1] == tail_)
            {
                currentLevels_--;
            }
        }
    }

    // Helper function to generate random levels for a new node
    int randomLevels()
    {
        int levels = 1;
        while (rand() % 2 == 0 && levels < maxLevels_)
        {
            levels++;
        }
        return levels;
    }

private:
    SkipListNode *head_;
    SkipListNode *tail_;
    int maxLevels_;
    int currentLevels_;
};

int main()
{
    SkipList skipList(16); // Max levels in the Skip List

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(9);
    skipList.insert(12);

    cout << "Search 6: " << skipList.search(6) << endl; // Output: 1 (true)
    cout << "Search 7: " << skipList.search(7) << endl; // Output: 0 (false)

    skipList.remove(6);
    cout << "Search 6 after removal: " << skipList.search(6) << endl; // Output: 0 (false)

    return 0;
}
