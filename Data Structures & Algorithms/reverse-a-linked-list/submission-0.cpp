/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // prev = previous node
        ListNode* prev = nullptr;

        // curr = current node
        ListNode* curr = head;

        while (curr != nullptr) {

            // Save the next node before changing the pointer
            ListNode* next = curr->next;

            // Reverse the current node's pointer
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = next;
        }

        // prev is now the new head
        return prev;
    }
};

/*
Time Complexity: O(n)
    - We visit every node exactly once.

Space Complexity: O(1)
    - Only three pointers are used.
*/