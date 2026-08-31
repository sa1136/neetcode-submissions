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

    // Comparator to make priority_queue a MIN HEAP
    // By default, priority_queue is a MAX HEAP.
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        /*
            INTUITION:
            We have K sorted linked lists.

            Example:
            L1: 1 → 2 → 4
            L2: 1 → 3 → 5
            L3: 3 → 6

            We put the first node of every list into a MIN HEAP.

            Heap:
            [1, 1, 3]

            The smallest node is always at the top.

            Steps:
            1. Take the smallest node.
            2. Add it to our answer.
            3. Move to its next node.
            4. Put that next node into the heap.
            5. Repeat.

            MEMORY TRICK:
            POP smallest → ADD to answer → PUSH its next
        */

        // Min heap containing ListNode pointers
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;


        // Put the first node of every non-empty list into the heap
        for (ListNode* head : lists) {

            if (head != nullptr) {
                pq.push(head);
            }
        }


        // Dummy node makes it easier to build the result list
        ListNode* dummy = new ListNode(0);

        // tail always points to the last node in our result
        ListNode* tail = dummy;


        // Continue until there are no nodes left in the heap
        while (!pq.empty()) {

            // Get the smallest node
            ListNode* smallest = pq.top();
            pq.pop();


            // Add the smallest node to our result
            tail->next = smallest;
            tail = tail->next;


            // Push the next node from the same list
            // because it is now the next possible candidate
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }


        // dummy->next is the actual head of the merged list
        return dummy->next;
    }
};


/*
    TIME COMPLEXITY: O(N log K)

    N = total number of nodes across all K lists
    K = number of linked lists

    Every node is:
        - pushed into the heap once  → O(log K)
        - popped from the heap once   → O(log K)

    There are N total nodes.

    Therefore:
        O(N log K)


    SPACE COMPLEXITY: O(K)

    At any time, the heap contains at most
    one node from each of the K lists.

    Therefore:
        O(K)

    The output list does NOT count as extra space
    because we are reusing the existing nodes.
*/