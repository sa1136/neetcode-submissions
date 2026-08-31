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

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        /*
            INTUITION:
            
            We have K sorted linked lists.

            Example:
            L1: 1 → 2 → 4
            L2: 1 → 3 → 5
            L3: 3 → 6

            We put the first node of every list
            into a MIN HEAP.

            Heap:
            [1, 1, 3]

            The smallest value is always at the top.

            We repeatedly:
            
            1. POP the smallest node
            2. ADD it to our answer
            3. PUSH its next node into the heap

            MEMORY TRICK:
            POP → ADD → PUSH next
        */


        // Min heap storing:
        // {node value, node pointer}
        //
        // greater<> makes it a MIN HEAP
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;


        // Put the first node of every non-empty list
        // into the heap
        for (ListNode* head : lists) {

            if (head != nullptr) {
                pq.push({head->val, head});
            }
        }


        // Dummy node helps us build the result list
        ListNode* dummy = new ListNode(0);

        // tail points to the last node in our result
        ListNode* tail = dummy;


        // Process all nodes
        while (!pq.empty()) {

            // Get the smallest node
            // .second gives us the ListNode*
            ListNode* smallest = pq.top().second;

            // Remove it from the heap
            pq.pop();


            // Add smallest node to our answer
            tail->next = smallest;
            tail = tail->next;


            // If there is another node in the same list,
            // put it into the heap
            if (smallest->next != nullptr) {

                pq.push({
                    smallest->next->val,
                    smallest->next
                });
            }
        }


        // Return the actual head
        // (dummy itself is not part of the answer)
        return dummy->next;
    }
};


/*
    TIME COMPLEXITY: O(N log K)

    N = total number of nodes
    K = number of linked lists

    Every node is:
        - pushed into the heap once → O(log K)
        - popped from the heap once  → O(log K)

    There are N nodes.

    Therefore:

        O(N log K)


    SPACE COMPLEXITY: O(K)

    The heap contains at most one node
    from each of the K lists.

    Therefore:

        O(K)

    We are reusing the existing linked-list nodes,
    so the output list does not count as extra space.
*/