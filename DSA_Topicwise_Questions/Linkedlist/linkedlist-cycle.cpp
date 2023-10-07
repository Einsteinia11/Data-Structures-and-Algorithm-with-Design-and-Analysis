/*
141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false. Examples are below the code:-
*/
#include <iostream>
#include <cstddef> // Include the necessary header for NULL

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // Check if the linked list is empty
        if (head == NULL)
            return false;

        ListNode *fast = head; // Fast pointer moves 2 steps at a time
        ListNode *slow = head; // Slow pointer moves 1 step at a time

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next; // Move the fast pointer 2 steps
            slow = slow->next;       // Move the slow pointer 1 step

            // If there's a cycle (fast and slow pointers meet), return true
            if (fast == slow)
                return true;
        }

        // If the loop completes without finding a cycle, return false
        return false;
    }
};

int main()
{
    // Create a linked list for testing (with or without a cycle)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Uncomment the next line to create a cycle in the linked list
    // head->next->next->next->next->next = head->next;

    Solution solution;

    if (solution.hasCycle(head))
        std::cout << "The linked list has a cycle." << std::endl;
    else
        std::cout << "The linked list does not have a cycle." << std::endl;

    return 0;
}

/*
Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
*/
