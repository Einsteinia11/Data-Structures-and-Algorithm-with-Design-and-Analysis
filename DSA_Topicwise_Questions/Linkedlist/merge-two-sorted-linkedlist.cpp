/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
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
};

class Solution
{
public:
    // Function to merge two sorted linked lists
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        // Check for empty lists
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        // Compare the values of the current nodes
        if (list1->val < list2->val)
        {
            // If list1's value is smaller, merge list1->next with list2 and update list1->next
            list1->next = merge(list1->next, list2);
            return list1;
        }
        else
        {
            // If list2's value is smaller or equal, merge list1 with list2->next and update list2->next
            list2->next = merge(list1, list2->next);
            return list2;
        }
    }

    // Function to merge two lists
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        return merge(list1, list2);
    }
};

// function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    // Create two sorted linked lists for testing
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    ListNode *mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

/*
Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/