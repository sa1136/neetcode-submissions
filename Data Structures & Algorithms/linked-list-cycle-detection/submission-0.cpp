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
    bool hasCycle(ListNode *head) {

        // Slow moves 1 step at a time
        ListNode* slow = head;

        // Fast moves 2 steps at a time
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;           // Move slow by 1
            fast = fast->next->next;     // Move fast by 2

            // If slow and fast meet,
            // there is a cycle in the linked list
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches NULL, there is no cycle
        return false;

        /*
        Time Complexity: O(N)
        - In the worst case, slow and fast may traverse
          the linked list/cycle before meeting.
        - Therefore, O(N).

        Space Complexity: O(1)
        - We only use two pointers: slow and fast.
        - No extra data structure is used.
        - Therefore, O(1).
        */
    }
};
