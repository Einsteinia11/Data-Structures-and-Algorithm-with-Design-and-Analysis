/*
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list. Examples are below the code:-
*/

#include <iostream>
#include <cstddef> // Include the necessary header for NULL

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *nextNode;        // Pointer to the next node in the original list
        ListNode *prevNode = NULL; // Pointer to the previous node in the reversed list

        while (head)
        {
            nextNode = head->next; // Store the next node of the original list

            head->next = prevNode; // Reverse the next pointer of the current node

            prevNode = head; // Move the prevNode pointer to the current node
            head = nextNode; // Move the head pointer to the next node
        }

        return prevNode; // Return the new head of the reversed list
    }
};

int main()
{
    // Create a linked list for testing
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    std::cout << "Original List: ";
    ListNode *current = head;
    while (current)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode *reversedHead = solution.reverseList(head);

    std::cout << "Reversed List: ";
    current = reversedHead;
    while (current)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}

/*
Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:

Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].

*/