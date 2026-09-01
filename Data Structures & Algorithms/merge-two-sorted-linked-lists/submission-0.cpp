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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node helps us easily build the merged list
        ListNode* dummy = new ListNode(-1);

        // tail always points to the last node
        // in the merged list
        ListNode* tail = dummy;

        // Compare nodes from both lists
        while (list1 && list2) {

            if (list1->val <= list2->val) {

                // Attach list1 node to merged list
                tail->next = list1;

                // Move list1 forward
                list1 = list1->next;

            } else {

                // Attach list2 node to merged list
                tail->next = list2;

                // Move list2 forward
                list2 = list2->next;
            }

            // Move tail to the newly added node
            tail = tail->next;
        }

        // Attach the remaining nodes
        // from whichever list is not empty
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the actual head of merged list
        // (skip the dummy node)
        return dummy->next;

        /*
        Time Complexity: O(N + M)
        - Every node from both lists is visited once.

        Space Complexity: O(1)
        - Only dummy, tail and existing list pointers are used.
        - No new nodes are created for the merged list.
        */
    }
};
